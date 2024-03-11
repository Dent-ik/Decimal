#include "s21_decimal.h"

void whole_part_div(s21_decimal *, s21_decimal, s21_decimal *);

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_decimal temp2 = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(10, &temp2);
  s21_decimal res = {{0, 0, 0, 0}};
  int sign_1 = get_sign(value_1), sign_2 = get_sign(value_2);
  int res_scale = get_scale(value_1) - get_scale(value_2);
  value_2.bits[3] = 0;
  value_1.bits[3] = 0;
  if (value_2.bits[0] == 0 && value_2.bits[1] == 0 && value_2.bits[2] == 0) {
    return 3;
  } else if (value_2.bits[0] == 1 && value_2.bits[1] == 0 &&
             value_2.bits[2] == 0) {
    value_1.bits[3] = 0;
    res = value_1;
    if (sign_1 != sign_2) {
      res.bits[3] |= MINUS;
    } else {
      res.bits[3] &= ~MINUS;
    }
    if (res_scale != 0) {
      if (res_scale > 28) {
        return 2;
      }
      while (res.bits[2] < 429496729 && res_scale < 0) {
        s21_mul(res, temp2, &res);
        res.bits[3] = 0;
        res_scale++;
      }
      if (res_scale < 0) {
        return 1;
      }
      res.bits[3] = res.bits[3] + (res_scale << 16);
    }
    *result = res;
    return 0;
  }
  whole_part_div(&value_1, value_2, &res);

  if (sign_1 != sign_2) {
    res.bits[3] |= MINUS;
  } else {
    res.bits[3] &= ~MINUS;
  }
  if (res_scale != 0) {
    if (res_scale > 28 || (res_scale == 28 && res.bits[0] == 0 &&
                           res.bits[1] == 0 && res.bits[2] == 0)) {
      return 2;
    }
  }
  *result = res;
  return 0;
}

void whole_part_div(s21_decimal *value_1, s21_decimal value_2,
                    s21_decimal *temp) {
  s21_decimal one = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(1, &one);
  while (s21_is_greater_or_equal(*value_1, value_2)) {
    s21_decimal value_2_pow = value_2;
    s21_decimal counter = {{0, 0, 0, 0}};
    while (s21_is_greater_or_equal(*value_1, value_2_pow)) {
      s21_add(counter, one, &counter);

      value_2_pow.bits[3] = 28 << 16;
      s21_mul(value_2_pow, value_2, &value_2_pow);
      // printf("error%d",error);
      value_2_pow.bits[3] = 0;
    }
    value_2_pow.bits[3] = 0;
    if (counter.bits[0] != 0 || counter.bits[1] != 0 || counter.bits[2] != 0) {
      s21_sub(counter, one, &counter);
    }
    if (counter.bits[0] != 0 || counter.bits[1] != 0 || counter.bits[2] != 0) {
    } else if (s21_is_not_equal(value_2_pow, value_2)) {
      s21_add(*temp, one, temp);
      s21_sub(*value_1, value_2, value_1);
    }
  }
}
