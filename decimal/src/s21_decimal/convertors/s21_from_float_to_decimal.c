#include <math.h>
#include <stdio.h>

#include "../1decimal/create_decimal.h"
#include "./convertors.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  s21_convertation_code_error code = S21_CONVERTATION_OK;
  if (!dst) {
    // Если указатель на decimal является NULL
    code = S21_CONVERTATION_ERROR;
  } else if (src == 0.0) {
    // Отдельно обрабатываем 0.0, чтобы не выполнять лишних вычислений
    code = S21_CONVERTATION_OK;
    *dst = s21_decimal_get_zero();
    if (signbit(src) != 0) {
      // Добавляем знак для -0.0
      s21_decimal_set_sign(dst, S21_NEGATIVE);
    }
  } else if (isinf(src) || isnan(src)) {
    // Отдельно обрабатываем +inf, -inf, +nan, и -nan
    code = S21_CONVERTATION_ERROR;
    *dst = s21_decimal_get_inf();
    if (signbit(src) != 0) {
      // Добавляем знак для -nan и -inf
      s21_decimal_set_sign(dst, S21_NEGATIVE);
    }
  } else if (fabsf(src) > MAX_FLOAT_TO_CONVERT) {
    // MAX_FLOAT_TO_CONVERT - максимальное число, которое можно сконвертировать
    // в decimal
    code = S21_CONVERTATION_ERROR;
    *dst = s21_decimal_get_inf();
    if (signbit(src) != 0) {
      // Добавляем знак для для отрицательного числа
      s21_decimal_set_sign(dst, S21_NEGATIVE);
    }
  } else if (fabsf(src) < MIN_FLOAT_TO_CONVERT) {
    // MIN_FLOAT_TO_CONVERT - минимальное число, которое можно сконвертировать в
    // decimal
    code = S21_CONVERTATION_ERROR;
    *dst = s21_decimal_get_zero();
  } else {
    *dst = s21_decimal_get_zero();
    s21_decimal result;
    char flt[64];
    // Приводим float в научную запись - одна цифра до запятой и 6 цифр после
    // запятой В итоге мы получаем 7 значащих цифр, которые нам и нужно
    // перевести по заданию из float в decimal
    sprintf(flt, "%.6E", fabsf(src));
    // Получаем степень float из научной записи.
    int exp = s21_get_float_exp_from_string(flt);
    // Анализируем полученную степень.
    if (exp <= -23) {
      // Если степень слишком маленькая, то не все значащие цифры поместятся в
      // decimal Поэтому корректируем точность и заново приводим float в научную
      // запись уже с новой точностью
      int float_precision = exp + 28;
      sprintf(flt, "%.*E", float_precision, fabsf(src));
    }
    // Переводим строку с научной нотацией в decimal
    result = s21_float_string_to_decimal(flt);
    // Определяем знак результата, исходя из знака числа src (типа float)
    if (signbit(src) != 0) {
      s21_decimal_set_sign(&result, S21_NEGATIVE);
    }
    *dst = result;
  }
  return code;
}
