#include "../binary/binary.h"
#include "s21_decimal_overflow.h"

/*
 * Функция может использоваться в двух вариантах:
 * 1. Для проверки бита. Если бит N установлен - вернёт 2^N
 * 2. При сложении двух чисел для получения битов carry, т.е. битов переноса.
 */
s21_decimal_overflow s21_decimal_overflow_and(s21_decimal_overflow first,
                                              s21_decimal_overflow second) {
  s21_decimal_overflow flag;
  for (int i = 0; i < 7; ++i) {
    flag.parts[i] = first.parts[i] & second.parts[i];
  }
  return flag;
}

/*
 * Функция может использоваться в двух вариантах:
 * 1. Для переворачивания одного бита числа. Тогда мы получаем то же число, но с
 * перевёрнутым битом и с неизменёнными остальными частями
 * 2. При сложении двух чисел. Тогда в экспоненте и знаке мы получаем "мусор".
 */
s21_decimal_overflow s21_decimal_overflow_xor(s21_decimal_overflow first,
                                              s21_decimal_overflow second) {
  s21_decimal_overflow flag;
  for (int i = 0; i < 7; ++i) {
    flag.parts[i] = first.parts[i] ^ second.parts[i];
  }
  return flag;
}

/*
 * Функция переворачивает ВСЕ биты числа
 */
s21_decimal_overflow s21_decimal_overflow_not(s21_decimal_overflow in) {
  s21_decimal_overflow flag;
  for (int i = 0; i < 7; ++i) {
    flag.parts[i] = ~in.parts[i];
  }
  return flag;
}
