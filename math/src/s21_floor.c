#include "s21_math.h"

long double s21_floor(double x) {
  long double f = 0;
  f = x;
  if (x == x && x != S21_INFINITY && x != -S21_INFINITY) {
    f = (uint128_t)x;
    if (f > x) {
      f = f - 1;
    }
  }
  return f;
}
