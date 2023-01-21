#include "s21_math.h"

long double s21_cos(double x) {
  long double res = 1.0;
  int i = 1;
  long double num = 1.0;
  int sign = 1;

  if (x == S21_INF || x == -S21_INF || x == S21_NAN) {
    res = -S21_NAN;
  } else {
    while ((x > S21_PI || x < -S21_PI)) {
      if (x > S21_PI) {
        x -= 2 * S21_PI;
      } else if (x < -S21_PI) {
        x += 2 * S21_PI;
      }
    }
    while (s21_fabs(num) > 0.0000001) {
      sign = (-1) * sign;
      num *= x / i++;
      num *= x / i++;
      res += sign * num;
    }
  }
  return res;
}
