#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int a = 0;
  if (get_sign(value_1) == get_sign(value_2)) {
    s21_big_decimal big1 = {{0, 0, 0, 0, 0, 0, 0}};
    s21_from_dec_to_big(value_1, &big1);

    s21_big_decimal big2 = {{0, 0, 0, 0, 0, 0, 0}};
    s21_from_dec_to_big(value_2, &big2);

    s21_big_decimal res = {{0, 0, 0, 0, 0, 0, 0}};

    if (get_scale(value_1) != get_scale(value_2)) {
      big_normalize(&big1, &big2);
    }

    int memory = 0;
    int num_result;
    res.bits[7] = big1.bits[7];

    for (int i = 0; i < 224; i++) {  // идем по всей мантиссе
      int bit_decimal_1 = big_get_bit(big1, i);
      int bit_decimal_2 = big_get_bit(big2, i);

      num_result = bit_decimal_1 + bit_decimal_2 + memory;

      memory = num_result / 2;

      if (num_result) {
        big_set_bit(&res, i, num_result % 2);
      }
    }

    a = s21_from_big_to_dec(res, result);

  } else {
    if (s21_is_greater(value_1, value_2)) {
      set_sign(&value_2, get_sign(value_1));
      a = s21_sub(value_1, value_2, result);
    } else {
      set_sign(&value_1, get_sign(value_2));
      a = s21_sub(value_2, value_1, result);
    }
  }
  return a;
}
