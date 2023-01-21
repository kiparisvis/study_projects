#include "../1decimal/create_decimal.h"
#include "../arithmetic/arithmetic.h"
#include "../comparison_operators/comparison_operators.h"
#include "another_function.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  s21_another_functions_code_error code = S21_ANOTHER_FUNCTION_OK;

  // Если указатель на decimal является NULL.
  if (!result) {
    code = S21_ANOTHER_FUNCTION_ERROR;
    // Проверяем, что value является корректным decimal.
  } else if (!s21_is_correct_decimal(value)) {
    code = S21_ANOTHER_FUNCTION_ERROR;
    *result = s21_decimal_get_zero();
    // В остальных случаях производим округление.
  } else {
    s21_decimal one = s21_decimal_get_one();
    s21_decimal five = s21_decimal_get_five();
    s21_decimal remainder = {0};
    int value_sign = s21_decimal_get_sign(value);

    *result = s21_decimal_get_zero();
    if (value_sign) {
      s21_negate(value, &value);
    }

    s21_truncate(value, result);
    s21_mod(value, one, &remainder);
    s21_decimal_set_power(&five, 1);

    if (s21_is_greater(remainder, five)) {
      s21_add(*result, one, result);
    } else if (s21_is_equal(five, remainder)) {
      if (s21_even_or_odd(*result) == S21_ODD) {
        s21_add(*result, one, result);
      }
    }
    if (value_sign) {
      s21_negate(*result, result);
    }
  }
  return code;
}
