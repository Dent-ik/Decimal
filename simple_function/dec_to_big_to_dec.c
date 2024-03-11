#include "../s21_decimal.h"

int s21_from_dec_to_big(s21_decimal number, s21_big_decimal *result) {
  result->bits[7] = number.bits[3];
  result->bits[0] = number.bits[0];
  result->bits[1] = number.bits[1];
  result->bits[2] = number.bits[2];
  return 0;
}

int s21_from_big_to_dec(s21_big_decimal number, s21_decimal *result) {
  int res = 0;
  int zero = 0;
  int okrugl = 0;
  int k = 0;

  while (big_get_scale(number) > 28) {
    if (number.bits[0] == 0 && number.bits[1] == 0 && number.bits[2] == 0 &&
        number.bits[3] == 0 && number.bits[4] == 0 && number.bits[5] == 0 &&
        number.bits[6] == 0) {
      res = 2;

      break;
    } else {
      zero = div_simple_ten(&number);
      okrugl = zero + okrugl;
      k++;
    }
  }

  while ((number.bits[3] > 0 || number.bits[4] > 0 || number.bits[5] > 0 ||
          number.bits[6] > 0)) {
    if (big_get_scale(number) > 0) {
      zero = div_simple_ten(&number);
      okrugl = zero + okrugl;
      k++;
    }

    else {
      if (big_get_sign(number) == 1) {
        res = 2;
      } else {
        res = 1;
      }

      break;
    }
  }

  s21_big_decimal bank = {{1, 0, 0, 0, 0, 0, 0, 0}};

  if ((zero > 5 || (zero == 5 && okrugl > zero))) {
    s21_big_add_simple(number, bank, &number);
  }
  if (zero == 5 && okrugl == zero && number.bits[0] % 2 == 1 &&
      big_get_sign(number) == 0) {
    s21_big_add_simple(number, bank, &number);
  }

  if (number.bits[3] == 0 && number.bits[4] == 0 && number.bits[5] == 0 &&
      number.bits[6] == 0 && res == 0) {
    result->bits[3] = number.bits[7];
    result->bits[0] = number.bits[0];
    result->bits[1] = number.bits[1];
    result->bits[2] = number.bits[2];
    res = 0;
  }
  if ((number.bits[3] > 0 || number.bits[4] > 0 || number.bits[5] > 0 ||
       number.bits[6] > 0) &&
      big_get_scale(number) == 0 && big_get_sign(number) == 0) {
    res = 1;
  }
  if ((number.bits[3] > 0 || number.bits[4] > 0 || number.bits[5] > 0 ||
       number.bits[6] > 0) &&
      big_get_scale(number) == 0 && big_get_sign(number) == 1) {
    res = 2;
  }

  return res;
}
