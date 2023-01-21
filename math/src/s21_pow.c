// #include "s21_math.h"

// long double s21_pow(double base, double exp) {
//   long double result = 2., buffer = 0.;
//   long long int exp_int = (long long int)exp;
//   if (exp < 0.) {
//     if (s21_fabs(exp_int - exp) < S21_EPS && exp_int % 2 != 0) {
//       if (s21_is_neg_inf(1 / base)) result = S21_NEG_INF;
//       if (s21_is_pos_inf(1 / base)) result = S21_POS_INF;
//     } else {
//       if (s21_is_pos_inf(1 / base) || s21_is_neg_inf(1 / base))
//         result = S21_POS_INF;
//     }
//   } else if (exp > 0.) {
//     if (s21_fabs(exp_int - exp) < S21_EPS && exp_int % 2 != 0) {
//       if (s21_is_neg_inf(1 / base)) result = -0.;
//       if (s21_is_pos_inf(1 / base)) result = 0.;
//     } else {
//       if (s21_is_neg_inf(1 / base) || s21_is_pos_inf(1 / base)) result = 0.;
//     }
//   }
//   if ((s21_fabs(base + 1) < S21_EPS) && s21_isinf(exp)) {
//     result = 1.;
//   }
//   if ((s21_fabs(base - 1) < S21_EPS) || s21_is_pos_inf(1 / exp) ||
//       s21_is_neg_inf(1 / exp)) {
//     result = 1.;
//   }
//   if (base < 0. && !s21_is_neg_inf(base) && !s21_isinf(exp) && exp_int !=
//   exp) {
//     return S21_NAN;
//   }
//   if (s21_is_neg_inf(exp)) {
//     if (s21_fabs(base) < 1.) result = S21_POS_INF;
//     if (s21_fabs(base) > 1.) result = 0.;
//   }
//   if (s21_is_pos_inf(exp)) {
//     if (s21_fabs(base) < 1.) result = 0.;
//     if (s21_fabs(base) > 1.) result = S21_POS_INF;
//   }
//   if (s21_is_neg_inf(base) && exp < 0.) {
//     if (s21_fabs(exp_int - exp) < S21_EPS && exp_int % 2 != 0.) {
//       result = -0.;
//     } else {
//       result = 0.;
//     }
//   }
//   if (s21_is_neg_inf(base) && exp > 0.) {
//     if (s21_fabs(exp_int - exp) < S21_EPS && exp_int % 2 != 0.) {
//       result = S21_NEG_INF;
//     } else {
//       result = S21_POS_INF;
//     }
//   }
//   if (s21_is_pos_inf(base) && exp < 0.) {
//     result = 0.;
//   }
//   if (s21_is_pos_inf(base) && exp > 0.) {
//     result = S21_POS_INF;
//   }
//   if ((s21_fabs(base) < S21_EPS) && (s21_fabs(exp) < S21_EPS)) {
//     result = 1.;
//   }
//   if (result == 2.) {
//     if (base < 0.) {
//       buffer = -base;
//       result = s21_exp(exp * s21_log(buffer));
//       if (s21_fmod(exp, 2) != 0.) result = -result;
//     } else {
//       result = s21_exp(exp * s21_log(base));
//     }
//   }
//   return result;
// }

#include "s21_math.h"

long double s21_pow_calc(double base, double exp) {
  long double result = 0, base_copy = base;
  if (base < 0) {
    base_copy = -base_copy;
    result = s21_exp(exp * s21_log(base_copy));
    if (s21_fmod(exp, 2) != 0) result = -result;
  } else {
    result = s21_exp(exp * s21_log(base));
  }
  if (exp == 1) result = base;
  if (exp == 0) result = 1;
  return result;
}

long double s21_pow(double base, double exp) {
  int base_is_fin = is_finite(base);
  int exp_is_fin = is_finite(exp);
  int exp_int = s21_fabs(exp - s21_floor(exp)) <= S21_ACCUR;
  int enter = 0;
  long double res = 0.;

  // exp is DBL_MAX
  if (base < 0 && (exp == DBL_MAX || exp == -DBL_MAX) && enter == 0) {
    res = -s21_pow_calc(base, exp);
    enter++;
  }

  // base ±0 returns +0 for exp > 0 and even integer or non-integer
  if ((s21_fabs(base) < S21_ACCUR) && (exp > S21_ACCUR) &&
      (((exp_int && !((int)exp) % 2)) || (!exp_int)) && enter == 0) {
    res = 0;
    enter++;
  }

  // exp is ±0 returns 1 for any base, even when base is NaN
  if ((s21_fabs(exp) < S21_ACCUR) && enter == 0) {
    res = 1.;
    enter++;
  }

  // base = 1 or base = -1 and exp = +-INF
  if ((((base == -1) && ((exp == +S21_INF) || (exp == -S21_INF))) ||
       (base == 1)) &&
      enter == 0) {
    res = 1.;
    enter++;
  }

  // base is finite and negative and exp is finite and non-integer
  if (base_is_fin && base < -S21_ACCUR && exp_is_fin && !exp_int &&
      s21_fabs(exp) > 0 && enter == 0) {
    res = S21_NAN;
    enter++;
  }

  // |base| < 1 and exp is -INF or |base| > 1 and exp is +INF
  if (((s21_fabs(base) - 1 < S21_ACCUR && exp == -S21_INF) ||
       (s21_fabs(base) - 1 > S21_ACCUR && exp == +S21_INF)) &&
      enter == 0) {
    res = +S21_INF;
    enter++;
  }

  // |base| > 1 and exp is -INF or |base| < 1 and exp is +INF
  if (((s21_fabs(base) - 1 > S21_ACCUR && exp == -S21_INF) ||
       (s21_fabs(base) - 1 < S21_ACCUR && exp == +S21_INF)) &&
      enter == 0) {
    res = +0;
    enter++;
  }

  // base is -INF returns +INF if exp is a positive non-integer or positive even
  // integer
  if ((base == -S21_INF) && (exp > S21_ACCUR) &&
      (((exp_int && !((int)exp) % 2)) || (!exp_int)) && enter == 0) {
    res = +S21_INF;
    enter++;
  }

  // base is -INF returns +0 if exp is a negative non-integer or negative even
  // integer
  if ((base == -S21_INF) && (exp < S21_ACCUR) && enter == 0 &&
      (((exp_int && !((int)exp) % 2)) || (!exp_int))) {
    res = 0;
    enter++;
  }

  if (enter == 0) res = s21_pow_calc(base, exp);
  return res;
}
