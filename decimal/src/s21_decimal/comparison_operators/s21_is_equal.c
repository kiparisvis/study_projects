#include "../decimal_overflow/s21_decimal_overflow.h"
#include "./comparison_operators.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  s21_comparison_result code = S21_COMPARISON_FALSE;
  if (value_1.bits[0] == value_2.bits[0] && value_1.bits[0] == 0 &&
      value_1.bits[1] == value_2.bits[1] && value_1.bits[1] == 0 &&
      value_1.bits[2] == value_2.bits[2] && value_1.bits[2] == 0) {
    code = S21_COMPARISON_TRUE;
  }
  s21_decimal_overflow value_1_big = decimal_to_s21_decimal_overflow(value_1);
  s21_decimal_overflow value_2_big = decimal_to_s21_decimal_overflow(value_2);
  s21_decimal_overflow_balance_exp(&value_1_big, &value_2_big);
  value_1 = s21_decimal_overflow_to_decimal(value_1_big);
  value_2 = s21_decimal_overflow_to_decimal(value_2_big);
  if (value_1.bits[0] == value_2.bits[0] &&
      value_1.bits[1] == value_2.bits[1] &&
      value_1.bits[2] == value_2.bits[2] &&
      value_1.bits[3] == value_2.bits[3]) {
    code = S21_COMPARISON_TRUE;
  }
  return code;
}
