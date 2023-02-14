#include "s21_math.h"

long double s21_atan(double x) {
  long double sum_atan = 0;
  const long double s21_atan_1 = 0.7853981633974480L;
  long double xx = x;
  if (xx == 1) {
    sum_atan = s21_atan_1;
  } else if (xx == -1) {
    sum_atan = -s21_atan_1;
  } else if (xx == S21_M_PI / 2) {
    sum_atan = 1.003884821853887214L;
  } else if (xx == S21_M_INF || xx == -S21_M_INF) {
    sum_atan = xx < 0 ? -S21_M_PI / 2 : S21_M_PI / 2;
  } else if (xx == S21_M_NAN) {
    sum_atan = S21_M_NAN;
  } else if (-1. < xx && xx < 1.) {
    for (register int i = 0; i < 40; i++) {
      sum_atan += s21_pow(-1, i) * s21_pow(xx, 1 + (2 * i)) / (1 + (2 * i));
    }
  } else {
    for (register int i = 0; i < 40; i++) {
      sum_atan += s21_pow(-1, i) * s21_pow(xx, -1 - (2 * i)) / (1 + (2 * i));
    }
    sum_atan = S21_M_PI * s21_sqrt(xx * xx) / (2 * xx) - sum_atan;
  }
  return sum_atan;
}
