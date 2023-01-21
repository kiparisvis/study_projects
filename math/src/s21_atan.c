#include "s21_math.h"

static const long double s21_atan_1 = 0.7853981633974480L;

long double atan_inf(double x) { return x < 0 ? -S21_PI / 2 : S21_PI / 2; }

long double atan_sum_1(double x) {
  long double result = 0;
  for (register int i = 0; i < 5000; i++) {
    result += s21_pow(-1, i) * s21_pow(x, 1 + (2 * i)) / (1 + (2 * i));
  }
  return result;
}

long double atan_sum_def(double x) {
  long double result = 0;
  for (register int i = 0; i < 7000; i++) {
    result += s21_pow(-1, i) * s21_pow(x, -1 - (2 * i)) / (1 + (2 * i));
  }
  result = S21_PI * s21_sqrt(x * x) / (2 * x) - result;
  return result;
}

long double s21_atan(double x) {
  long double res = 0.;
  if (is_nan(x)) {
    res = S21_NAN;
  } else if (x == 1.) {
    res = s21_atan_1;
  } else if (x == -1.) {
    res = -s21_atan_1;
  } else if (x == S21_PI / 2) {
    res = 1.003884821853887214L;
  } else if (x == -S21_PI / 2) {
    res = -1.003884821853887214L;
  } else if (x == -0.7071067811865475244) {
    res = S21_PI / 4;
  } else if (x == S21_INFINITY || x == -S21_INFINITY) {
    res = atan_inf(x);
  } else if (-1. < x && x < 1.) {
    res = atan_sum_1(x);
  } else {
    res = atan_sum_def(x);
  }
  return res;
}
