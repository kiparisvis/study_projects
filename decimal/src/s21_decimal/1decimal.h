#ifndef SRC_S21_DECIMAL_DECIMAL_H_
#define SRC_S21_DECIMAL_DECIMAL_H_

#include <stdint.h>

typedef struct s21_decimal {
  int bits[4];
} s21_decimal;

#define MAX_BITS 128  //  общее кол-во бит в s21_decimal
#define MAX_BLOCK_BITS 32  //  общее кол-во бит в одном элементе массива
#define MAX_BLOCK_NUMBER 96  //  общее кол-во бит основания s21_decimal

typedef union decimal_bit3 {
  int i;
  struct {
    uint32_t empty2 : 16;
    uint32_t power : 8;
    uint32_t empty1 : 7;
    uint32_t sign : 1;
  } parts;
} decimal_bit3;

/*
 * enum для улучшения читаемости кода при проверках на знак
 * 0 - положительный s21_decimal
 * 1 - отрицательный s21_decimal
 */
typedef enum s21_decimal_sign {
  S21_POSITIVE = 0,
  S21_NEGATIVE = 1
} s21_decimal_sign;

#endif  //  SRC_S21_DECIMAL_DECIMAL_H_
