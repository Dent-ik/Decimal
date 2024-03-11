#include "../s21_decimal.h"

void shift_left(s21_decimal* number, int shift_value) {
  unsigned memory = 0;
  for (int i = 0; i < (int)(sizeof(s21_decimal) / sizeof(unsigned) - 1); ++i) {
    unsigned temp = number->bits[i];
    number->bits[i] <<= shift_value;
    number->bits[i] |= memory;
    memory = temp >> (32 - shift_value);
  }
}
