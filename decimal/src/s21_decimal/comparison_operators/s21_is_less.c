#include "./comparison_operators.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  s21_comparison_result code = S21_COMPARISON_FALSE;
  if (!s21_is_greater(value_1, value_2) && !s21_is_equal(value_1, value_2)) {
    code = S21_COMPARISON_TRUE;
  }
  return code;
}
