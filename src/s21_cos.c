#include "s21_math.h"

long double s21_cos(double x) {
  if (x == S21_M_INF)
    return S21_M_NAN;  //+inf
  else if (x == -S21_M_INF)
    return S21_M_NAN;  //+inf
  else if (x != x)
    return S21_M_NAN;  // nan

  long double xx = x_to_pi(x);
  long double S = 0.l;
  S = s21_sin(S21_M_PI / 2 + xx);  // считать через синус

  return (S);
}
