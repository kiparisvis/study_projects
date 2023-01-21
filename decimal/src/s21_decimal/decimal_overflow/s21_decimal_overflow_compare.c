#include <stdio.h>

#include "s21_decimal_overflow.h"

/*
 * Функция сравнения мантисс
 */
int s21_decimal_overflow_compare(s21_decimal_overflow first,
                                 s21_decimal_overflow second) {
  s21_decimal_overflow_comparison_result result =
      S21_DECIMAL_OVERFLOW_COMPARISON_EQUAL;
  int first_sign = s21_decimal_overflow_get_sign(first);
  int second_sign = s21_decimal_overflow_get_sign(second);
  if (s21_decimal_overflow_is_zero(first) &&
      s21_decimal_overflow_is_zero(second)) {
  } else if (first_sign && !second_sign) {
    result = S21_DECIMAL_OVERFLOW_COMPARISON_SECOND_GREATER;
  } else if (!first_sign && second_sign) {
    result = S21_DECIMAL_OVERFLOW_COMPARISON_FIRST_GREATER;
  } else {
    int first_bit = s21_decimal_overflow_get_not_zero_bit(first);
    int second_bit = s21_decimal_overflow_get_not_zero_bit(second);
    if (first_bit > second_bit) {
      result = S21_DECIMAL_OVERFLOW_COMPARISON_FIRST_GREATER;
    } else if (first_bit < second_bit) {
      result = S21_DECIMAL_OVERFLOW_COMPARISON_SECOND_GREATER;
    } else {
      for (int i = first_bit; i >= 0; i--) {
        if (s21_decimal_overflow_is_set_bit(first, i) ==
            s21_decimal_overflow_is_set_bit(second, i)) {
          continue;
        } else if (s21_decimal_overflow_is_set_bit(first, i)) {
          result = S21_DECIMAL_OVERFLOW_COMPARISON_FIRST_GREATER;
        } else {
          result = S21_DECIMAL_OVERFLOW_COMPARISON_SECOND_GREATER;
        }
        break;
      }
    }
    if (result != S21_DECIMAL_OVERFLOW_COMPARISON_EQUAL) {
      if (first_sign) {
        if (result == S21_DECIMAL_OVERFLOW_COMPARISON_FIRST_GREATER) {
          result = S21_DECIMAL_OVERFLOW_COMPARISON_SECOND_GREATER;
        } else {
          result = S21_DECIMAL_OVERFLOW_COMPARISON_FIRST_GREATER;
        }
      }
    }
  }
  return result;
}
