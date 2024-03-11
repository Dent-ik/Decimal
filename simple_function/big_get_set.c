#include "../s21_decimal.h"

int big_get_bit(s21_big_decimal number, int index_bit) {
  int bit;
  if ((number.bits[index_bit / 32] & (1 << index_bit % 32)) == 0) {
    bit = 0;
  } else {
    bit = 1;
  }
  return bit;
}

int big_get_sign(s21_big_decimal number) {
  int sign;
  if ((number.bits[7] & (1 << 31)) == 0) {
    sign = 0;  // число положительное
  } else {
    sign = 1;  // число отрицательное
  }
  return sign;
}

int big_get_scale(s21_big_decimal number) {
  int shift = 16;
  int scale = 0;
  int i = 0;
  while (shift <= 23) {
    int bit = 0;
    if ((number.bits[7] & (1 << shift)) != 0) {
      bit = 1;
    }
    scale = scale + (bit * pow(2, i));
    shift++;
    i++;
  }
  return scale;
}

int big_set_bit(s21_big_decimal* number, int index_bit, int bit) {
  if (bit == 1) {
    number->bits[index_bit / 32] =
        number->bits[index_bit / 32] | (1 << index_bit % 32);
  }
  if (bit == 0) {
    number->bits[index_bit / 32] =
        number->bits[index_bit / 32] & (~(1 << index_bit % 32));
  }

  return 0;
}

int big_set_sign(s21_big_decimal* number, int sign) {
  if (sign == 1) {
    number->bits[7] = number->bits[7] | (1 << 31);

  } else {
    number->bits[7] = number->bits[7] & ~(1 << 31);
  }
  return 0;
}

int big_set_scale(s21_big_decimal* number, int scale) {
  int sign = big_get_sign(*number);
  number->bits[7] = 0;
  scale = scale << 16;

  number->bits[7] = scale | number->bits[7];
  if (sign != 0) {
    big_set_sign(number, sign);
  }
  return 0;
}
int zero(s21_decimal* res) {
  int k = 0;

  if (res->bits[2] == 0 && res->bits[1] == 0 && res->bits[0] == 0) {
    res->bits[3] = 0;
    k = 1;
  }
  return k;
}
