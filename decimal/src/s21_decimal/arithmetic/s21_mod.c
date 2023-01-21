#include <stddef.h>
#include <stdio.h>

#include "../../tests/_helpers/_debug.h"
#include "../1decimal/create_decimal.h"
#include "../another_functions/another_function.h"
#include "../comparison_operators/comparison_operators.h"
#include "../decimal_overflow/s21_decimal_overflow.h"
#include "./arithmetic.h"

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_arithmetic_result code = S21_ARITHMETIC_OK;
  int res_sign = s21_decimal_get_sign(value_1);
  s21_decimal value_1_mod = value_1;
  s21_decimal value_2_mod = value_2;
  s21_decimal_set_sign(&value_1_mod, 0);
  s21_decimal_set_sign(&value_2_mod, 0);
  if (!s21_is_correct_decimal(value_1) || !s21_is_correct_decimal(value_2) ||
      result == NULL) {
    return -1;  // обработка ошибок
  } else if (s21_is_equal(value_2, s21_decimal_get_zero())) {
    code = S21_ARITHMETIC_ZERO_DIV;
  } else if (s21_is_equal(value_1, s21_decimal_get_zero())) {
    *result = s21_decimal_get_zero();
  } else if (s21_is_greater(value_2_mod, value_1_mod)) {
    *result = value_1;
  } else {
    s21_decimal_overflow res = s21_decimal_overflow_get_zero();
    s21_decimal_overflow remainder = s21_decimal_overflow_get_zero();
    s21_decimal_overflow dividend =
        decimal_to_s21_decimal_overflow(value_1_mod);
    s21_decimal_overflow divisor = decimal_to_s21_decimal_overflow(value_2_mod);
    code =
        s21_decimal_overflow_div_big_int(dividend, divisor, &res, &remainder);
    if (code == S21_ARITHMETIC_OK) {
      int temp_exp = s21_decimal_overflow_get_exp(dividend) -
                     s21_decimal_overflow_get_exp(divisor);
      while (temp_exp > 0) {
        s21_decimal_overflow tmp_rem = s21_decimal_overflow_get_zero();
        s21_decimal_overflow_div_big_int(
            res, decimal_to_s21_decimal_overflow(s21_decimal_get_ten()), &res,
            &tmp_rem);
        temp_exp--;
      }
      while (temp_exp < 0) {
        s21_decimal_overflow_mul(
            res, decimal_to_s21_decimal_overflow(s21_decimal_get_ten()), &res);
        s21_decimal_overflow_mul(
            remainder, decimal_to_s21_decimal_overflow(s21_decimal_get_ten()),
            &remainder);
        s21_decimal_overflow temp_res = s21_decimal_overflow_get_zero();
        s21_decimal_overflow_div_big_int(remainder, divisor, &temp_res,
                                         &remainder);
        res = s21_decimal_overflow_add(res, temp_res);
        temp_exp++;
      }
      code = s21_decimal_overflow_mul(res, divisor, &res);
      if (code == S21_ARITHMETIC_OK) {
        res = s21_decimal_overflow_change_sign(res);
        res = s21_decimal_overflow_add(dividend, res);
      }
    }
    if (res_sign) {
      res = s21_decimal_overflow_set_sign(res, 1);
    }
    *result = s21_decimal_overflow_to_decimal(res);
  }
  return code;
}
