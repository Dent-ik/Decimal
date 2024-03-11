#include "../s21_decimal.h"

int s21_big_add_simple(s21_big_decimal decimal_1, s21_big_decimal decimal_2,
                       s21_big_decimal* res) {
  int memory = 0;
  int num_result;
  res->bits[7] = decimal_1.bits[7];
  res->bits[6] = 0;
  res->bits[5] = 0;
  res->bits[4] = 0;
  res->bits[3] = 0;
  res->bits[2] = 0;
  res->bits[1] = 0;
  res->bits[0] = 0;
  for (int i = 0; i < 224; i++) {
    int bit_decimal_1 = big_get_bit(decimal_1, i);
    int bit_decimal_2 = big_get_bit(decimal_2, i);
    num_result = bit_decimal_1 + bit_decimal_2 + memory;

    memory = num_result / 2;

    if (num_result) {
      big_set_bit(res, i, num_result % 2);
    }
  }

  return 0;
}
