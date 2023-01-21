#include "./binary.h"

/*
 * Складываем, начиная с младших разрядов:
 * 1) Если соответствующие разряды обоих слагаемых содержат ноли, то и сумма
 * ноль. 2) Если в соответствующих разрядах только одно из слагаемых содержит
 * единицу, то и сумма единица. 3) Если соответствующие разряды обоих слагаемых
 * содержат единицы, то сумма двух единиц дает число два, которое в двоичной
 * системе отображается как 10, т.е. это уже двухразрядное число с нулем в
 * младшем разряде. Поэтому в тот же разряд суммы ставим ноль, а единицу
 * переносим в следующий разряд.
 *
 * Например, для 8 бит:
 * A:   1 0 1 0 0 1 1 1
 * B: + 0 0 0 1 0 0 0 1
 *      ---------------
 * C: = 1 0 1 1 1 0 0 0
 */
s21_decimal s21_decimal_binary_addition(s21_decimal decimal1,
                                        s21_decimal decimal2) {
  s21_decimal flag = decimal1;
  s21_decimal tmp = decimal2;

  while (!s21_decimal_binary_equal_zero(tmp)) {
    s21_decimal overflow_bits = s21_decimal_binary_and(flag, tmp);
    overflow_bits = s21_decimal_binary_shift_left(overflow_bits, 1);
    flag = s21_decimal_binary_xor(flag, tmp);
    tmp = overflow_bits;
  }

  return flag;
}
