#include "../1decimal.h"

/*
 * Сдвигает
 */
int s21_is_set_bit(int number, int index) {
  return (number & (1U << index)) >> index;
}

int s21_set_bit(int number, int index) { return number | (1U << index); }

int s21_reset_bit(int number, int index) { return number & ~(1U << index); }

/*
 * Проверяет, установлен ли бит (имеет значение 1) номер index в числе
 * decimal. Валидация данных не осуществляется и должна осуществляться до вызова
 * функции
 */
int s21_decimal_is_set_bit(s21_decimal decimal, int index) {
  return s21_is_set_bit(decimal.bits[index / MAX_BLOCK_BITS],
                        index % MAX_BLOCK_BITS);
}

/*
 * Устанавливает значение 1 для бита номер index в числе decimal
 * Валидация данных не осуществляется и должна осуществляться до вызова функции
 */
s21_decimal s21_decimal_set_bit(s21_decimal decimal, int index) {
  decimal.bits[index / MAX_BLOCK_BITS] =
      s21_set_bit(decimal.bits[index / MAX_BLOCK_BITS], index % MAX_BLOCK_BITS);
  return decimal;
}

/*
 * Находит ближайший к старшему биту установленный бит (который имеет
 * значение 1) числа decimal Например:
 * 10000000 00000000 00000000 00000000 ... 00000000 10000001 00011000 00000000 -
 * вернет 127
 * 00100000 00000000 00000000 00000000 ... 00000000 00000000 00000000 10000000 -
 * вернет 125
 * 00000000 00000000 00000000 00000000 ... 00000000 00000000 00000000 10000000 -
 * вернет 7
 * 00000000 00000000 00000000 00000000 ... 00000000 00000000 00000000 00000001 -
 * вернет 0
 *
 * Если все биты равны 0, то вернет -1
 */
int s21_decimal_get_not_zero_bit(s21_decimal decimal) {
  int flag = -1;
  for (int i = MAX_BITS - 1; i >= 0; i--) {
    if (s21_decimal_is_set_bit(decimal, i)) {
      flag = i;
      break;
    }
  }
  return flag;
}
