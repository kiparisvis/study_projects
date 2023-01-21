#include <limits.h>

#include "../1decimal/create_decimal.h"
#include "./convertors.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  s21_convertation_code_error code = S21_CONVERTATION_OK;
  if (!dst) {
    // Если указатель на decimal является NULL
    code = S21_CONVERTATION_ERROR;
  } else {
    *dst = s21_decimal_get_zero();
    int sign;
    if (src < 0) {
      sign = S21_NEGATIVE;
      if (src != INT_MIN) {
        // У INT_MIN не надо менять знак:
        // negation of -2147483648 cannot be represented in type 'int';
        src = -src;
      }
    } else {
      sign = S21_POSITIVE;
    }
    dst->bits[0] = src;
    // Определяем знак результата, исходя из знака числа src (типа int)
    s21_decimal_set_sign(dst, sign);
  }
  return code;
}
