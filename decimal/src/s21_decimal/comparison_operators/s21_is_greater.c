#include "../1decimal/create_decimal.h"
#include "../binary/binary.h"
#include "../decimal_overflow/s21_decimal_overflow.h"
#include "./comparison_operators.h"

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  s21_comparison_result code = S21_COMPARISON_FALSE;
  s21_decimal_overflow s21_decimal_overflow_1 =
      decimal_to_s21_decimal_overflow(value_1);
  s21_decimal_overflow s21_decimal_overflow_2 =
      decimal_to_s21_decimal_overflow(value_2);

  s21_decimal_overflow_balance_exp(&s21_decimal_overflow_1,
                                   &s21_decimal_overflow_2);
  if (s21_decimal_overflow_compare(s21_decimal_overflow_1,
                                   s21_decimal_overflow_2) ==
      S21_DECIMAL_OVERFLOW_COMPARISON_FIRST_GREATER) {
    code = S21_COMPARISON_TRUE;
  }
  return code;
}
