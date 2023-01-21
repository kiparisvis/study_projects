#include "../../s21_decimal.h"
#include "_debug.h"

int test_decimal_get_sign(s21_decimal value) {
  test_decimal_bytes decimal_bytes;
  decimal_bytes.d = value;
  return decimal_bytes.parts.sign;
}
