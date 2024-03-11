#include "../s21_decimal.h"

void notation_2(unsigned int x) {
  char str[32];
  for (int i = 0; i < 32; i++) {
    str[i] = x % 2 + '0';
    x /= 2;
  }
  printf("[ ");
  for (int i = 0; i < 32; i++) printf("%c", str[31 - i]);
  printf(" ]\n");
}
void print_decimal(s21_decimal dst) {
  printf("bits\t%5d%25d\n", 10, 2);
  for (int i = 0; i < 4; i++) {
    printf("[%d] = [%10u]", i, dst.bits[i]);
    notation_2(dst.bits[i]);
  }
}
