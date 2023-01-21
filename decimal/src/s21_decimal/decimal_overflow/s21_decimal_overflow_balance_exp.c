#include <stddef.h>
#include <stdio.h>

#include "../../tests/_helpers/_debug.h"
#include "s21_decimal_overflow.h"

/*
 * Функция выравнивания экспонент
 */
void s21_decimal_overflow_balance_exp(s21_decimal_overflow *first,
                                      s21_decimal_overflow *second) {
  s21_decimal_overflow *to_balance = NULL;
  int diff = s21_decimal_overflow_get_exp(*first) -
             s21_decimal_overflow_get_exp(*second);
  if (diff > 0) {
    to_balance = second;
  } else if (diff < 0) {
    to_balance = first;
    diff *= -1;
  }
  if (to_balance) {
    int sign = s21_decimal_overflow_get_sign(*to_balance);
    *to_balance = s21_decimal_overflow_set_sign(*to_balance, 0);
    for (int i = 0; i < diff; i++) {
      s21_decimal_overflow shifted_one =
          s21_decimal_overflow_shift_left(*to_balance, 1);
      s21_decimal_overflow shifted_three =
          s21_decimal_overflow_shift_left(*to_balance, 3);
      *to_balance =
          s21_decimal_overflow_add_big_int(shifted_one, shifted_three);
    }
    s21_decimal_overflow_set_exp(
        to_balance, s21_decimal_overflow_get_exp(*to_balance) + diff);
    if (sign) {
      *to_balance = s21_decimal_overflow_set_sign(*to_balance, 1);
    }
  }
}
