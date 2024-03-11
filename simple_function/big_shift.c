#include "../s21_decimal.h"

int big_shift_left(s21_big_decimal* number, int shift_value) {
  if (shift_value != 0) {
    unsigned memory = 0;
    for (int i = 0; i < (int)(sizeof(s21_big_decimal) / sizeof(unsigned) - 1);
         ++i) {
      unsigned temp = number->bits[i];
      number->bits[i] <<= shift_value;
      number->bits[i] |= memory;
      memory = temp >> (32 - shift_value);
    }
  }
  return 0;
}
