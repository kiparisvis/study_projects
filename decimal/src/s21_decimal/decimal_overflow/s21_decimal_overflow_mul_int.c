#include <stdio.h>

#include "../../tests/_helpers/_debug.h"
#include "../arithmetic/arithmetic.h"
#include "s21_decimal_overflow.h"

/*
 * Целочисленное умножение мантисс (соответственно без учёта экспоненты)
 */
int s21_decimal_overflow_mul_big_int(s21_decimal_overflow first,
                                     s21_decimal_overflow second,
                                     s21_decimal_overflow *result) {
  s21_arithmetic_result code = S21_ARITHMETIC_OK;
  int mul_sign = s21_decimal_overflow_get_sign(first) ^
                 s21_decimal_overflow_get_sign(second);
  s21_decimal_overflow multipliable = s21_decimal_overflow_get_zero();
  s21_decimal_overflow multiplier = s21_decimal_overflow_get_zero();
  s21_decimal_overflow_set_exp(&multiplier, 0);
  s21_decimal_overflow_set_exp(&multipliable, 0);
  if (s21_decimal_overflow_get_not_zero_bit(first) >
      s21_decimal_overflow_get_not_zero_bit(second)) {
    multipliable = first;
    multiplier = second;
  } else {
    multipliable = second;
    multiplier = first;
  }
  multipliable = s21_decimal_overflow_set_sign(multipliable, 0);
  multiplier = s21_decimal_overflow_set_sign(multiplier, 0);
  s21_decimal_overflow sum = s21_decimal_overflow_get_zero();
  int count = s21_decimal_overflow_get_not_zero_bit(multiplier);
  for (register int i = 0; i <= count; i++) {
    if (s21_decimal_overflow_is_set_bit(multiplier, i)) {
      sum = s21_decimal_overflow_add_big_int(
          sum, s21_decimal_overflow_shift_left(multipliable, i));
    }
  }
  // Если у sum появился знак, значит произошло переполнение.
  if (s21_decimal_overflow_get_sign(sum)) {
    if (mul_sign) {
      code = S21_ARITHMETIC_SMALL;
    } else {
      code = S21_ARITHMETIC_BIG;
    }
  } else {
    sum = s21_decimal_overflow_set_sign(sum, mul_sign);
  }
  s21_decimal_overflow_set_exp(&sum, s21_decimal_overflow_get_exp(first) +
                                         s21_decimal_overflow_get_exp(second));
  *result = sum;
  return code;
}
