#include "../binary/binary.h"
#include "create_decimal.h"

/*
 * Проверяет корректность данных, записанных в s21_decimal
 */
int s21_is_correct_decimal(s21_decimal decimal) {
  int flag = 1;

  if (s21_decimal_get_empty1(decimal) != 0 ||
      s21_decimal_get_empty2(decimal) != 0) {
    flag = 0;
  } else {
    int power = s21_decimal_get_power(decimal);
    if (power < 0 || power > 28) {
      flag = 0;
    }
  }
  return flag;
}

/*
 * Возвращает знак s21_decimal
 */
int s21_decimal_get_sign(s21_decimal decimal) {
  decimal_bit3 bits3;
  bits3.i = decimal.bits[3];

  return bits3.parts.sign;
}

/*
 * Возвращает степень s21_decimal
 */
int s21_decimal_get_power(s21_decimal decimal) {
  decimal_bit3 bits3;
  bits3.i = decimal.bits[3];

  return bits3.parts.power;
}

/*
 * Возвращает значение битов с 24 по 30 в bits[3]
 */
int s21_decimal_get_empty1(s21_decimal decimal) {
  decimal_bit3 bits3;
  bits3.i = decimal.bits[3];

  return bits3.parts.empty1;
}

/*
 * Возвращает значение битов с 0 до 15 в bits[3]
 */
int s21_decimal_get_empty2(s21_decimal decimal) {
  decimal_bit3 bits3;
  bits3.i = decimal.bits[3];

  return bits3.parts.empty2;
}

/*
 * Устанавливает для s21_decimal знак sign
 */
void s21_decimal_set_sign(s21_decimal *decimal, int sign) {
  decimal_bit3 bits3;
  bits3.i = decimal->bits[3];
  if (sign == S21_POSITIVE) {
    bits3.parts.sign = S21_POSITIVE;
  } else {
    bits3.parts.sign = S21_NEGATIVE;
  }

  decimal->bits[3] = bits3.i;
}

/*
 * Устанавливает для s21_decimal степень
 */
void s21_decimal_set_power(s21_decimal *decimal, int power) {
  decimal_bit3 bits3;
  bits3.i = decimal->bits[3];
  bits3.parts.power = power;

  decimal->bits[3] = bits3.i;
}

/*
 * Зануляет все биты, не являющиеся самим числом s21_decimal (bits[3])
 */
void s21_decimal_null_service_bits(s21_decimal *value) { value->bits[3] = 0; }

/*
 * Проверяет, является число s21_decimal четным или нечетным
 */
int s21_even_or_odd(s21_decimal decimal) {
  int flag = 0;
  if (s21_decimal_is_set_bit(decimal, 0) == 1) {
    flag = 1;
  }
  return flag;
}
