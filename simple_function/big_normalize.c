#include "../s21_decimal.h"

void big_normalize(s21_big_decimal* decimal_1, s21_big_decimal* decimal_2) {
  int scale_decimal_1 = big_get_scale(*decimal_1);
  int scale_decimal_2 = big_get_scale(*decimal_2);
  int k = big_get_sign(*decimal_1);

  int k2 = big_get_sign(*decimal_2);

  int max_scale =
      (scale_decimal_1 > scale_decimal_2) ? scale_decimal_1 : scale_decimal_2;
  int min_scale =
      (scale_decimal_1 < scale_decimal_2) ? scale_decimal_1 : scale_decimal_2;
  s21_big_decimal res;

  if (min_scale == scale_decimal_1) {
    while (max_scale != min_scale) {
      s21_big_decimal a = *decimal_1;
      big_shift_left(&a, 3);
      s21_big_decimal b = *decimal_1;
      big_shift_left(&b, 1);
      s21_big_add_simple(a, b, &res);
      res.bits[7] = 0;
      *decimal_1 = res;

      min_scale += 1;
      big_set_scale(decimal_1, min_scale);
    }
  }
  if (min_scale == scale_decimal_2) {
    while (max_scale != min_scale) {
      s21_big_decimal a = *decimal_2;
      big_shift_left(&a, 3);
      s21_big_decimal b = *decimal_2;
      big_shift_left(&b, 1);
      s21_big_add_simple(a, b, &res);
      res.bits[7] = 0;
      *decimal_2 = res;
      big_set_scale(decimal_2, min_scale);
      min_scale += 1;
      big_set_scale(decimal_2, min_scale);
    }
  }
  big_set_sign(decimal_1, k);
  big_set_sign(decimal_2, k2);
}
