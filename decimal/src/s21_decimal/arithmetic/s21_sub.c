#include <stddef.h>

#include "../1decimal/create_decimal.h"
#include "../comparison_operators/comparison_operators.h"
#include "./arithmetic.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_arithmetic_result code = S21_ARITHMETIC_OK;
  if (!s21_is_correct_decimal(value_1) || !s21_is_correct_decimal(value_2) ||
      result == NULL) {
    return -1;  // обработка ошибок
  } else if (s21_is_equal(value_1, s21_decimal_get_zero())) {
    if (s21_decimal_get_sign(value_2)) {
      s21_decimal_set_sign(&value_2, 0);
    } else {
      s21_decimal_set_sign(&value_2, 1);
    }
    *result = value_2;
  } else if (s21_is_equal(value_2, s21_decimal_get_zero())) {
    *result = value_1;
  } else {
    if (s21_decimal_get_sign(value_2)) {
      s21_decimal_set_sign(&value_2, 0);
    } else {
      s21_decimal_set_sign(&value_2, 1);
    }
    code = s21_add(value_1, value_2, result);
  }
  return code;
}
