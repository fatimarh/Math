#include "s21_math.h"

long double s21_fabs(double x) {
  long double xx = x;
  if (xx < 0) xx = -xx;
  return xx;
}
