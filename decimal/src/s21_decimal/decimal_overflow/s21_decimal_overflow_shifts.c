#include <stdio.h>

#include "s21_decimal_overflow.h"

/*
 * Функция сдвигает биты мантиссы влево на shifts разрядов
 */
s21_decimal_overflow s21_decimal_overflow_shift_left(s21_decimal_overflow in,
                                                     int shifts) {
  // Начинаем со старшего инта. Если есть переполнение - меняем знак
  if (s21_decimal_overflow_is_set_bit(in, 191))
    in = s21_decimal_overflow_set_sign(in, 1);
  else
    in = s21_decimal_overflow_set_sign(in, 0);
  while (shifts) {
    int index = 159;
    for (int i = 5; i >= 0; i--) {
      in.parts[i] = in.parts[i] << 1;
      if (i && s21_decimal_overflow_is_set_bit(in, index)) {
        in = s21_decimal_overflow_set_bit(in, index + 1);
      }
      index -= 32;
    }
    shifts--;
  }
  return in;
}

/*
 * Функция сдвигает биты мантиссы вправо на shifts разрядов
 */
s21_decimal_overflow s21_decimal_overflow_shift_right(s21_decimal_overflow in,
                                                      int shifts) {
  while (shifts) {
    int index = 32;
    for (int i = 0; i <= 5; i++) {
      in.parts[i] = in.parts[i] >> 1;
      if (i != 5 && s21_decimal_overflow_is_set_bit(in, index)) {
        in = s21_decimal_overflow_set_bit(in, index - 1);
      }
      index += 32;
    }
    shifts--;
  }
  return in;
}
