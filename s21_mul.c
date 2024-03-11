#include "s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int a = 0;
  s21_big_decimal big1 = {{0, 0, 0, 0, 0, 0, 0}};
  s21_from_dec_to_big(value_1, &big1);

  s21_big_decimal big2 = {{0, 0, 0, 0, 0, 0, 0}};
  s21_from_dec_to_big(value_2, &big2);
  big2.bits[7] = 0;
  s21_big_decimal res = {{0, 0, 0, 0, 0, 0, 0}};
  if (zero(&value_1) == 0 && zero(&value_2) == 0) {
    for (int i = 0; i < 96; i++) {  // идем по всей мантиссе

      if (big_get_bit(big1, i)) {
        s21_big_add_simple(res, big2, &res);
      }

      big_shift_left(&big2, 1);
    }

    int scale = (get_scale(value_1) + get_scale(value_2));
    big_set_sign(&res, ((get_sign(value_1) + get_sign(value_2)) % 2));

    big_set_scale(&res, scale);
    a = s21_from_big_to_dec(res, result);
  }

  return a;
}
