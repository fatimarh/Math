#include "s21_math.h"

long double x_to_pi(double x) {
  long double xx = x;
  if (xx > (-2 * S21_M_PI) && xx < (2 * S21_M_PI)) {
    return xx;
  } else {
    for (; xx < (-2 * S21_M_PI) || xx > (2 * S21_M_PI);) {
      if (xx > (2 * S21_M_PI)) {
        xx -= (2 * S21_M_PI);
      } else {
        xx += (2 * S21_M_PI);
      }
    }
  }
  return xx;
}
