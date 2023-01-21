#include "s21_math.h"

long double s21_log(double x) {
  long double res = 0;
  int check = 0;
  int i = 0;
  double befor = 0;
  if (x == 0.0) {
    res = -S21_INFINITY;
  } else if (x != x && x == -S21_INFINITY) {
    res = S21_NAN;
  } else if (x < 0.0) {
    res = S21_NAN;
  } else if (x == 1) {
    res = 0;
  } else if (x == S21_INFINITY) {
    res = S21_INFINITY;
  } else if (x == S21_E) {
    res = 1;
  } else {
    while (x > S21_E) {
      x = x / S21_E;
      check++;
      continue;
    }
    while (i < 200) {
      res = befor + 2 * (x - s21_exp(befor)) / (x + s21_exp(befor));
      befor = res;
      i++;
    }
  }
  return (res + check);
}
