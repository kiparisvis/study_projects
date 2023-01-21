#include "s21_math.h"

long double s21_fabs(double x) {
  if (x == x) {
    if (x == S21_INFINITY || x == -S21_INFINITY) {
      if (x == -S21_INFINITY) x = x * (-1);
    } else {
      if (x < 0) {
        x = x * (-1);
      }
      if (x == -0) {
        x = 0;
      }
    }
  }
  return x;
}
