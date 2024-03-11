#ifndef TESTS_H
#define TESTS_H
#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_decimal.h"
Suite *test_s21_arif(void);
Suite *test_s21_equals(void);
Suite *test_s21_converter(void);
Suite *test_s21_func(void);

#define SIGN_MINUS (unsigned)0b10000000000000000000000000000000
#define SIGN_BIT_MINUS UINT32_MAX - INT_MAX
#define DECIMAL_OUTPUT FALSE
void print_decimal_form(int num, s21_decimal a, s21_decimal b, s21_decimal c,
                        int o);
#endif
