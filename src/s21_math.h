#ifndef SRC_S21_MATH_H
#define SRC_S21_MATH_H

#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define S21_M_PI 3.14159265358979323846264338327950288
#define S21_M_E 2.71828182845904523536028747135266250
#define S21_M_PRE 1e-9

#define S21_M_INF 1.0 / 0.0
#define S21_M_NAN 0.0 / 0.0
#define NUMBER_NAN 9223372036854775808UL

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
long double x_to_pi(double x);

#endif  // SRC_S21_MATH_H