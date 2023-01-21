#include <stdio.h>

#include "../../tests/_helpers/_debug.h"
#include "../arithmetic/arithmetic.h"
#include "s21_decimal_overflow.h"

/*
 * Функция деления чисел формата s21_decimal_overflow
 */
int s21_decimal_overflow_div(s21_decimal_overflow dividend,
                             s21_decimal_overflow divisor,
                             s21_decimal_overflow *result) {
  s21_arithmetic_result code = S21_ARITHMETIC_OK;

  // Сначала получаем целую часть
  // Знак результата уже учтён
  *result = s21_decimal_overflow_get_zero();
  s21_decimal_overflow remainder = s21_decimal_overflow_get_zero();
  s21_decimal_overflow_div_big_int(dividend, divisor, result, &remainder);
  int sign = s21_decimal_overflow_get_sign(*result);

  int over = 0;
  int over_in_sum = 0;
  int break_on_exp = 0;
  int temp_exp = s21_decimal_overflow_get_exp(dividend) -
                 s21_decimal_overflow_get_exp(divisor);
  // Сбрасываем знак делителя
  divisor = s21_decimal_overflow_set_sign(divisor, 0);
  s21_decimal_overflow div_res = s21_decimal_overflow_get_zero();
  while (!s21_decimal_overflow_is_zero(remainder)) {
    // Домножаем остаток на 10
    s21_decimal_overflow shifted_one =
        s21_decimal_overflow_shift_left(remainder, 1);
    s21_decimal_overflow shifted_three =
        s21_decimal_overflow_shift_left(remainder, 3);
    remainder = s21_decimal_overflow_add_big_int(shifted_three, shifted_one);

    // Делим домноженный остаток на делитель
    s21_decimal_overflow_div_big_int(remainder, divisor, &div_res, &remainder);

    if (temp_exp != 28) {
      // Домножаем основной результат на 10
      shifted_one = s21_decimal_overflow_shift_left(*result, 1);
      shifted_three = s21_decimal_overflow_shift_left(*result, 3);
      s21_decimal_overflow temp_res =
          s21_decimal_overflow_add_big_int(shifted_one, shifted_three);

      // Если при этом умножении основной результат не вышел за пределы
      // s21_decimal, значит результат промежуточного деления можно прибавить к
      // этому временному результату.

      if (s21_decimal_overflow_is_zero(temp_res) ||
          s21_decimal_overflow_get_not_zero_bit(temp_res) < 96) {
        temp_res = s21_decimal_overflow_add_big_int(temp_res, div_res);
        // При этом сложении могло произойти переполнение decimal
        if (!s21_decimal_overflow_is_zero(temp_res) &&
            s21_decimal_overflow_get_not_zero_bit(temp_res) > 95) {
          over_in_sum = 1;
          break;
        }
        // Если переполнения не произошло, то сохраняем основной результат и
        // увеличиваем экспоненту
        *result = temp_res;
        temp_exp++;
      } else {
        // Произошло переполнение при умножении основного результата.
        // Отбрасываем переполненный результат, т.е. не сохраняем в result.
        // И выходим из цикла с флагом переполнения.
        over = 1;
        break;
      }
    } else {
      // При экспоненте 28 уже нет смысла домножать результат. Выходим из цикла.
      break_on_exp = 1;
      break;
    }
  }
  // Далее идёт обработка результатов. Отталкиваемся от состояния экспоненты.
  if (s21_decimal_overflow_is_zero(*result) &&
      s21_decimal_overflow_is_zero(div_res) && temp_exp == 0 && over_in_sum) {
    code = S21_ARITHMETIC_SMALL;
  } else if ((temp_exp < 0 && over) ||
             (temp_exp == 28 && s21_decimal_overflow_is_zero(*result) &&
              s21_decimal_overflow_is_zero(div_res))) {
    // Если экспонента отрицательная, а разрядная сетка при этом заполнена,
    // то имеем неисправимое переполнение
    // Либо если экспонента 28, результат и результат деления равны 0, то имеем
    // очень малое число.
    if (break_on_exp) {
      code = S21_ARITHMETIC_SMALL;
    } else if (sign && over) {
      code = S21_ARITHMETIC_SMALL;
    } else if (!sign && over) {
      code = S21_ARITHMETIC_BIG;
    }
  } else if ((over && temp_exp >= 0) || (over_in_sum) ||
             (temp_exp == 28 && break_on_exp)) {
    // Если экспонента больше либо равна 0 и есть флаг переполнения, то
    // округляем
    if (div_res.parts[0] > 5 ||
        (div_res.parts[0] == 5 &&
         (!s21_decimal_overflow_is_zero(remainder) ||
          s21_decimal_overflow_is_set_bit(*result, 0)))) {
      s21_decimal_overflow temp = s21_decimal_overflow_incr(*result);
      // Могло произойти переполнение
      if (s21_decimal_overflow_get_not_zero_bit(temp) > 95) {
        s21_decimal_overflow temp_rem = s21_decimal_overflow_get_zero();
        s21_decimal_overflow_div_big_int(
            *result, decimal_to_s21_decimal_overflow(s21_decimal_get_ten()),
            result, &temp_rem);
        *result = s21_decimal_overflow_incr(*result);
        temp_exp--;
      }
      *result = temp;
    } else if (s21_decimal_overflow_is_zero(*result) && temp_exp == 28) {
      code = S21_ARITHMETIC_SMALL;
    }
  }
  if (temp_exp < 0 && code == S21_ARITHMETIC_OK) {
    // Поднимаем экспоненту до 0
    s21_decimal_overflow raized_res = *result;
    while (temp_exp < 0 &&
           s21_decimal_overflow_get_not_zero_bit(raized_res) < 96) {
      *result = raized_res;
      s21_decimal_overflow shifted_one =
          s21_decimal_overflow_shift_left(raized_res, 1);
      s21_decimal_overflow shifted_three =
          s21_decimal_overflow_shift_left(raized_res, 3);
      raized_res = s21_decimal_overflow_add_big_int(shifted_one, shifted_three);
      temp_exp++;
    }
    if (s21_decimal_overflow_get_not_zero_bit(raized_res) < 96) {
      *result = raized_res;
    } else {
      if (sign)
        code = S21_ARITHMETIC_SMALL;
      else
        code = S21_ARITHMETIC_BIG;
    }
  }
  s21_decimal_overflow_set_exp(result, temp_exp);
  *result = s21_decimal_overflow_set_sign(*result, sign);
  if (code == S21_ARITHMETIC_OK) *result = remove_trail_zero(*result);
  return code;
}
