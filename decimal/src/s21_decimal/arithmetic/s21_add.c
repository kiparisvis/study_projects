#include <stddef.h>
#include <stdio.h>

#include "../../tests/_helpers/_debug.h"
#include "../1decimal/create_decimal.h"
#include "../decimal_overflow/s21_decimal_overflow.h"
#include "./arithmetic.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (!s21_is_correct_decimal(value_1) || !s21_is_correct_decimal(value_2) ||
      result == NULL) {
    return -1;  // обработка ошибок
  }
  s21_arithmetic_result code = S21_ARITHMETIC_OK;
  s21_decimal_overflow s21_decimal_overflow1 =
      decimal_to_s21_decimal_overflow(value_1);
  s21_decimal_overflow s21_decimal_overflow2 =
      decimal_to_s21_decimal_overflow(value_2);
  s21_decimal_overflow s21_decimal_overflow1_abs =
      s21_decimal_overflow_set_sign(s21_decimal_overflow1, 0);
  s21_decimal_overflow s21_decimal_overflow2_abs =
      s21_decimal_overflow_set_sign(s21_decimal_overflow2, 0);
  int value_1_sign = s21_decimal_get_sign(value_1);
  int value_2_sign = s21_decimal_get_sign(value_2);
  s21_decimal_overflow res =
      s21_decimal_overflow_add(s21_decimal_overflow1, s21_decimal_overflow2);
  int res_sign = s21_decimal_overflow_get_sign(res);
  // Оценка результата
  // Если знаки аргументов одинаковые
  // но не совпадают со знаком результата
  if (value_1_sign == value_2_sign && !s21_decimal_overflow_is_zero(res)) {
    if ((!value_1_sign && res_sign) || (value_1_sign && !res_sign)) {
      if (value_1_sign)
        code = S21_ARITHMETIC_SMALL;
      else
        code = S21_ARITHMETIC_BIG;
    }
  } else if (value_1_sign) {  // Если первый аргумент отрицательный
    if (s21_decimal_overflow_compare(
            s21_decimal_overflow2_abs,
            s21_decimal_overflow1_abs)) {  // и по модулю меньше второго
      // знак результата должен быть положительный
      if (res_sign) {
        // знак результата отрицательный, неудача
      }
    } else if (s21_decimal_overflow_compare(
                   s21_decimal_overflow1_abs,
                   s21_decimal_overflow2_abs)) {  // если же больше
      // знак результата должен быть отрицательный
      if (!res_sign) {
        // знак результата положительный, неудача
      }
    } else {
      // в этом случае результат должен быть 0
    }
  } else {  // Если второй аргумент отрицательный
    if (s21_decimal_overflow_compare(
            s21_decimal_overflow1_abs,
            s21_decimal_overflow2_abs)) {  // и по модулю меньше первого
      // знак результата должен быть положительный
      if (res_sign) {
        // знак результата отрицательный, неудача
      }
    } else if (s21_decimal_overflow_compare(
                   s21_decimal_overflow2_abs,
                   s21_decimal_overflow1_abs)) {  // если же больше
      // знак результата должен быть отрицательный
      if (!res_sign) {
        // знак результата положительный, неудача
      }
    }
  }
  // Если код результата остался ОК, то округлить до decimal
  if (code == S21_ARITHMETIC_OK && !s21_decimal_overflow_is_zero(res)) {
    int sign = s21_decimal_overflow_get_sign(res);
    if (sign) {
      int exp = s21_decimal_overflow_get_exp(res);
      res = s21_decimal_overflow_to_twos_complement(res);
      s21_decimal_overflow_set_exp(&res, exp);
    }
    code = s21_decimal_overflow_round_to_decimal(res, result);
  } else if (s21_decimal_overflow_is_zero(res)) {
    *result = s21_decimal_get_zero();
  }
  return code;
}
