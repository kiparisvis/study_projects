#include <math.h>

#include "../1decimal/create_decimal.h"
#include "../binary/binary.h"
#include "../comparison_operators/comparison_operators.h"
#include "./convertors.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  s21_convertation_code_error code = S21_CONVERTATION_OK;
  if (!dst) {
    // Если указатель на float является NULL
    code = S21_CONVERTATION_ERROR;
  } else if (!s21_is_correct_decimal(src)) {
    // Проверяем, что src является корректным decimal
    code = S21_CONVERTATION_ERROR;
    *dst = 0.0;
  } else if (s21_is_equal(src, s21_decimal_get_zero())) {
    // Отдельно обрабатываем 0 и -0
    int sign = s21_decimal_get_sign(src);
    if (sign == S21_NEGATIVE) {
      *dst = -0.0;
    } else {
      *dst = 0.0;
    }
    code = S21_CONVERTATION_OK;
  } else {
    // В остальных случаях осуществляем конвертацию
    *dst = 0.0;
    // float и long double не подойдут
    double tmp = 0.0;
    // Запоминаем знак и степень decimal
    int sign = s21_decimal_get_sign(src);
    int power = s21_decimal_get_power(src);
    // Каждый бит decimal переводим в double
    for (int i = 0; i < MAX_BLOCK_NUMBER; i++) {
      if (s21_decimal_is_set_bit(src, i) != 0) {
        tmp += pow(2.0, i);
      }
    }
    // Затем учитываем степень и корректируем итоговый результат
    double powerten = pow(10, power);
    tmp /= powerten;
    if (sign == S21_NEGATIVE) {
      tmp *= -1.0;
    }
    *dst = (float)tmp;
  }
  return code;
}
