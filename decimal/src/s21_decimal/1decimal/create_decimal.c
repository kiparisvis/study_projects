#include "create_decimal.h"

#include <string.h>

#include "../binary/binary.h"

/*
 * Возвращает заполненный s21_decimal по данным аргументов
 */
s21_decimal s21_create_decimal_from_array(int data0, int data1, int data2,
                                          int data3) {
  s21_decimal decimal;

  decimal.bits[0] = data0;
  decimal.bits[1] = data1;
  decimal.bits[2] = data2;
  decimal.bits[3] = data3;

  return decimal;
}

/*
 * Возвращает заполненный s21_decimal по данным аргументов
 */
s21_decimal s21_create_decimal_from_data(int sign, int power, int data0,
                                         int data1, int data2) {
  s21_decimal decimal;
  s21_clear_decimal(&decimal);

  decimal.bits[0] = data0;
  decimal.bits[1] = data1;
  decimal.bits[2] = data2;

  s21_decimal_set_power(&decimal, power);
  s21_decimal_set_sign(&decimal, sign);

  return decimal;
}

/*
 * Возвращает заполненный s21_decimal по данным аргументов
 *
 * Пробелы в строке игнорируются, можно передать как "11111111 11111111 11111111
 * 11111111", так и "11111111111111111111111111111111" Если в строке окажутся
 * символы, отличные от " 01" или количество бит в строке будет больше 32, то
 * функция вернет некорректный decimal (все биты которого 1)
 */
s21_decimal s21_create_decimal_from_strings(char *str0, char *str1, char *str2,
                                            char *str3) {
  s21_decimal decimal = s21_decimal_get_zero();
  int flag = 0;

  flag = s21_decimal_set_bits_from_string(&decimal.bits[0], str0);

  if (flag == 0) {
    flag = s21_decimal_set_bits_from_string(&decimal.bits[1], str1);
  }

  if (flag == 0) {
    flag = s21_decimal_set_bits_from_string(&decimal.bits[2], str2);
  }

  if (flag == 0) {
    flag = s21_decimal_set_bits_from_string(&decimal.bits[3], str3);
  }

  if (flag == 1) {
    decimal.bits[0] = -1;
    decimal.bits[1] = -1;
    decimal.bits[2] = -1;
    decimal.bits[3] = -1;
  }

  return decimal;
}

/*
 * Устанавливает биты числа bits в соответствии со строкой str
 */
int s21_decimal_set_bits_from_string(int *bits, char *str) {
  int index = 0;
  int flag = 0;

  for (int i = (int)strlen(str) - 1; i >= 0; i--) {
    if (str[i] == ' ') {
      continue;
    } else if (str[i] == '1') {
      *bits = s21_set_bit(*bits, index);
    } else if (str[i] == '0') {
      *bits = s21_reset_bit(*bits, index);
    } else {
      flag = 1;
      break;
    }
    ++index;
  }
  return flag;
}

/*
 * Зануляет все биты числа типа s21_decimal
 */
void s21_clear_decimal(s21_decimal *decimal) {
  decimal->bits[0] = 0;
  decimal->bits[1] = 0;
  decimal->bits[2] = 0;
  decimal->bits[3] = 0;
}

/*
 * Формирует и возвращает число 0 в виде s21_decimal
 */
s21_decimal s21_decimal_get_zero(void) {
  s21_decimal result;
  s21_clear_decimal(&result);

  return result;
}

/*
 * Формирует и возвращает число 1 в виде s21_decimal
 */
s21_decimal s21_decimal_get_one(void) {
  s21_decimal result;
  s21_clear_decimal(&result);
  result.bits[0] = 1;

  return result;
}

/*
 * Формирует и возвращает число 5 в виде s21_decimal
 */
s21_decimal s21_decimal_get_five(void) {
  s21_decimal result;
  s21_clear_decimal(&result);
  result.bits[0] = 5;

  return result;
}

/*
 * Формирует и возвращает число 10 в виде s21_decimal
 */
s21_decimal s21_decimal_get_ten(void) {
  s21_decimal result;
  s21_clear_decimal(&result);
  result.bits[0] = 10;

  return result;
}

/*
 * Формирует и возвращает число 10 в степени pow в виде числа s21_decimal
 */
s21_decimal s21_decimal_get_ten_pow(int pow) { return all_ten_pows[pow]; }

/*
 * Формирует и возвращает число 2147483647 в виде s21_decimal
 */
s21_decimal s21_decimal_get_int_max(void) {
  //  INT_MAX = 2147483647
  s21_decimal result = {{0x7FFFFFFF, 0x0, 0x0, 0x0}};
  return result;
}

/*
 * Формирует и возвращает число -2147483648 в виде s21_decimal
 */
s21_decimal s21_decimal_get_int_min(void) {
  //  INT_MAX = -2147483648
  s21_decimal result = {{0x80000000, 0x0, 0x0, 0x80000000}};
  return result;
}

/*
 * Формирует и возвращает число, близкое к бесконечности в виде s21_decimal
 */
s21_decimal s21_decimal_get_inf(void) {
  s21_decimal result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x7FFFFFFF}};
  return result;
}

/*
 * Заполняет мантиссу нулями
 */
int s21_decimal_mantissa_is_zero(s21_decimal decimal) {
  return decimal.bits[0] == 0 && decimal.bits[1] == 0 && decimal.bits[2] == 0;
}
