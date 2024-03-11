#include "../s21_decimal.h"

int s21_add_simple(s21_decimal decimal_1, s21_decimal decimal_2,
                   s21_decimal* res) {
  int memory = 0;
  int num_result;
  res->bits[3] = decimal_1.bits[3];
  res->bits[0] = 0;
  res->bits[1] = 0;
  res->bits[2] = 0;
  for (int i = 0; i < 96; i++) {  // идем по всей мантиссе
    int bit_decimal_1 = get_bit(decimal_1, i);
    int bit_decimal_2 = get_bit(decimal_2, i);

    num_result = bit_decimal_1 ^ bit_decimal_2 ^ memory;

    memory = (bit_decimal_1 && bit_decimal_2) || (bit_decimal_1 && memory) ||
             (bit_decimal_2 && memory);

    if (num_result) {
      res->bits[i / 32] += (int)pow(2, i % 32);
    }
  }

  return 0;
}
