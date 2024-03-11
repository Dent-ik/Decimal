#include "s21_decimal.h"

void dec_to_zero(s21_decimal* number) {
  for (int i = 4; i > -1; i--) {
    number->bits[i] = 0;
  }
}

int s21_negate(s21_decimal value, s21_decimal* result) {
  int k = 0;
  if (get_scale(value) > 28) {
    k = 1;
  } else {
    int sign_curr = get_sign(value);
    if (sign_curr == 1) {
      value.bits[3] &= ~MINUS;
    } else
      value.bits[3] |= MINUS;
    *result = value;
  }
  return k;
}

int s21_truncate(s21_decimal value, s21_decimal* result) {
  int k = 0;
  if (get_scale(value) > 28) {
    k = 1;
  } else {
    dec_to_zero(result);
    s21_big_decimal big = {0};
    int scale = get_scale(value);
    s21_from_dec_to_big(value, &big);
    while (scale > 0) {
      div_simple_ten(&big);
      *result = value;
      scale--;
    }
    s21_from_big_to_dec(big, result);
  }
  return k;
}

int s21_round(s21_decimal value, s21_decimal* result) {
  int k = 0;
  if (get_scale(value) > 28) {
    k = 1;
  } else {
    int scale = get_scale(value);
    s21_big_decimal big = {0};
    s21_from_dec_to_big(value, &big);
    int zero = 0;
    int okrugl = 0;
    while (scale > 0) {
      scale--;
      zero = div_simple_ten(&big);
      okrugl = zero + okrugl;
    }
    s21_big_decimal bank = {{1, 0, 0, 0, 0, 0, 0, 0}};

    if ((zero > 5 || (zero == 5 && okrugl > zero))) {
      s21_big_add_simple(big, bank, &big);
    }
    if (zero == 5 && okrugl == zero && big.bits[0] % 2 == 1 &&
        big_get_sign(big) == 0) {
      s21_big_add_simple(big, bank, &big);
    }

    s21_from_big_to_dec(big, result);
  }
  return k;
}

int s21_floor(s21_decimal value, s21_decimal* result) {
  int k = 0;
  if (get_scale(value) > 28) {
    k = 1;
  } else {
    int sign = get_sign(value);
    if (sign == 0) {
      s21_truncate(value, result);
    } else {
      s21_truncate(value, result);
      result->bits[0] += 1;
    }
    set_sign(result, sign);
  }
  return k;
}
