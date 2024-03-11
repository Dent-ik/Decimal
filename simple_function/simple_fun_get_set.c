#include "../s21_decimal.h"

int get_bit(s21_decimal number, int index_bit) {
  int bit;
  if ((number.bits[index_bit / 32] & (1 << index_bit % 32)) == 0) {
    bit = 0;
  } else {
    bit = 1;
  }
  return bit;
}

int get_sign(s21_decimal number) {
  int sign;
  if ((number.bits[3] & (1 << 31)) == 0) {
    sign = 0;  // число положительное
  } else {
    sign = 1;  // число отрицательное
  }
  return sign;
}

int get_scale(s21_decimal number) {
  int shift = 16;
  int scale = 0;
  int i = 0;
  while (shift <= 23) {
    int bit = 0;
    if ((number.bits[3] & (1 << shift)) != 0) {
      bit = 1;
    }
    scale = scale + (bit * pow(2, i));
    shift++;
    i++;
  }
  return scale;
}

int set_sign(s21_decimal* number, int sign) {
  if (sign == 1) {
    number->bits[3] = number->bits[3] | (1 << 31);

  } else {
    number->bits[3] = number->bits[3] & ~(1 << 31);
  }
  return 0;
}
int set_scale(s21_decimal* number, int scale) {
  number->bits[3] &= MINUS;
  number->bits[3] |= (scale << 16) & SCALE;
  return 0;
}
