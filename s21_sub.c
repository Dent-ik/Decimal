#include "s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int a = 0;
  int k1 = get_sign(value_1);
  int k2 = get_sign(value_2);
  if (k1 != k2) {
    set_sign(&value_2, get_sign(value_1));

    a = s21_add(value_1, value_2, result);
  } else {
    char memory = 0;
    s21_big_decimal big = {{0, 0, 0, 0, 0, 0, 0}};
    s21_big_decimal small = {{0, 0, 0, 0, 0, 0, 0}};
    s21_big_decimal res = {{0, 0, 0, 0, 0, 0, 0}};

    int bit_big;
    int bit_small;
    set_sign(&value_1, 0);
    set_sign(&value_2, 0);
    if (s21_is_equal(value_1, value_2) == 0) {
      if (s21_is_greater(value_1, value_2)) {
        s21_from_dec_to_big(value_1, &big);
        if (k2 == 1) {
          big_set_sign(&res, 1);
        }
        s21_from_dec_to_big(value_2, &small);

      } else {
        s21_from_dec_to_big(value_2, &big);
        s21_from_dec_to_big(value_1, &small);
        if (k2 == 0) {
          big_set_sign(&res, 1);
        }
      }
      if (get_scale(value_1) != get_scale(value_2)) {
        big_normalize(&big, &small);
      }

      big_set_scale(&res, big_get_scale(big));
      for (int i = 0; i < 224; i++) {
        bit_big = big_get_bit(big, i);
        bit_small = big_get_bit(small, i);
        if (bit_big == 0 && bit_small == 1 && !memory) {
          memory = 1;
          res.bits[i / 32] += (int)pow(2, i % 32);
        } else if ((bit_big == 1 && bit_small == 1 && memory) ||
                   (bit_big == 1 && bit_small == 0 && !memory) ||
                   (bit_big == 0 && bit_small == 0 && memory)) {
          res.bits[i / 32] += (int)pow(2, i % 32);
        } else if (bit_big == 1 && bit_small == 0 && memory) {
          memory = 0;
        }
      }
    }
    a = s21_from_big_to_dec(res, result);
    zero(result);
  }
  return a;
}
