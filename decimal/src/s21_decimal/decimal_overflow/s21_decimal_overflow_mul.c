#include "../arithmetic/arithmetic.h"
#include "s21_decimal_overflow.h"

/*
 * Функция умножения чисел типа s21_decimal_overflow
 */
int s21_decimal_overflow_mul(s21_decimal_overflow first,
                             s21_decimal_overflow second,
                             s21_decimal_overflow *result) {
  s21_arithmetic_result code = S21_ARITHMETIC_OK;
  code = s21_decimal_overflow_mul_big_int(first, second, result);
  return code;
}
