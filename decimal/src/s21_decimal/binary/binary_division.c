#include <stdlib.h>

#include "../1decimal/create_decimal.h"
#include "../comparison_operators/comparison_operators.h"
#include "./binary.h"

/*
 * Функция бинарного деления двоичных чисел.
 * Проверка деления на ноль должна осуществляться перед вызовом функции.
 *
 * A:   1 0 1 0 0 1 1 1
 * B: / 0 0 0 0 1 1 0 1
 *      ---------------
 * C: = 0 0 0 0 1 1 0 0
 * и 1 0 1 1 в остатке
 */
s21_decimal s21_decimal_binary_division(s21_decimal decimal1,
                                        s21_decimal decimal2,
                                        s21_decimal *remainder) {
  s21_decimal result;

  // Рассчитываемый в алгоритме частичный остаток при расчетах
  s21_decimal partial_remainder = s21_decimal_get_zero();
  // Рассчитываемое в алгоритме частное
  s21_decimal quotient = s21_decimal_get_zero();

  if (s21_decimal_binary_equal_zero(decimal1)) {
    // Частный случай, когда делимое равно 0
    quotient = s21_decimal_get_zero();
    partial_remainder = s21_decimal_get_zero();
  } else if (s21_decimal_binary_compare(decimal1, decimal2) == -1) {
    // Частный случай, когда делимое меньше делителя
    quotient = s21_decimal_get_zero();
    partial_remainder = decimal1;
  } else {
    // В остальных случаях используем деление двоичных чисел методом без
    // восстановления остатка.

    // Рассчитываем предварительный сдвиг делителя
    int left1 = s21_decimal_get_not_zero_bit(decimal1);
    int left2 = s21_decimal_get_not_zero_bit(decimal2);
    int shift = left1 - left2;

    // Сдвинутый делитель
    s21_decimal shifted_divisor =
        s21_decimal_binary_shift_left(decimal2, shift);
    // Делимое для промежуточных расчетов, на первом этапе равно decimal1
    s21_decimal dividend = decimal1;

    int need_subtraction = 1;

    while (shift >= 0) {
      // Определяем необходимое действие (прибавлять или вычитать сдвинутый
      // делитель)
      if (need_subtraction == 1) {
        partial_remainder =
            s21_decimal_binary_subtraction(dividend, shifted_divisor);
      } else {
        partial_remainder =
            s21_decimal_binary_addition(dividend, shifted_divisor);
      }

      // Сдвигаем влево на 1 частное и записываем в младший бит 1,
      // если старший бит частичного остатка равен 1
      quotient = s21_decimal_binary_shift_left(quotient, 1);
      if (s21_decimal_is_set_bit(partial_remainder, MAX_BITS - 1) == 0) {
        quotient = s21_decimal_set_bit(quotient, 0);
      }

      // Рассчитываем делимое для следующей итерации цикла
      // (сдвиг влево на 1 частичного остатка)
      dividend = s21_decimal_binary_shift_left(partial_remainder, 1);

      // Если старший бит частичного остатка равен 0, то на следующей итерации
      // необходимо проводить вычитание
      if (s21_decimal_is_set_bit(partial_remainder, MAX_BITS - 1) == 0) {
        need_subtraction = 1;
      } else {
        need_subtraction = 0;
      }
      --shift;
    }
    // Определяем, требуется ли коррекция остатка
    if (s21_decimal_is_set_bit(partial_remainder, MAX_BITS - 1)) {
      partial_remainder =
          s21_decimal_binary_addition(partial_remainder, shifted_divisor);
    }
    // Возвращаем на место частичный остаток
    partial_remainder =
        s21_decimal_binary_shift_right(partial_remainder, left1 - left2);
  }

  // Заполняем переменные результата (частное и остаток)
  result = quotient;
  if (remainder != NULL) {
    *remainder = partial_remainder;
  }

  // Выдыхаем с облегчением
  return result;
}
