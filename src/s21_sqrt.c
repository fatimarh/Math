#include "s21_math.h"

long double s21_sqrt(double x) {
  if (x != x) return S21_M_NAN;
  if (x == 0) return 0;
  if (x == -0) return -0;
  if (x == S21_M_INF) return S21_M_INF;

  long double res = 0;
  long double copyofx = x;

  if (copyofx < 0) {
    res = S21_M_NAN;
  } else {
    res = s21_pow(copyofx, 0.5);
  }
  return res;
}
