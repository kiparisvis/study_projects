#include <stdio.h>

#include "../../tests/_helpers/_debug.h"
#include "../1decimal/create_decimal.h"
#include "../arithmetic/arithmetic.h"
#include "../binary/binary.h"
#include "s21_decimal_overflow.h"

/*
 * Функция по возможности округляет s21_decimal_overflow до decimal.
 */
int s21_decimal_overflow_round_to_decimal(s21_decimal_overflow in,
                                          s21_decimal *res) {
  s21_arithmetic_result code = S21_ARITHMETIC_OK;
  // При умножении экспонента может оказаться выше 28.
  // Соответственно надо понизить
  if (s21_decimal_overflow_get_exp(in) > 28) {
    int to_low = s21_decimal_overflow_get_exp(in) - 28;
    int sign = s21_decimal_overflow_get_sign(in);
    s21_decimal_overflow remainder = s21_decimal_overflow_get_zero();
    s21_decimal_overflow temp_res1 = s21_decimal_overflow_get_zero();
    code = s21_decimal_overflow_div_big_int(
        s21_decimal_overflow_set_sign(in, 0),
        decimal_to_s21_decimal_overflow(s21_decimal_get_ten_pow(to_low)),
        &temp_res1, &remainder);
    if (code == S21_ARITHMETIC_OK && !s21_decimal_overflow_is_zero(remainder)) {
      s21_decimal_overflow temp_res2 = s21_decimal_overflow_get_zero();
      code = s21_decimal_overflow_div_big_int(
          s21_decimal_overflow_set_sign(in, 0),
          decimal_to_s21_decimal_overflow(s21_decimal_get_ten_pow(to_low - 1)),
          &temp_res2, &remainder);
      if (code == S21_ARITHMETIC_OK) {
        // Для вычисления округляемой цифры придется домножить первый результат
        // на 10 и вычесть это из второго результата
        s21_decimal_overflow shifted_one =
            s21_decimal_overflow_shift_left(temp_res1, 1);
        s21_decimal_overflow shifted_three =
            s21_decimal_overflow_shift_left(temp_res1, 3);
        s21_decimal_overflow multied =
            s21_decimal_overflow_add_big_int(shifted_one, shifted_three);
        s21_decimal_overflow digit = s21_decimal_overflow_add_big_int(
            temp_res2, s21_decimal_overflow_set_sign(multied, 1));
        if (digit.parts[0] == 5 &&
            (!s21_decimal_overflow_is_zero(remainder) ||
             (s21_decimal_overflow_is_zero(remainder) &&
              s21_decimal_overflow_is_set_bit(temp_res1, 0)))) {
          temp_res1 = s21_decimal_overflow_incr(temp_res1);
        } else if (digit.parts[0] > 5) {
          temp_res1 = s21_decimal_overflow_incr(temp_res1);
        } else if (s21_decimal_overflow_is_zero(temp_res1)) {
          code = S21_ARITHMETIC_SMALL;
        }
        s21_decimal_overflow_set_exp(&temp_res1, 28);
        temp_res1 = s21_decimal_overflow_set_sign(temp_res1, sign);
        in = temp_res1;
      }
    }
  }
  // Выясним, на сколько битов надо округлить
  int bits_to_round = s21_decimal_overflow_get_not_zero_bit(in) - 95;
  if (bits_to_round > 0 && code == S21_ARITHMETIC_OK) {
    // Если поделить это количество на 3 и отбросить остаток,
    // то получим верхний уровень округления в десятичных знаках.
    // Но сначала можно проверить нижний - возможно впишется в разрядную сетку
    s21_decimal_overflow divisor;
    int ten_exp = (bits_to_round - 1) / 3 - 2;
    if (ten_exp < 1) {
      ten_exp = 1;
    } else if (ten_exp > 28) {
      ten_exp = 28;
    }
    divisor = decimal_to_s21_decimal_overflow(all_ten_pows[ten_exp]);
    // Используем деление нацело с остатком
    s21_decimal_overflow result = s21_decimal_overflow_get_zero();
    s21_decimal_overflow remainder = s21_decimal_overflow_get_zero();
    // Убираем экспоненту
    s21_decimal_overflow in_wo_exp = in;
    s21_decimal_overflow_set_exp(&in_wo_exp, 0);
    s21_decimal_overflow_div_big_int(in_wo_exp, divisor, &result, &remainder);
    while ((int)s21_decimal_overflow_get_not_zero_bit(result) - 95 > 0) {
      ten_exp++;
      if (ten_exp > 28) {
        break;
      }
      divisor = decimal_to_s21_decimal_overflow(all_ten_pows[ten_exp]);
      s21_decimal_overflow_div_big_int(in_wo_exp, divisor, &result, &remainder);
    }

    if (s21_decimal_overflow_get_exp(in) < ten_exp) {
      // Если экспонента числа меньше, чем надо округлить,
      // то получилось очень большое число,
      // результат 1
      if (s21_decimal_overflow_get_sign(in)) {
        code = S21_ARITHMETIC_SMALL;
      } else {
        code = S21_ARITHMETIC_BIG;
      }
    } else if (s21_decimal_overflow_get_exp(in) - ten_exp > 28) {
      // Если после деления экспонента числа осталась более 28,
      // то получилось очень маленькое число, результат 2
      code = S21_ARITHMETIC_SMALL;
    } else {
      // Теперь можно округлить
      s21_decimal_overflow first = s21_decimal_overflow_get_zero();
      s21_decimal_overflow tmp_remainder = s21_decimal_overflow_get_zero();
      divisor = decimal_to_s21_decimal_overflow(all_ten_pows[ten_exp - 1]);
      s21_decimal_overflow_div_big_int(remainder, divisor, &first,
                                       &tmp_remainder);
      if (first.parts[0] > 5 ||
          (first.parts[0] == 5 &&
           (!s21_decimal_overflow_is_zero(tmp_remainder) ||
            s21_decimal_overflow_is_set_bit(result, 0)))) {
        result = s21_decimal_overflow_incr(result);
        // Крайний случай: переполнение decimal при инкременте
        if (s21_decimal_overflow_is_set_bit(result, 96)) {
          if (s21_decimal_overflow_get_sign(in)) {
            code = S21_ARITHMETIC_SMALL;
          } else {
            code = S21_ARITHMETIC_BIG;
          }
        }
      }
      // Не забыть проставить экспоненту
      s21_decimal_overflow_set_exp(&result,
                                   s21_decimal_overflow_get_exp(in) - ten_exp);
    }
    // Конвертировать в decimal
    if (code == S21_ARITHMETIC_OK) {
      *res = s21_decimal_overflow_to_decimal(result);
    }
  } else {
    *res = s21_decimal_overflow_to_decimal(in);
  }
  return code;
}
