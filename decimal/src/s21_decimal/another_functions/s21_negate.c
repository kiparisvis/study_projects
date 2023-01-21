#include "../1decimal/create_decimal.h"
#include "another_function.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  s21_another_functions_code_error code = S21_ANOTHER_FUNCTION_OK;

  if (!result) {
    code = S21_ANOTHER_FUNCTION_ERROR;
  } else if (!s21_is_correct_decimal(value)) {
    code = S21_ANOTHER_FUNCTION_ERROR;
    *result = s21_decimal_get_zero();
  } else {
    *result = value;
    s21_decimal_set_sign(result, !s21_decimal_get_sign(value));
  }
  return code;
}
