#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(abs_tests) {
  ck_assert_int_eq(abs(-13), s21_abs(-13));
  ck_assert_int_eq(abs(13), s21_abs(13));
  ck_assert_int_eq(abs(-1000), s21_abs(-1000));
  ck_assert_int_eq(abs(32346234), s21_abs(32346234));
  ck_assert_int_eq(abs(0), s21_abs(0));
  ck_assert_int_eq(abs(-4), s21_abs(-4));
  ck_assert_int_eq(abs(0), s21_abs(0));
  ck_assert_int_eq(abs(10), s21_abs(10));
  ck_assert_int_eq(abs(4), s21_abs(4));
  ck_assert_int_eq(abs(-438), s21_abs(-438));
}
END_TEST

START_TEST(fabs_tests) {
  ck_assert_ldouble_eq(fabsl(-13.21313), s21_fabs(-13.21313));
  ck_assert_ldouble_eq(fabsl(13.21313), s21_fabs(13.21313));
  ck_assert_ldouble_eq(fabsl(-1000.21313), s21_fabs(-1000.21313));
  ck_assert_ldouble_eq(fabsl(32346234.21313), s21_fabs(32346234.21313));
  ck_assert_ldouble_eq(fabsl(0.0), s21_fabs(0.0));
  ck_assert_ldouble_eq(s21_fabs(50.0), fabsl(50.0));
  ck_assert_ldouble_eq(s21_fabs(-40.0), fabsl(-40.0));
  ck_assert_ldouble_eq(s21_fabs(-612367.54783), fabsl(-612367.54783));
  ck_assert_ldouble_eq(s21_fabs(0.0), fabsl(0.0));
  ck_assert_ldouble_eq(s21_fabs(S21_M_INF), fabsl(S21_M_INF));
}
END_TEST

START_TEST(fmod_tests) {
  ck_assert_ldouble_eq(fmodl(-13.21313, 2.5), s21_fmod(-13.21313, 2.5));
  ck_assert_ldouble_eq(fmodl(13.21313, 2.5), s21_fmod(13.21313, 2.5));
  ck_assert_ldouble_eq(fmodl(-1000.21313, 2.5), s21_fmod(-1000.21313, 2.5));
  ck_assert_ldouble_eq(fmodl(32346234.21313, 2.5),
                       s21_fmod(32346234.21313, 2.5));
  ck_assert_ldouble_eq(fmodl(0, 2.5), s21_fmod(0, 2.5));
  ck_assert_ldouble_eq(fmodl(2.5, 2.5), s21_fmod(2.5, 2.5));
  ck_assert_msg(fmodl(5.1, 3.0) == s21_fmod(5.1, 3.0), "1 test failed");
  ck_assert_msg(fmodl(-5.1, 3.0) == s21_fmod(-5.1, 3.0), "2 test failed");
  ck_assert_msg(fmodl(5.1, -3.0) == s21_fmod(5.1, -3.0), "3 test failed");
  ck_assert_msg(fmodl(-5.1, -3.0) == s21_fmod(-5.1, -3.0), "4 test failed");
  ck_assert_msg(fmodl(0.0, 1.0) == s21_fmod(0.0, 1.0), "5 test failed");
  ck_assert_msg(fmodl(-0.0, 1.0) == s21_fmod(-0.0, 1.0), "6 test failed");
  ck_assert_msg(fmodl(5.1, (int)INFINITY) == s21_fmod(5.1, (int)INFINITY),
                "7 test failed");
  ck_assert_msg(fmodl(5, 5) == s21_fmod(5, 5), "8 test failed");
}
END_TEST

START_TEST(pow_tests) {
  ck_assert_int_eq(powl(-13.21313, 2.5555), s21_pow(-13.21313, 2.5555));
  ck_assert_ldouble_eq_tol(powl(13.21313, 2.5), s21_pow(13.21313, 2.5), 9);
  ck_assert_int_eq(powl(-1000.21313, 2.5), s21_pow(-1000.21313, 2.5));
  ck_assert_ldouble_eq_tol(powl(123, -2), s21_pow(123, -2), 6);
  ck_assert_ldouble_eq_tol(powl(123, 0), s21_pow(123, 0), 6);
  ck_assert_ldouble_eq_tol(powl(123.65465456, 0), s21_pow(123.65465456, 0), 6);
  ck_assert_ldouble_eq_tol(powl(-65, 0), s21_pow(-65, 0), 6);
  ck_assert_int_eq(powl(2, S21_M_INF), s21_pow(2, S21_M_INF));
  ck_assert_int_eq(powl(2, -S21_M_INF), s21_pow(2, -S21_M_INF));
  ck_assert_int_eq(powl(2, S21_M_NAN), s21_pow(2, S21_M_NAN));
  ck_assert_int_eq(powl(S21_M_INF, 2), s21_pow(S21_M_INF, 2));
  ck_assert_int_eq(powl(-S21_M_INF, 2), s21_pow(-S21_M_INF, 2));
  ck_assert_int_eq(powl(S21_M_NAN, 3), s21_pow(S21_M_NAN, 3));
  ck_assert_int_eq(powl(3, S21_M_NAN), s21_pow(3, S21_M_NAN));
  ck_assert_double_infinite(s21_pow(0, -9));
  ck_assert_double_infinite(s21_pow(-S21_M_INF, 2.375));
  ck_assert_double_infinite(s21_pow(0.25, -S21_M_INF));
  ck_assert_int_eq(powl(0.25, S21_M_INF), s21_pow(0.25, S21_M_INF));
  ck_assert_double_infinite(s21_pow(-7.25, S21_M_INF));
  ck_assert_double_infinite(s21_pow(-S21_M_INF, 5));
  ck_assert_double_infinite(s21_pow(-434, 434));
  ck_assert_double_infinite(s21_pow(S21_M_INF, 2.375));
  ck_assert_int_eq(powl(0.0, -S21_M_INF), s21_pow(0.0, -S21_M_INF));
  ck_assert_int_eq(powl(0.0, S21_M_INF), s21_pow(0.0, S21_M_INF));
  ck_assert_int_eq(powl(-0.25, S21_M_INF), s21_pow(-0.25, S21_M_INF));
  ck_assert_int_eq(powl(-7.25, -S21_M_INF), s21_pow(-7.25, -S21_M_INF));
  ck_assert_int_eq(powl(-S21_M_INF, -5), s21_pow(-S21_M_INF, -5));
  ck_assert_int_eq(powl(+1, NAN), s21_pow(+1, S21_M_NAN));
  ck_assert_int_eq(powl(NAN, 0), s21_pow(S21_M_NAN, 0));
  ck_assert_int_eq(powl(-1, S21_M_INF), s21_pow(-1, S21_M_INF));
  ck_assert_int_eq(powl(-1, -S21_M_INF), s21_pow(-1, -S21_M_INF));
  ck_assert_int_eq(powl(-S21_M_INF, -5.98), s21_pow(-S21_M_INF, -5.98));
  ck_assert_int_eq(powl(S21_M_INF, -2.375), s21_pow(S21_M_INF, -2.375));
  ck_assert_ldouble_eq(powl(-1.0, 1), s21_pow(-1.0, 1));
  ck_assert_ldouble_eq(powl(1, 1), s21_pow(1, 1));
  ck_assert_ldouble_eq(powl(0, 0), s21_pow(0, 0));
  ck_assert_ldouble_eq_tol(powl(0.000001, -1), s21_pow(0.000001, -1), 7);
  ck_assert_ldouble_eq_tol(powl(5, 3), s21_pow(5, 3), 6);
  ck_assert_ldouble_eq_tol(powl(-5.1, 3.0), s21_pow(-5.1, 3.0), 6);
  ck_assert_ldouble_eq_tol(powl(5, 3.0), s21_pow(5, 3.0), 6);
  ck_assert_ldouble_eq_tol(powl(5.1, 3.0), s21_pow(5.1, 3.0), 6);
  ck_assert_ldouble_eq_tol(powl(0.0, 1.0), s21_pow(0.0, 1.0), 6);
  ck_assert_ldouble_eq_tol(powl(0.0, 1.0), s21_pow(0.0, 1.0), 6);
  ck_assert_ldouble_eq_tol(powl(5, 5), s21_pow(5, 5), 6);
  ck_assert_ldouble_eq_tol(powl(+1, 5), s21_pow(+1, 5), 6);
  ck_assert_ldouble_eq_tol(powl(4, 0), s21_pow(4, 0), 6);
  ck_assert_ldouble_eq_tol(powl(+0, 7), s21_pow(+0, 7), 6);
  ck_assert_ldouble_eq_tol(powl(-0, 9), s21_pow(-0, 9), 6);
  ck_assert_ldouble_eq_tol(powl(0, 3.25), s21_pow(0, 3.25), 6);
  ck_assert_double_infinite(s21_pow(S21_M_INF, S21_M_INF));
  ck_assert_double_infinite(s21_pow(-S21_M_INF, S21_M_INF));
  ck_assert_int_eq(powl(S21_M_INF, -S21_M_INF), s21_pow(S21_M_INF, -S21_M_INF));
  ck_assert_int_eq(powl(-S21_M_INF, -S21_M_INF),
                   s21_pow(-S21_M_INF, -S21_M_INF));
}
END_TEST

START_TEST(ceil_tests) {
  ck_assert_ldouble_eq(ceill(-13.54), s21_ceil(-13.54));
  ck_assert_ldouble_eq(ceill(13.54), s21_ceil(13.54));
  ck_assert_ldouble_eq(ceill(1000), s21_ceil(1000));
  ck_assert_ldouble_eq(ceill(102.0000002), s21_ceil(102.0000002));
  ck_assert_int_eq(ceill(S21_M_INF), s21_ceil(S21_M_INF));
  ck_assert_int_eq(ceill(-S21_M_INF), s21_ceil(-S21_M_INF));
  ck_assert_msg(s21_ceil(12.01) == ceill(12.01), "1 test failed");
  ck_assert_msg(s21_ceil(-12.01) == ceill(-12.01), "2  test failed");
  ck_assert_msg(s21_ceil(9.99) == ceill(9.99), "3  test failed");
  ck_assert_msg(s21_ceil(5.00) == ceill(5.00), "4  test failed");
  ck_assert_msg(s21_ceil(5.0000000000001) == ceill(5.0000000000001),
                "5  test failed");
  ck_assert_msg(s21_ceil(-5.0000000000001) == ceill(-5.0000000000001),
                "6  false");
  ck_assert_msg(s21_ceil(-12.99) == ceill(-12.99), "7 test failed");
  ck_assert_msg(s21_ceil(0) == ceill(0), "8 test failed");
  ck_assert_msg(s21_ceil(3123.43242353523) == ceill(3123.43242353523),
                "9 test failed");
}
END_TEST

START_TEST(floor_tests) {
  ck_assert_ldouble_eq(floorl(-13.54), s21_floor(-13.54));
  ck_assert_ldouble_eq(floorl(13.54), s21_floor(13.54));
  ck_assert_ldouble_eq(floorl(-0.54), s21_floor(-0.54));
  ck_assert_ldouble_eq(floorl(1000), s21_floor(1000));
  ck_assert_ldouble_eq(floorl(102.0000002), s21_floor(102.0000002));
  ck_assert_msg(floorl(12.873) == s21_floor(12.873), "1 test failed");
  ck_assert_msg(floorl(-12.873) == s21_floor(-12.873), "2 test failed");
  ck_assert_msg(floorl(12.00001) == s21_floor(12.00001), "3 test failed");
  ck_assert_msg(floorl(-12.00001) == s21_floor(-12.00001), "4 test failed");
  ck_assert_msg(floorl(-0.9999) == s21_floor(-0.9999), "5 test failed");
  ck_assert_msg(floorl(0.9999) == s21_floor(0.9999), "6 test failed");
  ck_assert_msg(floorl(5.000) == s21_floor(5.000), "7 test failed");
  ck_assert_msg(floorl(12.873) == s21_floor(12.873), "1 test failed");
  ck_assert_msg(floorl(-12.873) == s21_floor(-12.873), "2 test failed");
  ck_assert_msg(floorl(12.00001) == s21_floor(12.00001), "3 test failed");
  ck_assert_msg(floorl(-12.00001) == s21_floor(-12.00001), "4 test failed");
  ck_assert_msg(floorl(-0.9999) == s21_floor(-0.9999), "5 test failed");
  ck_assert_msg(floorl(0.9999) == s21_floor(0.9999), "6 test failed");
  ck_assert_msg(floorl(5.000) == s21_floor(5.000), "7 test failed");
}
END_TEST

START_TEST(exp_tests) {
  ck_assert_ldouble_eq_tol(expl(-13.54), s21_exp(-13.54), 6);
  ck_assert_ldouble_eq_tol(expl(13.54), s21_exp(13.54), 6);
  ck_assert_ldouble_eq_tol(expl(-0.54), s21_exp(-0.54), 6);
  ck_assert_ldouble_eq_tol(expl(1), s21_exp(1), 6);
  ck_assert_ldouble_eq_tol(expl(2), s21_exp(2), 6);
  ck_assert_ldouble_eq_tol(expl(-1), s21_exp(-1), 6);
  ck_assert_ldouble_eq_tol(expl(0), s21_exp(0), 6);
  ck_assert_int_eq(expl(S21_M_NAN), s21_exp(S21_M_NAN));
  ck_assert_ldouble_eq_tol(expl(1.2345), s21_exp(1.2345), 6);
  ck_assert_ldouble_eq_tol(expl(1.23454656768), s21_exp(1.23454656768), 6);
  ck_assert_int_eq(expl(DBL_MAX), s21_exp(DBL_MAX));
  ck_assert_int_eq(expl(DBL_MAX), s21_exp(DBL_MAX));
  ck_assert_ldouble_eq_tol(s21_exp(35), expl(35), 6);
  ck_assert_ldouble_eq_tol(s21_exp(-4), expl(-4), 6);
  ck_assert_ldouble_eq_tol(s21_exp(0), expl(0), 6);
  ck_assert_ldouble_eq_tol(expl(0.00001), s21_exp(0.00001), 6);
  ck_assert_ldouble_eq_tol(expl(-1.0), s21_exp(-1.0), 6);
  ck_assert_ldouble_eq_tol(expl(0.0), s21_exp(0.0), 6);
  ck_assert_ldouble_eq_tol(s21_exp(2.15), expl(2.15), 6);
  ck_assert_ldouble_eq_tol(s21_exp(-4.38), expl(-4.38), 6);
  ck_assert_int_eq(s21_exp(S21_M_INF), expl(S21_M_INF));
  ck_assert_int_eq(s21_exp(-S21_M_INF), expl(-S21_M_INF));
}
END_TEST

START_TEST(sin_tests) {
  ck_assert_double_eq_tol(sinl(-14.5), s21_sin(-14.5), 6);
  ck_assert_double_eq_tol(sinl(13.54), s21_sin(13.54), 6);
  ck_assert_double_eq_tol(sinl(20.000001), s21_sin(20.000001), 6);
  ck_assert_double_eq_tol(sinl(0.0), s21_sin(0.0), 6);
  ck_assert_double_eq_tol(sinl(1.0), s21_sin(1.0), 6);
  ck_assert_double_eq_tol(sinl(2.5), s21_sin(2.5), 6);
  ck_assert_double_eq_tol(sinl(6.28), s21_sin(6.28), 6);
  ck_assert_double_eq_tol(sinl(2.2343), s21_sin(2.2343), 6);
  ck_assert_double_eq_tol(sinl(0.1234), s21_sin(0.1234), 6);
}
END_TEST

START_TEST(cos_tests) {
  ck_assert_double_eq_tol(cosl(-14.5), s21_cos(-14.5), 6);
  ck_assert_double_eq_tol(cosl(13.54), s21_cos(13.54), 6);
  ck_assert_double_eq_tol(cosl(20.000001), s21_cos(20.000001), 6);
  ck_assert_double_eq_tol(cosl(0.0), s21_cos(0.0), 6);
  ck_assert_double_eq_tol(cosl(1.0), s21_cos(1.0), 6);
  ck_assert_double_eq_tol(cosl(3.14), s21_cos(3.14), 6);
  ck_assert_double_eq_tol(cosl(6.28), s21_cos(6.28), 6);
  ck_assert_double_eq_tol(cosl(2.2343), s21_cos(2.2343), 6);
  ck_assert_double_eq_tol(cosl(0.1234), s21_cos(0.1234), 6);
  ck_assert_int_eq(cosl(S21_M_INF), s21_cos(S21_M_INF));
  ck_assert_int_eq(cosl(-S21_M_INF), s21_cos(-S21_M_INF));
  ck_assert_int_eq(cosl(S21_M_NAN), s21_cos(S21_M_NAN));
}
END_TEST

START_TEST(tan_tests) {
  ck_assert_ldouble_eq_tol(tanl(-14.5), s21_tan(-14.5), 6);
  ck_assert_ldouble_eq_tol(tanl(13.54), s21_tan(13.54), 6);
  ck_assert_ldouble_eq_tol(tanl(0), s21_tan(0), 6);
  ck_assert_ldouble_eq_tol(tanl(1), s21_tan(1), 6);
  ck_assert_ldouble_eq_tol(tanl(2.5), s21_tan(2.5), 6);
  ck_assert_ldouble_eq_tol(tanl(6.28), s21_tan(6.28), 6);
  ck_assert_ldouble_eq_tol(tanl(2.2343), s21_tan(2.2343), 6);
  ck_assert_ldouble_eq_tol(tanl(0.1234), s21_tan(0.1234), 6);
  ck_assert_int_eq(tanl(S21_M_INF), s21_tan(S21_M_INF));
  ck_assert_int_eq(tanl(-S21_M_INF), s21_tan(-S21_M_INF));
  ck_assert_int_eq(tanl(S21_M_NAN), s21_tan(S21_M_NAN));
}
END_TEST

START_TEST(sqrt_tests) {
  ck_assert_ldouble_eq_tol(sqrtl(0.0), s21_sqrt(0.0), 6);
  ck_assert_ldouble_eq_tol(sqrtl(1.0), s21_sqrt(1.0), 6);
  ck_assert_ldouble_eq_tol(sqrtl(3.14), s21_sqrt(3.14), 6);
  ck_assert_ldouble_eq_tol(sqrtl(6.28), s21_sqrt(6.28), 6);
  ck_assert_ldouble_eq_tol(sqrtl(2.2343), s21_sqrt(2.2343), 6);
  ck_assert_int_eq(sqrtl(-123), s21_sqrt(-123));
}
END_TEST

START_TEST(log_tests) {
  ck_assert_msg(logl(-13.54) != s21_log(-13.54), "FAILED");
  ck_assert_int_eq(logl(-13.54), s21_log(-13.54));
  ck_assert_ldouble_eq_tol(logl(13.54), s21_log(13.54), 6);
  ck_assert_int_eq(logl(0.0), s21_log(0.0));
  ck_assert_ldouble_eq_tol(logl(1.0), s21_log(1.0), 6);
  ck_assert_ldouble_eq_tol(logl(3.14), s21_log(3.14), 6);
  ck_assert_ldouble_eq_tol(logl(6.28), s21_log(6.28), 6);
  ck_assert_ldouble_eq_tol(logl(2.2343), s21_log(2.2343), 6);
  ck_assert_ldouble_eq_tol(logl(0.1234), s21_log(0.1234), 6);
}
END_TEST

START_TEST(atan_tests) {
  ck_assert_double_nan(s21_atan(S21_M_NAN));
  ck_assert_ldouble_eq_tol(atanl(+0), s21_atan(+0), 6);
  ck_assert_ldouble_eq_tol(atanl(-0), s21_atan(-0), 6);
  ck_assert_ldouble_eq_tol(atanl(S21_M_INF), s21_atan(S21_M_INF), 6);
  ck_assert_ldouble_eq_tol(atanl(-S21_M_INF), s21_atan(-S21_M_INF), 6);
  ck_assert_ldouble_eq_tol(atanl(100), s21_atan(100), 6);
  ck_assert_ldouble_eq_tol(atanl(-5.1), s21_atan(-5.1), 6);
  ck_assert_ldouble_eq_tol(atanl(-2.0), s21_atan(-2.0), 6);
  ck_assert_ldouble_eq_tol(atanl(3.0), s21_atan(3.0), 6);
  ck_assert_ldouble_eq_tol(atanl(1.0), s21_atan(1.0), 6);
  ck_assert_ldouble_eq_tol(atanl(0.0), s21_atan(0.0), 6);
  ck_assert_ldouble_eq_tol(atanl((int)S21_M_INF), s21_atan((int)S21_M_INF), 6);
  ck_assert_ldouble_eq_tol(atanl(5), s21_atan(5), 6);
  ck_assert_ldouble_eq_tol(atanl(0.000001), s21_atan(0.000001), 6);
  ck_assert_ldouble_eq_tol(atanl(-2), s21_atan(-2), 6);
  ck_assert_ldouble_eq_tol(atanl(0.0), s21_atan(0.0), 6);
  ck_assert_ldouble_eq_tol(atanl(-1.0), s21_atan(-1.0), 6);
  ck_assert_ldouble_eq_tol(atanl(S21_M_PI / 2), s21_atan(S21_M_PI / 2), 6);
}
END_TEST

START_TEST(asin_tests) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.0), asinl(-0.0), 6);
  ck_assert_ldouble_eq_tol(s21_asin(0.0), asinl(0.0), 6);
  ck_assert_ldouble_eq_tol(s21_asin(0.000005), asinl(0.000005), 6);
  ck_assert_ldouble_eq_tol(s21_asin(1.0), asinl(1.0), 6);
  ck_assert_ldouble_eq_tol(s21_asin(-1.0), asinl(-1.0), 6);
  ck_assert_int_eq(asinl(-13.54), s21_asin(-13.54));
  ck_assert_int_eq(asinl(13.54), s21_asin(13.54));
  ck_assert_int_eq(asinl(6.28), s21_asin(6.28));
  ck_assert_ldouble_eq_tol(asinl(0.000001), s21_asin(0.000001), 6);
  ck_assert_double_finite(asinl(S21_M_INF) == s21_asin(S21_M_INF));
  ck_assert_double_finite(asinl(S21_M_NAN) == s21_asin(S21_M_NAN));
  ck_assert_ldouble_eq_tol(asinl(-0.0 / 1.0), s21_asin(-0.0 / 1.0), 6);
  ck_assert_ldouble_eq_tol(asinl(0.1234), s21_asin(0.1234), 6);
  ck_assert_ldouble_eq_tol(asinl(0), s21_asin(0), 6);
  ck_assert_ldouble_eq_tol(asinl(1), s21_asin(1), 6);
  ck_assert_ldouble_eq_tol(asinl(-1), s21_asin(-1), 6);
  ck_assert_ldouble_eq_tol(asinl(0.5), s21_asin(0.5), 6);
  ck_assert_ldouble_eq_tol(asinl(-0.5), s21_asin(-0.5), 6);
}
END_TEST

START_TEST(acos_tests) {
  ck_assert_ldouble_eq_tol(acosl(1.0), s21_acos(1.0), 6);
  ck_assert_ldouble_eq_tol(acosl(0.0), s21_acos(0.0), 6);
  ck_assert_int_eq(acosl((int)S21_M_INF), s21_acos((int)S21_M_INF));
  ck_assert_int_eq(acosl(-13.54), s21_acos(-13.54));
  ck_assert_int_eq(acosl(13.54), s21_acos(13.54));
  ck_assert_int_eq(acosl(2.2343), s21_acos(2.2343));
  ck_assert_ldouble_eq_tol(acosl(0.1234), s21_acos(0.1234), 6);
  ck_assert_ldouble_eq_tol(acosl(0), s21_acos(0), 6);
  ck_assert_ldouble_eq_tol(acosl(1), s21_acos(1), 6);
  ck_assert_ldouble_eq_tol(acosl(-1), s21_acos(-1), 6);
  ck_assert_ldouble_eq_tol(acosl(0.5), s21_acos(0.5), 6);
  ck_assert_ldouble_eq_tol(acosl(-0.5), s21_acos(-0.5), 6);
}
END_TEST

Suite *s21_math_tests_create() {
  Suite *s21_math = suite_create("s21_math");
  TCase *s21_math_tests = tcase_create("S21_MATH");
  tcase_add_test(s21_math_tests, ceil_tests);
  tcase_add_test(s21_math_tests, floor_tests);
  tcase_add_test(s21_math_tests, exp_tests);
  tcase_add_test(s21_math_tests, sin_tests);
  tcase_add_test(s21_math_tests, cos_tests);
  tcase_add_test(s21_math_tests, tan_tests);
  tcase_add_test(s21_math_tests, abs_tests);
  tcase_add_test(s21_math_tests, fabs_tests);
  tcase_add_test(s21_math_tests, fmod_tests);
  tcase_add_test(s21_math_tests, pow_tests);
  tcase_add_test(s21_math_tests, sqrt_tests);
  tcase_add_test(s21_math_tests, log_tests);
  tcase_add_test(s21_math_tests, asin_tests);
  tcase_add_test(s21_math_tests, acos_tests);
  tcase_add_test(s21_math_tests, atan_tests);
  suite_add_tcase(s21_math, s21_math_tests);
  return s21_math;
}

int main() {
  Suite *s21_math = s21_math_tests_create();
  SRunner *s21_math_runner = srunner_create(s21_math);
  float number_failed;
  srunner_run_all(s21_math_runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(s21_math_runner);
  srunner_free(s21_math_runner);

  return number_failed == 0 ? 0 : 1;
}
