#include <stddef.h>

#include "../1decimal/create_decimal.h"
#include "../comparison_operators/comparison_operators.h"
#include "../decimal_overflow/s21_decimal_overflow.h"
#include "arithmetic.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_arithmetic_result code = S21_ARITHMETIC_OK;
  if (!s21_is_correct_decimal(value_1) || !s21_is_correct_decimal(value_2) ||
      result == NULL) {
    return -1;  // обработка ошибок
  } else if (s21_is_equal(value_1, s21_decimal_get_zero()) ||
             s21_is_equal(value_2, s21_decimal_get_zero())) {
    *result = s21_decimal_get_zero();
  } else {
    s21_decimal_overflow val_1_big = decimal_to_s21_decimal_overflow(value_1);
    s21_decimal_overflow val_2_big = decimal_to_s21_decimal_overflow(value_2);
    s21_decimal_overflow res = s21_decimal_overflow_get_zero();
    code = s21_decimal_overflow_mul(val_1_big, val_2_big, &res);
    if (code == S21_ARITHMETIC_OK) {
      code = s21_decimal_overflow_round_to_decimal(res, result);
    }
  }
  return code;
}
