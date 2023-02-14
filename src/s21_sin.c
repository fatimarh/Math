#include "s21_math.h"

long double s21_sin(double x) {
  if (x >= S21_M_INF)
    return S21_M_NAN;
  else if (x <= -S21_M_INF)
    return S21_M_NAN;
  else if (x != x)
    return S21_M_NAN;

  long double xx = x_to_pi(x);
  long double S = xx;
  long double q = 0.l;
  long double dividend = 0.0, divider = 1.0;
  int n = 1;

  do {
    dividend = s21_pow(xx, (2 * n + 1));
    divider *= 2 * n * (2 * n + 1);
    q = dividend / divider;
    if (s21_fabs(s21_pow((-1), n)) > DBL_MAX ||
        s21_fabs(s21_pow(xx, (2 * n + 1))) > DBL_MAX)
      break;
    S += (q * s21_pow((-1), n));
    n++;
  } while (s21_fabs(q) > S21_M_PRE);
  return (S);
}
