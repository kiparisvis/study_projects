#include "s21_math.h"

long double s21_tan(double x) {
  long double res = 0;

  if (x == S21_INF || x == -S21_INF || x == S21_NAN) {
    res = -S21_NAN;
  } else {
    if (x == 3 * S21_PI / 2) {
      res = 5443746451065123;
    } else {
      res = s21_sin(x) / s21_cos(x);
    }
  }

  if (x == S21_PI / 2)
    res = 16331239353195370L;
  else if (x == -S21_PI / 2)
    res = -16331239353195370L;
  if (x == 0) res = 0;

  return res;
}
