#include "s21_decimal_overflow.h"

/*
 * Сложение двух чисел типа s21_decimal_overflow
 */
s21_decimal_overflow s21_decimal_overflow_add(s21_decimal_overflow first,
                                              s21_decimal_overflow second) {
  s21_decimal_overflow_balance_exp(&first, &second);
  return s21_decimal_overflow_add_big_int(first, second);
}
