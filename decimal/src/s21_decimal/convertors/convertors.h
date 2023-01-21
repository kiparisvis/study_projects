#ifndef SRC_S21_1DECIMAL_CONVERTORS_CONVERTORS_H_
#define SRC_S21_1DECIMAL_CONVERTORS_CONVERTORS_H_

#include <stdlib.h>

#include "../../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

/*
 * Return value - code error:
 * 0 - OK
 * 1 - convertation error
 */
typedef enum s21_convertation_code_error {
  S21_CONVERTATION_OK = 0,
  S21_CONVERTATION_ERROR = 1
} s21_convertation_code_error;

#define MAX_FLOAT_TO_CONVERT 79228157791897854723898736640.0f
#define MIN_FLOAT_TO_CONVERT \
  0.00000000000000000000000000010000000031710768509710513471352647538147514756461109f

s21_decimal s21_decimal_get_from_char(char c);
int s21_get_float_exp_from_string(char *str);
s21_decimal s21_float_string_to_decimal(char *str);

#endif  //  SRC_S21_1DECIMAL_CONVERTORS_CONVERTORS_H_
