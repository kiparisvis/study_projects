#include "../1decimal/create_decimal.h"
#include "./binary.h"

/*
 * Побитовое «И» для чисел типа decimal
 */
s21_decimal s21_decimal_binary_and(s21_decimal decimal1, s21_decimal decimal2) {
  s21_decimal result = s21_decimal_get_zero();
  result.bits[0] = decimal1.bits[0] & decimal2.bits[0];
  result.bits[1] = decimal1.bits[1] & decimal2.bits[1];
  result.bits[2] = decimal1.bits[2] & decimal2.bits[2];
  result.bits[3] = decimal1.bits[3] & decimal2.bits[3];

  return result;
}

/*
 * Исключающее «или» для чисел типа decimal
 */
s21_decimal s21_decimal_binary_xor(s21_decimal decimal1, s21_decimal decimal2) {
  s21_decimal result = s21_decimal_get_zero();
  result.bits[0] = decimal1.bits[0] ^ decimal2.bits[0];
  result.bits[1] = decimal1.bits[1] ^ decimal2.bits[1];
  result.bits[2] = decimal1.bits[2] ^ decimal2.bits[2];
  result.bits[3] = decimal1.bits[3] ^ decimal2.bits[3];

  return result;
}

/*
 * Побитовая инверсия для чисел типа decimal
 */
s21_decimal s21_decimal_binary_not(s21_decimal decimal) {
  s21_decimal result = s21_decimal_get_zero();
  result.bits[0] = ~decimal.bits[0];
  result.bits[1] = ~decimal.bits[1];
  result.bits[2] = ~decimal.bits[2];
  result.bits[3] = ~decimal.bits[3];

  return result;
}
