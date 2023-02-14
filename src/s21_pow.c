#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double result = 0.;
  long double copyofbase = base;
  long double copyofexp = exp;

  if (copyofbase == 1.0) {
    result = 1.0;
  } else if (copyofexp == 0.0) {
    result = 1.0;
  } else if (copyofexp == 1.0) {
    result = copyofbase;
  } else if (copyofbase == -1.0 &&
             (copyofexp == S21_M_INF || copyofexp == -S21_M_INF)) {
    result = 1.0;
  } else if (copyofbase > -1 && copyofbase < 0) {
    if (copyofexp == S21_M_INF) result = 0;
    if (copyofexp == -S21_M_INF) result = -S21_M_INF;
  } else if ((copyofbase < 1 && copyofbase > 0) && copyofexp == S21_M_INF)
    result = 0;
  else if ((copyofbase < 1 && copyofbase > 0) && copyofexp == -S21_M_INF)
    result = S21_M_INF;
  else if (copyofbase < 0 && copyofexp == S21_M_INF) {
    result = S21_M_INF;
  } else if (copyofbase < 0 && copyofexp == -S21_M_INF) {
    result = -0;
  } else if (copyofbase == -S21_M_INF && copyofexp > 0) {
    result = S21_M_INF;
  } else if (copyofbase == -S21_M_INF && copyofexp < 0) {
    result = 0;
  } else if (copyofbase == 0.0 && copyofexp == -S21_M_INF) {
    result = S21_M_INF;
  } else if (copyofbase == S21_M_INF) {
    result = (copyofexp > 0) ? S21_M_INF : 0.0;
  } else if (copyofexp == S21_M_INF && copyofbase == 0.0) {
    result = 0;
  } else if (copyofexp == S21_M_INF) {
    result = (copyofbase > 0) ? S21_M_INF : S21_M_NAN;
  } else if (copyofexp == -S21_M_INF) {
    result = (copyofbase > 0) ? 0.0 : S21_M_NAN;
  } else if (copyofbase == 0.0 && copyofexp > 0) {
    result = 0.0;
  } else if (copyofbase == 0.0 && copyofexp < 0) {
    result = S21_M_INF;
  } else if ((int)copyofexp != copyofexp && copyofbase < 0) {
    result = S21_M_NAN;
  } else {
    if (copyofbase < 0) {
      if (s21_fabs(copyofexp - (int)copyofexp) > S21_M_PRE) {
        result = S21_M_NAN;
      } else {
        copyofbase = -copyofbase;
        result = s21_exp(copyofexp * s21_log(copyofbase));
        if (s21_fmod(copyofexp, 2) != 0) {
          result = -result;
        }
      }
    } else {
      result = s21_exp(copyofexp * s21_log(copyofbase));
    }
  }
  return result;
}
