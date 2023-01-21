#include "s21_math.h"

long double s21_ceil(double x) {
  long double res = 0;
  if (x != x) {
    res = S21_NAN;
  } else if (x == S21_INF || x == S21_NEG_INF) {
    res = x;
  } else {
    long long int q = (long long int)x;
    if (x > 0 && q < x) {
      res = q + 1;
    } else {
      res = (long double)q;
    }
  }
  return res;
}
