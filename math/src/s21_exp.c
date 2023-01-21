#include "s21_math.h"

long double s21_exp(double x) {
  long double result = 1;
  long double item = 1;
  long double i = 1;

  x = (long double)x;

  int is_neg = 0;
  if (x < 0) {
    x = -x;
    is_neg = 1;
  }

  while (s21_fabs(item) > S21_ACCUR) {
    item *= x / i;
    i++;
    result += item;
    if (result > DBL_MAX) {
      result = S21_INF;
      break;
    }
  }
  if (is_neg) {
    if (result > DBL_MAX)
      result = 0;
    else
      result = 1. / result;
  }
  return result;
}
