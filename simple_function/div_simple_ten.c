#include "../s21_decimal.h"

int div_simple_ten(s21_big_decimal *value) {
  unsigned long long int num, max35;
  unsigned long long int x = 8;
  max35 = 34359738368;
  unsigned long long int osthighbit = 0;
  unsigned long long int ostlowbit = 0;  // остаток

  osthighbit = value->bits[6] % 10;
  value->bits[6] =
      value->bits[6] / 10;  // остаток от деления на 10 старшего бита

  for (int i = 6; i > 0; i = i - 1) {  // идем по мантиссе со старших разрядов

    ostlowbit = value->bits[i - 1] % 10;  // остаток от деления на 10 шего бита

    value->bits[i - 1] = value->bits[i - 1] / 10;

    max35 = 4294967296;
    num = 0;
    x = 8;

    while (osthighbit > 0) {
      num = (osthighbit % 2) * max35 + num;
      osthighbit = osthighbit / 2;
      x = x / 2;

      max35 = max35 * 2;
    }
    max35 = 4294967296;

    ostlowbit = ostlowbit + num % 10;
    num = value->bits[i - 1] + num / 10 + ostlowbit / 10;

    if (num >= max35) {
      ++value->bits[i];
      num = num - max35;
    }
    value->bits[i - 1] = num;
    osthighbit = ostlowbit % 10;
  }

  big_set_scale(value, big_get_scale(*value) - 1);
  return osthighbit;
}
