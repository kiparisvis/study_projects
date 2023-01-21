#include "./binary.h"

/*
 * Функция определяет, являются ли все биты decimal нулями
 */
int s21_decimal_binary_equal_zero(s21_decimal decimal) {
  return decimal.bits[0] == 0 && decimal.bits[1] == 0 && decimal.bits[2] == 0 &&
         decimal.bits[3] == 0;
}

/*
 * Сравнивает побитово 2 числа типа decimal
 * -1 - Значение d1 меньше d2.
 *  0 - Значения d1 и d2 равны.
 *  1 - Значение d1 больше значения d2.
 */
int s21_decimal_binary_compare(s21_decimal d1, s21_decimal d2) {
  int flag = 0;
  for (int i = MAX_BITS - 1; i >= 0; i--) {
    int b1 = s21_decimal_is_set_bit(d1, i);
    int b2 = s21_decimal_is_set_bit(d2, i);
    if (b1 == 0 && b2 != 0) {
      flag = -1;
    }
    if (b1 != 0 && b2 == 0) {
      flag = 1;
    }
    if (flag != 0) {
      break;
    }
  }
  return flag;
}
