#include <stdio.h>

#include "../../tests/_helpers/_debug.h"
#include "s21_decimal_overflow.h"

/*
 * Функция принимает на входе два s21_decimal_overflow, но экспоненту игнорирует
 * и никак не обрабатывает. Возможное переполнение попадает в знаковый бит.
 * Оценивать результат уже в вызывающей функции.
 */
s21_decimal_overflow s21_decimal_overflow_add_big_int(
    s21_decimal_overflow first, s21_decimal_overflow second) {
  int exp = s21_decimal_overflow_get_exp(first);
  if (s21_decimal_overflow_get_sign(first)) {
    first = s21_decimal_overflow_to_twos_complement(first);
  }
  s21_decimal_overflow result = first;
  if (s21_decimal_overflow_get_sign(second))
    second = s21_decimal_overflow_to_twos_complement(second);
  while (!s21_decimal_overflow_is_zero(second)) {
    // Получаем carry
    s21_decimal_overflow carry = s21_decimal_overflow_and(result, second);
    s21_decimal_overflow shifted_carry =
        s21_decimal_overflow_shift_left(carry, 1);
    result = s21_decimal_overflow_xor(result, second);
    second = shifted_carry;
    if (s21_decimal_overflow_is_zero(second)) {
      result = s21_decimal_overflow_xor(result, second);
    }
  }
  s21_decimal_overflow_set_exp(&result, exp);
  return result;
}
