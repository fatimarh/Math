#include "s21_math.h"

long double s21_acos(double x) {
  long double S = 0.l;
  long double xx = x;

  if (xx == 0) {
    return S21_M_PI / 2;
  } else if (xx == -1.) {
    return S21_M_PI;
  } else if (xx == 1.) {
    return 0;
  } else if (xx == S21_M_NAN || xx == S21_M_INF) {
    S = S21_M_NAN;
  } else if (xx > 0. && xx < 1.) {
    S = s21_atan(s21_sqrt(1 - xx * xx) / xx);
  } else if (xx < 0. && xx > -1.) {
    S = S21_M_PI + s21_atan(s21_sqrt(1 - xx * xx) / xx);
  } else {
    S = S21_M_NAN;
  }
  return S;
}
