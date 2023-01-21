#include "../1decimal/create_decimal.h"
#include "./binary.h"

/*
 * Функция бинарного вычитания двоичных чисел.
 *
 * A:   1 0 1 0 0 1 1 1
 * B: - 0 0 0 1 0 0 0 1
 *      ---------------
 * C: = 1 0 0 1 0 1 1 0
 */
s21_decimal s21_decimal_binary_subtraction(s21_decimal decimal1,
                                           s21_decimal decimal2) {
  s21_decimal result;
  decimal2 = s21_decimal_binary_not(decimal2);
  decimal2 = s21_decimal_binary_addition(decimal2, s21_decimal_get_one());
  result = s21_decimal_binary_addition(decimal1, decimal2);

  return result;
}
