#include "s21_math.h"

long double s21_log(double x) {
  if (x == S21_M_INF || x == -S21_M_INF) return x;
  if ((long unsigned int)x == NUMBER_NAN || (long double)x < 0)
    return S21_M_NAN;
  if (x == 0) return -S21_M_INF;

  int ex_pow = 0;
  double result = 0;
  double compare = 0;

  for (; x >= S21_M_E; x /= S21_M_E, ex_pow++) continue;

  for (int i = 0; i < 40; i++) {
    compare = result;
    result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
  }

  return result + ex_pow;
}
