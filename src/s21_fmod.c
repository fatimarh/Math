#include "s21_math.h"

long double s21_fmod(double x, double y) {
  if (x == S21_M_INF || x == -S21_M_INF || y == 0.0) return S21_M_NAN;
  if (x == S21_M_INF) return S21_M_NAN;
  if (x != x || y != y) return S21_M_NAN;
  if (y == S21_M_INF || y == -S21_M_INF) return x;

  long long int fmod = 0;
  long double res = 0;
  fmod = (long double)x / (long double)y;

  res = (long double)x - fmod * (long double)y;
  return res;
}
