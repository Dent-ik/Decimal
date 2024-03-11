#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MINUS 0x80000000     // 10000000 00000000 00000000 00000000
#define SCALE 0x00ff0000     // 00000000 11111111 00000000 00000000
#define MAX4BITE 0xffffffff  // 11111111 11111111 11111111 11111111
#define MASK 0xf0000000      // 11110000 00000000 00000000 00000000
#define MIN4BITE 0x00000000

enum enum_error {
  OK = 0,
  FALSE = 0,
  NUMBER_INF = 1,
  TRUE = 1,
  ERROR_CONVERT = 1,
  NUMBER_MIN_INF = 2,
  DEV_BY_ZERO = 3
};

typedef struct {
  unsigned int bits[4];  // unsigned??
} s21_decimal;

typedef struct {
  unsigned int bits[8];  // unsigned??
} s21_big_decimal;
void notation_2(unsigned int x);
void print_decimal(s21_decimal dst);
// служебные функции
int zero(s21_decimal* res);
int get_sign(s21_decimal number);
int big_get_sign(s21_big_decimal number);
int set_sign(s21_decimal* number, int sign);
int big_set_sign(s21_big_decimal* number, int sign);
int get_scale(s21_decimal number);
int big_get_scale(s21_big_decimal number);
int set_scale(s21_decimal* number, int scale);
int big_set_scale(s21_big_decimal* number, int scale);
int get_bit(s21_decimal number, int index_bit);
int big_get_bit(s21_big_decimal number, int index_bit);
int set_bit(s21_decimal* number, int index_bit, int bit);
int big_set_bit(s21_big_decimal* number, int index_bit, int bit);
void shift_left(s21_decimal* number, int shift_value);
int shift_right(s21_decimal* number, int shift_value);
int big_shift_left(s21_big_decimal* number, int shift_value);
int s21_add_simple(s21_decimal decimal_1, s21_decimal decimal_2,
                   s21_decimal* res);
int s21_big_add_simple(s21_big_decimal decimal_1, s21_big_decimal decimal_2,
                       s21_big_decimal* res);
void normalize(s21_decimal* decimal_1, s21_decimal* decimal_2);
void big_normalize(s21_big_decimal* decimal_1, s21_big_decimal* decimal_2);
int s21_from_dec_to_big(s21_decimal number, s21_big_decimal* result);
int s21_from_big_to_dec(s21_big_decimal number, s21_decimal* result);
int div_simple_ten(s21_big_decimal* value);
// служебные функции

int s21_negate(s21_decimal value,
               s21_decimal* result);  // Возвращает результат умножения
                                      // указанного Decimal на -1.
int s21_truncate(s21_decimal value,
                 s21_decimal* result);  // Возвращает целые цифры указанного
                                        //  Decimal числа; любые дробные цифры
                                        // отбрасываются, включая конечные нули.
int s21_floor(s21_decimal value,
              s21_decimal* result);  // Округляет указанное Decimal число до
                                     // ближайшего целого числа в сторону
                                     // отрицательной бесконечности.
int s21_round(
    s21_decimal value,
    s21_decimal* result);  // Округляет Decimal до ближайшего целого числа.

int s21_from_int_to_decimal(int src, s21_decimal* dst);  // Преобразователь
int s21_from_decimal_to_int(s21_decimal src, int* dst);  // Преобразователь
int s21_from_float_to_decimal(float src, s21_decimal* dst);  // Преобразователь
int s21_from_decimal_to_float(s21_decimal src, float* dst);  // Преобразователь

int s21_add(s21_decimal value_1, s21_decimal value_2,
            s21_decimal* result);  // Сложение
int s21_sub(s21_decimal value_1, s21_decimal value_2,
            s21_decimal* result);  // Вычитание
int s21_mul(s21_decimal value_1, s21_decimal value_2,
            s21_decimal* result);  // Умножение
int s21_div(s21_decimal value_1, s21_decimal value_2,
            s21_decimal* result);  // Деление

int s21_is_less(s21_decimal value_1, s21_decimal value_2);  // меньше
int s21_is_less_or_equal(s21_decimal value_1,
                         s21_decimal value_2);  // меньше или равно
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);  // больше
int s21_is_greater_or_equal(s21_decimal value_1,
                            s21_decimal value_2);  // больше или равно
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);  // равно
int s21_is_not_equal(s21_decimal value_1,
                     s21_decimal value_2);  // неравно

#endif
