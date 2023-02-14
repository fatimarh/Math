#include "s21_math.h"

long double s21_exp(double x) {
  if (x != x) return S21_M_NAN;
  if (x == S21_M_INF) return S21_M_INF;
  if (x == -S21_M_INF) return 0.0;

  long double add_value = 1;
  long double series = 1;
  long double i = 1;
  long double copyofx = x;
  int negative = 0;

  if (x < 0) {
    copyofx *= -1;
    negative = 1;
  }
  while (s21_fabs(add_value) > S21_M_PRE) {
    add_value = add_value * (copyofx / i);
    i++;
    series = series + add_value;
    if (series > DBL_MAX) {
      series = S21_M_INF;
      break;
    }
  }
  if (negative == 1) {
    if (series > DBL_MAX) {
      series = 0;
    } else {
      series = 1. / series;
    }
  }
  return (series > DBL_MAX) ? S21_M_INF : series;
}
