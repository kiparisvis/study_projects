#include <stdio.h>

#include "../../tests/_helpers/_debug.h"
#include "../arithmetic/arithmetic.h"
#include "s21_decimal_overflow.h"

int s21_decimal_overflow_div_big_int(s21_decimal_overflow dividend,
                                     s21_decimal_overflow divisor,
                                     s21_decimal_overflow *result,
                                     s21_decimal_overflow *remainder) {
  s21_arithmetic_result code = S21_ARITHMETIC_OK;
  // Фиксируем знак результата
  int sign = s21_decimal_overflow_get_sign(dividend) ^
             s21_decimal_overflow_get_sign(divisor);
  // Сбрасываем знак у делимого
  dividend = s21_decimal_overflow_set_sign(dividend, 0);
  *result = s21_decimal_overflow_get_zero();
  // Обработка частных случаев
  if (s21_decimal_overflow_is_zero(divisor)) {  // Деление на 0
    code = S21_ARITHMETIC_ZERO_DIV;
  } else if (s21_decimal_overflow_compare(
                 s21_decimal_overflow_set_sign(divisor, 0),
                 s21_decimal_overflow_set_sign(dividend, 0)) == 1) {
    //  Делитель больше делимого по модулю
    *result = s21_decimal_overflow_get_zero();
    *remainder = dividend;
  } else {  // делим
    // Сдвиг делителя на уровень старшего значащего бита делимого
    // Сначала вычисляем размер сдвига
    int shift_size = s21_decimal_overflow_get_not_zero_bit(dividend) -
                     s21_decimal_overflow_get_not_zero_bit(divisor);
    // Потом сдвигаем делитель
    s21_decimal_overflow shifted_divisor =
        s21_decimal_overflow_shift_left(divisor, shift_size);
    // Проставляем знак
    shifted_divisor = s21_decimal_overflow_set_sign(shifted_divisor, 1);
    s21_decimal_overflow sum = s21_decimal_overflow_get_zero();
    for (int i = 0; i <= shift_size; i++) {
      // Сдвигаем результат для записи нового бита
      *result = s21_decimal_overflow_shift_left(*result, 1);
      // Складываем делимое и отрицательный делитель
      sum = s21_decimal_overflow_add_big_int(dividend, shifted_divisor);
      // Если сумма (промежуточный остаток) больше или равна 0, то сохраняем её
      // в качестве делимого, а в результат дописываем 1. Если же сумма
      // отрицательная, то записывать ничего не надо -- там и так ноль после
      // сдвига результата. И делимое тоже не меняем чтобы сдвинулось ещё на
      // один порядок.
      if (!s21_decimal_overflow_get_sign(sum)) {
        dividend = sum;
        *result = s21_decimal_overflow_set_bit(*result, 0);
      }
      // Сдвигаем делитель на один разряд вправо
      if (i != shift_size) {
        shifted_divisor = s21_decimal_overflow_shift_right(shifted_divisor, 1);
      }
    }
    if (s21_decimal_overflow_get_sign(sum))
      *remainder = dividend;
    else
      *remainder = sum;
  }
  *result = s21_decimal_overflow_set_sign(*result, sign);
  return code;
}
