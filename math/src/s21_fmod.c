#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double res = S21_NAN;
  if (y == S21_INFINITY || y == -S21_INFINITY) {
    if (x != S21_INFINITY && x != -S21_INFINITY && x == x) {
      res = 0;
    }
  } else if (x == S21_INFINITY || x == -S21_INFINITY) {
    res = S21_NAN;
  } else if (y == 0) {
    res = S21_NAN;
  } else if (y) {
    long long int ost = x / y;
    res = x - ost * y;
  }
  return res;
}
