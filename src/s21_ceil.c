#include "s21_math.h"

long double s21_ceil(double x) {
  if (x == S21_M_INF || x == -S21_M_INF) return x;
  if ((long unsigned int)x == NUMBER_NAN) return x;

  if (x > 0. && (long long int)x - x != 0) x += 1.;
  return (long long int)x;
}
