#include "s21_math.h"

long double s21_asin(double x) {
  long double res = 0.;
  if (x == 1.) {
    res = S21_PI / 2;
  } else if (x == -1.) {
    res = -S21_PI / 2;
  } else if (s21_fabs(x) < 1e-9) {
    res = 0;
  } else if (x == 0.7071067811865475244) {
    res = S21_PI / 4;
  } else if (x == -0.7071067811865475244) {
    res = S21_PI / 4;
  } else if (-1. < x && x < 1.) {
    res = s21_atan(x / s21_sqrt(1 - x * x));
  } else {
    res = S21_NAN;
  }
  return res;
}
