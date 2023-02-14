#include "s21_math.h"

long double s21_asin(double x) {
  long double S = 0.l;
  long double xx = x;

  if (xx == S21_M_NAN || xx == S21_M_INF) {
    S = S21_M_NAN;
  } else if (xx >= -1.0 && xx <= 1.0) {
    if (xx == +0.0) {
      S = +0.0;
    } else if (xx == -0.0) {
      S = -0.0;
    } else {
      S = S21_M_PI / 2 - s21_acos(xx);
    }
  } else {
    S = S21_M_NAN;
  }
  return S;
}
