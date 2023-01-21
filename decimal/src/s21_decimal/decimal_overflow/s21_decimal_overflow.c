#include "s21_decimal_overflow.h"

#include <stdio.h>

#include "../../tests/_helpers/_debug.h"
#include "../1decimal/create_decimal.h"

/*
 * Конвертирует числа из типа decimal в тип s21_decimal_overflow
 */
s21_decimal_overflow decimal_to_s21_decimal_overflow(s21_decimal in) {
  s21_decimal_overflow result = s21_decimal_overflow_get_zero();
  result.parts[0] = (unsigned int)in.bits[0];
  result.parts[1] = (unsigned int)in.bits[1];
  result.parts[2] = (unsigned int)in.bits[2];
  result.parts[6] = (unsigned int)in.bits[3];
  if (s21_decimal_get_sign(in))
    result = s21_decimal_overflow_change_sign(result);
  return result;
}

/*
 * Конвертирует числа из типа s21_decimal_overflow в тип decimal
 */
s21_decimal s21_decimal_overflow_to_decimal(s21_decimal_overflow in) {
  // Число может быть отрицательным
  s21_decimal result = s21_decimal_get_zero();
  result.bits[0] = in.parts[0];
  result.bits[1] = in.parts[1];
  result.bits[2] = in.parts[2];
  // Теперь прописать экспоненту и знак
  s21_decimal_set_sign(&result, s21_decimal_overflow_get_sign(in));
  s21_decimal_set_power(&result, s21_decimal_overflow_get_exp(in));
  return result;
}

/*
 * Функция возвращает s21_decimal_overflow с одним единственным битом мантиссы
 * выставленным по индексу. Такое число удобно для проверки, установки или
 * переворачивания одного бита другого числа
 */
s21_decimal_overflow s21_decimal_overflow_get_bit(int index) {
  s21_decimal_overflow result = s21_decimal_overflow_get_zero();
  result.parts[index / 32] = 1U << index % 32;
  return result;
}

/*
 * Функция возвращает 1 если бит мантиссы установлен, иначе возвращает 0
 */
unsigned int s21_decimal_overflow_is_set_bit(s21_decimal_overflow in,
                                             int index) {
  unsigned int res = 0;
  s21_decimal_overflow bit = s21_decimal_overflow_get_bit(index);
  if (!s21_decimal_overflow_is_zero(s21_decimal_overflow_and(in, bit)))
    res = 1U;
  return res;
}

/*
 * Функция устанваливает в указанный бит мантиссы 1, если там был 0, либо
 * ничего не делает. (x OR y) = NOT(NOT(x) AND NOT(y)) Экспонента и знак не
 * меняются
 */
s21_decimal_overflow s21_decimal_overflow_set_bit(s21_decimal_overflow in,
                                                  int index) {
  s21_decimal_overflow bit = s21_decimal_overflow_get_bit(index);
  return s21_decimal_overflow_not(s21_decimal_overflow_and(
      s21_decimal_overflow_not(in), s21_decimal_overflow_not(bit)));
}
/*
 * Функция меняет значение указанного бита мантиссы на противоположное
 */
s21_decimal_overflow s21_decimal_overflow_flip_bit(s21_decimal_overflow in,
                                                   int index) {
  s21_decimal_overflow bit = s21_decimal_overflow_get_bit(index);
  return s21_decimal_overflow_xor(in, bit);
}

/*
 * Функция возвращает 1 если знак (192 индекс) установлен.
 */
unsigned int s21_decimal_overflow_get_sign(s21_decimal_overflow in) {
  return in.parts[6] & 1U;
}

/*
 * Функция устанавливает знак
 */
s21_decimal_overflow s21_decimal_overflow_set_sign(s21_decimal_overflow in,
                                                   int sign) {
  if (s21_decimal_overflow_get_sign(in) && sign == 0) {
    in.parts[6] = in.parts[6] - 1;
  } else if (!s21_decimal_overflow_get_sign(in) && sign) {
    in.parts[6] = in.parts[6] + 1;
  }
  return in;
}

/*
 * Функция меняет знак у числа типа s21_decimal_overflow на противоположный
 */
s21_decimal_overflow s21_decimal_overflow_change_sign(s21_decimal_overflow in) {
  if (s21_decimal_overflow_get_sign(in))
    in = s21_decimal_overflow_set_sign(in, 0);
  else
    in = s21_decimal_overflow_set_sign(in, 1);
  return in;
}

/*
 * Функция для получения девственно-чистого s21_decimal_overflow
 */
s21_decimal_overflow s21_decimal_overflow_get_zero(void) {
  s21_decimal_overflow result;
  for (int i = 0; i < 7; ++i) {
    result.parts[i] = 0U;
  }
  return result;
}

/*
 * Функция возвращает дополнительный код мантиссы полученного
 * s21_decimal_overflow. Знак превдварительно зануляется, чтобы не перевернулся.
 * Экспонента обнуляется.
 */
s21_decimal_overflow s21_decimal_overflow_to_twos_complement(
    s21_decimal_overflow direct_code) {
  s21_decimal_overflow result;
  if (s21_decimal_overflow_is_zero(direct_code)) {
    result = s21_decimal_overflow_get_zero();
  } else {
    direct_code = s21_decimal_overflow_set_sign(direct_code, 0);
    result = s21_decimal_overflow_incr(s21_decimal_overflow_not(direct_code));
    // Зануляем экспоненту просто сохраняя знак
    result.parts[6] = s21_decimal_overflow_get_sign(result);
  }
  return result;
}

/*
 * Функция инкремента числа типа s21_decimal_overflow
 */
s21_decimal_overflow s21_decimal_overflow_incr(s21_decimal_overflow in) {
  for (register int i = 0; i < 192; ++i) {
    int bit = s21_decimal_overflow_is_set_bit(in, i);
    in = s21_decimal_overflow_flip_bit(in, i);
    if (!bit) break;
  }
  return in;
}

/*
 * Зануление числа типа s21_decimal_overflow
 */
unsigned int s21_decimal_overflow_is_zero(s21_decimal_overflow in) {
  unsigned int result = 1U;
  for (int i = 0; i < 6; ++i) {
    if (in.parts[i] != 0) {
      result = 0U;
      break;
    }
  }
  return result;
}

/*
 * Получение экспоненты у числа типа s21_decimal_overflow
 */
int s21_decimal_overflow_get_exp(s21_decimal_overflow in) {
  return (in.parts[6] & (255U << 16)) >> 16;
}

void s21_decimal_overflow_set_exp(s21_decimal_overflow* in, int exp) {
  unsigned int sign = s21_decimal_overflow_get_sign(*in);
  (*in).parts[6] = ((unsigned int)exp) << 16;
  *in = s21_decimal_overflow_set_sign(*in, sign);
}

/*
 * Функция, противоположная занулению ("заединение" ^_^)
 */
unsigned int s21_decimal_overflow_get_not_zero_bit(s21_decimal_overflow in) {
  int i = 191;
  for (; i >= 0; i--) {
    if (s21_decimal_overflow_is_set_bit(in, i)) break;
  }
  return i;
}

/*
 * Функция очистки нулей
 */
s21_decimal_overflow remove_trail_zero(s21_decimal_overflow in) {
  s21_decimal_overflow res = in;
  int exp = s21_decimal_overflow_get_exp(in);
  if (exp > 0) {
    s21_decimal_overflow remainder = s21_decimal_overflow_get_zero();
    s21_decimal_overflow result = s21_decimal_overflow_get_zero();
    s21_decimal_overflow_div_big_int(
        in, decimal_to_s21_decimal_overflow(s21_decimal_get_ten()), &result,
        &remainder);
    while (s21_decimal_overflow_is_zero(remainder) && exp > 0) {
      exp--;
      res = result;
      s21_decimal_overflow_div_big_int(
          result, decimal_to_s21_decimal_overflow(s21_decimal_get_ten()),
          &result, &remainder);
    }
    s21_decimal_overflow_set_exp(&res, exp);
  }
  return res;
}
