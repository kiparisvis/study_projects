#include <math.h>
#include <stdio.h>

#include "../../s21_decimal.h"
#include "../1decimal/create_decimal.h"
#include "../binary/binary.h"
#include "../comparison_operators/comparison_operators.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  s21_convertation_code_error code = S21_CONVERTATION_OK;

  if (!dst) {
    // Если указатель на int является NULL
    code = S21_CONVERTATION_ERROR;
  } else if (!s21_is_correct_decimal(src)) {
    // Проверяем, что src является корректным decimal
    code = S21_CONVERTATION_ERROR;
    *dst = 0;
  } else {
    *dst = 0;
    s21_decimal truncated_decimal = s21_decimal_get_zero();
    // Отбрасываем дробную часть decimal
    s21_truncate(src, &truncated_decimal);

    if (s21_is_less(truncated_decimal, s21_decimal_get_int_min()) ==
        S21_COMPARISON_TRUE) {
      // Если decimal меньше -2147483648, то сконвертировать нельзя
      code = S21_CONVERTATION_ERROR;
    } else if (s21_is_greater(truncated_decimal, s21_decimal_get_int_max()) ==
               S21_COMPARISON_TRUE) {
      // Если decimal больше 2147483647, то сконвертировать нельзя
      code = S21_CONVERTATION_ERROR;
    } else {
      // В остальных случаях производим конвертацию
      for (int i = 0; i < MAX_BLOCK_NUMBER; i++) {
        if (s21_decimal_is_set_bit(truncated_decimal, i) != 0) {
          *dst += pow(2, i);
        }
      }
      // Определяем знак результата, исходя из знака числа src (типа decimal)
      if (s21_decimal_get_sign(src) == 1 && *dst != -2147483648) {
        // У INT_MIN не надо менять знак:
        // negation of -2147483648 cannot be represented in type 'int';
        // А при этом для INT_MIN при расчете мы получили переполнение int и
        // правильное значение
        *dst = -*dst;
      }
    }
  }
  return code;
}
