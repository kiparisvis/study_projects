#include <stdlib.h>

#include "../1decimal/create_decimal.h"
#include "../binary/binary.h"
#include "another_function.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  s21_another_functions_code_error code = S21_ANOTHER_FUNCTION_OK;
  if (!result) {
    // Если указатель на decimal является NULL
    code = S21_ANOTHER_FUNCTION_ERROR;
  } else if (!s21_is_correct_decimal(value)) {
    // Проверяем, что value является корректными decimal
    code = S21_ANOTHER_FUNCTION_ERROR;
    *result = s21_decimal_get_inf();
  } else {
    // В остальных случаях производим расчет
    *result = s21_decimal_get_zero();
    int power = s21_decimal_get_power(value);
    s21_decimal tmp = value;
    s21_decimal_null_service_bits(&tmp);
    tmp =
        s21_decimal_binary_division(tmp, s21_decimal_get_ten_pow(power), NULL);
    *result = tmp;
    if (s21_decimal_get_sign(value) == S21_NEGATIVE) {
      s21_decimal_set_sign(result, S21_NEGATIVE);
    }
  }
  return code;
}
