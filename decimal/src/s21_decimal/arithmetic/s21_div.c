#include <stdio.h>
#include <stdlib.h>

#include "../1decimal/create_decimal.h"
#include "../decimal_overflow/s21_decimal_overflow.h"
#include "./arithmetic.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_arithmetic_result code = S21_ARITHMETIC_OK;
  if (!s21_is_correct_decimal(value_1) || !s21_is_correct_decimal(value_2) ||
      result == NULL) {
    return -1;  // обработка ошибок
  } else if (s21_decimal_mantissa_is_zero(value_2)) {
    code = S21_ARITHMETIC_ZERO_DIV;
  } else if (s21_decimal_mantissa_is_zero(value_1)) {
    *result = s21_decimal_get_zero();
  } else {
    *result = s21_decimal_get_zero();
    s21_decimal_overflow val_1_big = decimal_to_s21_decimal_overflow(value_1);
    s21_decimal_overflow val_2_big = decimal_to_s21_decimal_overflow(value_2);
    s21_decimal_overflow res;
    code = s21_decimal_overflow_div(val_1_big, val_2_big, &res);
    if (code == S21_ARITHMETIC_OK) {
      if (s21_decimal_get_sign(value_1) != s21_decimal_get_sign(value_2)) {
        s21_decimal_overflow_set_sign(res, 1);
      }
      *result = s21_decimal_overflow_to_decimal(res);
    }
  }
  return code;
}
