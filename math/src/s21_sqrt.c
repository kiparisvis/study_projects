#include "s21_math.h"

long double s21_sqrt(double x) {
  double left = 0;
  double right = x;
  double rootNumber = 0;
  if (x == x) {
    if (x > 0 && x != -0 && x != -S21_INFINITY) {
      if (x < 1) right = 1;
      while (right - left > 1e-6) {
        rootNumber = (right + left) / 2;
        if (rootNumber * rootNumber > x) {
          right = rootNumber;
        } else {
          left = rootNumber;
        }
      }
    } else {
      if (x == 0) {
        left = x;
      } else {
        left = S21_NAN;
      }
    }
  } else {
    left = x;
  }
  return left;
}
