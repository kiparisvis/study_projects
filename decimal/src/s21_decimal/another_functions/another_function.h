#ifndef SRC_S21_1DECIMAL_ANOTHER_FUNCTIONS_ANOTHER_FUNCTION_H_
#define SRC_S21_1DECIMAL_ANOTHER_FUNCTIONS_ANOTHER_FUNCTION_H_

#include "../1decimal/create_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

typedef enum s21_another_functions_code_error {
  S21_ANOTHER_FUNCTION_OK = 0,
  S21_ANOTHER_FUNCTION_ERROR = 1
} s21_another_functions_code_error;

typedef enum s21_even_or_odd_code_result {
  S21_EVEN = 0,
  S21_ODD = 1
} s21_even_or_odd_code_result;

#endif  //  SRC_S21_1DECIMAL_ANOTHER_FUNCTIONS_ANOTHER_FUNCTION_H_
