#include <string.h>

#include "s21_decimal.h"

#define DEC_MAX 79228162514264337593543950335.0
#define DEC_MIN 1.0e-28

int str_to_int(char *str, int len) {
  int res = 0;
  int not = 10;
  int sign = 1;
  if (*str == '-') {
    sign = -1;
    str++;
  } else if (*str == '+')
    str++;
  for (int i = 0; i < len; i++, str++)
    if (*str != '.') res = res * not +(*str - 48);
  return res * sign;
}

void pow_ten(s21_decimal *num, int power) {
  s21_decimal res = {0};
  while (power > 0) {
    s21_decimal a = *num;
    shift_left(&a, 3);
    s21_decimal b = *num;
    shift_left(&b, 1);
    s21_add_simple(a, b, &res);
    *num = res;
    power--;
  }
}

long double s21_from_decimal_to_ld(s21_decimal src) {
  long double res = 0;
  for (int i = 0; i < 96; i++) {
    res += get_bit(src, i) * pow(2, i);
  }
  int scale = get_scale(src);
  while (scale > 0) {
    res /= 10;
    scale--;
  }
  if (get_sign(src)) res = -res;
  return res;
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int ok = 1;
  dst->bits[0] = 0;
  dst->bits[1] = 0;
  dst->bits[2] = 0;
  dst->bits[3] = 0;
  if (src <= INT_MAX && src >= INT_MIN) {
    if (src < 0) {
      set_sign(dst, 1);
      src = -src;
    }
    dst->bits[0] = src;
    ok = 0;
  }
  return ok;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int ok = 0;
  *dst = 0;
  long double res = s21_from_decimal_to_ld(src);
  if (res > INT_MAX || res < INT_MIN)
    ok = 1;
  else
    *dst = res;
  return ok;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int ok = 1;
  dst->bits[0] = 0;
  dst->bits[1] = 0;
  dst->bits[2] = 0;
  dst->bits[3] = 0;
  if (fabs(src) <= DEC_MAX && fabs(src) >= DEC_MIN) {
    if (src < 0) {
      set_sign(dst, 1);
      src = -src;
    }
    char *float_to_str = (char *)malloc(13);
    sprintf(float_to_str, "%e", fabs(src));
    int scale = str_to_int(float_to_str + 9, strlen(float_to_str) - 10) - 6;
    int num = str_to_int(float_to_str, strlen(float_to_str) - 4);
    if (scale < 0) {
      while (scale < 0 && !(num % 10)) {
        scale++;
        num = num / 10;
      }
      if (scale < -28) {
        long double res = num * pow(10, scale + 28);
        num = round(res);
        scale = -28;
      }
      dst->bits[0] = num;
      set_scale(dst, -scale);
    } else {
      dst->bits[0] = num;
      pow_ten(dst, scale);
    }
    free(float_to_str);
    ok = 0;
  }
  return ok;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  *dst = s21_from_decimal_to_ld(src);
  return 0;
}
