#ifndef SRC_S21_DECIMAL_DECIMAL_OVERFLOW_S21_DECIMAL_OVERFLOW_H_
#define SRC_S21_DECIMAL_DECIMAL_OVERFLOW_S21_DECIMAL_OVERFLOW_H_

#include "../1decimal.h"

typedef struct s21_decimal_overflow {
  unsigned int parts[7];
} s21_decimal_overflow;

typedef enum s21_decimal_overflow_comparison_result {
  S21_DECIMAL_OVERFLOW_COMPARISON_EQUAL = 0,
  S21_DECIMAL_OVERFLOW_COMPARISON_FIRST_GREATER = 1,
  S21_DECIMAL_OVERFLOW_COMPARISON_SECOND_GREATER = -1,
} s21_decimal_overflow_comparison_result;

int s21_decimal_overflow_compare(s21_decimal_overflow first,
                                 s21_decimal_overflow second);

s21_decimal_overflow decimal_to_s21_decimal_overflow(s21_decimal in);
s21_decimal s21_decimal_overflow_to_decimal(s21_decimal_overflow in);

s21_decimal_overflow s21_decimal_overflow_and(s21_decimal_overflow first,
                                              s21_decimal_overflow second);
s21_decimal_overflow s21_decimal_overflow_xor(s21_decimal_overflow first,
                                              s21_decimal_overflow second);
s21_decimal_overflow s21_decimal_overflow_not(s21_decimal_overflow in);

s21_decimal_overflow s21_decimal_overflow_get_bit(int index);
unsigned int s21_decimal_overflow_is_set_bit(s21_decimal_overflow in,
                                             int index);
s21_decimal_overflow s21_decimal_overflow_set_bit(s21_decimal_overflow in,
                                                  int index);
s21_decimal_overflow s21_decimal_overflow_flip_bit(s21_decimal_overflow in,
                                                   int index);
unsigned int s21_decimal_overflow_get_sign(s21_decimal_overflow in);
s21_decimal_overflow s21_decimal_overflow_set_sign(s21_decimal_overflow in,
                                                   int sign);
s21_decimal_overflow s21_decimal_overflow_change_sign(s21_decimal_overflow in);

s21_decimal_overflow s21_decimal_overflow_get_zero(void);
s21_decimal_overflow s21_decimal_overflow_to_twos_complement(
    s21_decimal_overflow direct_code);

s21_decimal_overflow s21_decimal_overflow_incr(s21_decimal_overflow in);

s21_decimal_overflow s21_decimal_overflow_shift_left(s21_decimal_overflow in,
                                                     int shifts);
s21_decimal_overflow s21_decimal_overflow_shift_right(s21_decimal_overflow in,
                                                      int shifts);

int s21_decimal_overflow_div_big_int(s21_decimal_overflow dividend,
                                     s21_decimal_overflow divisor,
                                     s21_decimal_overflow *result,
                                     s21_decimal_overflow *remainder);

int s21_decimal_overflow_round_to_decimal(s21_decimal_overflow in,
                                          s21_decimal *res);

unsigned int s21_decimal_overflow_is_zero(s21_decimal_overflow in);
int s21_decimal_overflow_get_exp(s21_decimal_overflow in);
void s21_decimal_overflow_set_exp(s21_decimal_overflow *in, int exp);
unsigned int s21_decimal_overflow_get_not_zero_bit(s21_decimal_overflow in);

void s21_decimal_overflow_balance_exp(s21_decimal_overflow *first,
                                      s21_decimal_overflow *second);
s21_decimal_overflow s21_decimal_overflow_add(s21_decimal_overflow first,
                                              s21_decimal_overflow second);
s21_decimal_overflow s21_decimal_overflow_add_big_int(
    s21_decimal_overflow first, s21_decimal_overflow second);
int s21_decimal_overflow_div(s21_decimal_overflow dividend,
                             s21_decimal_overflow divisor,
                             s21_decimal_overflow *result);
int s21_decimal_overflow_mul_big_int(s21_decimal_overflow first,
                                     s21_decimal_overflow second,
                                     s21_decimal_overflow *result);
int s21_decimal_overflow_mul(s21_decimal_overflow first,
                             s21_decimal_overflow second,
                             s21_decimal_overflow *result);

s21_decimal_overflow remove_trail_zero(s21_decimal_overflow in);

#endif  //  SRC_S21_DECIMAL_DECIMAL_OVERFLOW_S21_DECIMAL_OVERFLOW_H_
