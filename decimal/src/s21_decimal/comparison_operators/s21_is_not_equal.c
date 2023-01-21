#include "../../s21_decimal.h"

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  s21_comparison_result code = S21_COMPARISON_FALSE;

  if (!s21_is_equal(value_1, value_2)) {
    code = S21_COMPARISON_TRUE;
  }
  return code;
}
