#include <limits.h>

#include "test.h"
void print_decimal_form(int num, s21_decimal a, s21_decimal b, s21_decimal c,
                        int o) {
  char s[200];
  printf("case num: %d\n", num);
  print_decimal(a);
  printf("\nvalue_1 : %s", s);
  print_decimal(b);
  printf("\nvalue_2 : %s", s);
  print_decimal(c);
  printf("\nresult  : %s", s);
  printf("\noverflow: ");
  o ? printf("YES") : printf("NO");
  puts("\n\n");
}

START_TEST(s21_mul_1) {
  s21_decimal value_1 = {{64, 64, 64, SIGN_BIT_MINUS}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
  if (DECIMAL_OUTPUT) print_decimal_form(1, value_1, value_2, result, error);
}
END_TEST

START_TEST(s21_mul_2) {
  s21_decimal value_1 = {{4, 8, 12, SIGN_BIT_MINUS}};
  s21_decimal value_2 = {{4, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 16);
  ck_assert_uint_eq(result.bits[1], 32);
  ck_assert_uint_eq(result.bits[2], 48);
  ck_assert_uint_eq(result.bits[3], SIGN_BIT_MINUS);
  if (DECIMAL_OUTPUT) print_decimal_form(2, value_1, value_2, result, error);
}
END_TEST

START_TEST(s21_mul_3) {
  s21_decimal value_1 = {{UINT32_MAX, UINT32_MAX >> 16, 0, 0}};
  s21_decimal value_2 = {{UINT32_MAX, UINT32_MAX >> 16, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 1);
  ck_assert_uint_eq(result.bits[1], UINT32_MAX << 17);
  ck_assert_uint_eq(result.bits[2], UINT32_MAX);
  ck_assert_uint_eq(result.bits[3], 0);
  if (DECIMAL_OUTPUT) print_decimal_form(3, value_1, value_2, result, error);
}
END_TEST

START_TEST(s21_mul_4) {
  s21_decimal value_1 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, SIGN_BIT_MINUS}};
  s21_decimal value_2 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(error, 2);
  ck_assert_uint_eq(result.bits[0], 0);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
  if (DECIMAL_OUTPUT) print_decimal_form(4, value_1, value_2, result, error);
}
END_TEST

START_TEST(s21_mul_6) {
  s21_decimal value_1 = {{13, 0, 0, 28 << 16}};
  s21_decimal value_2 = {{13, 0, 0, 1 << 16}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);
  if (DECIMAL_OUTPUT) print_decimal_form(6, value_1, value_2, result, error);
  ck_assert_uint_eq(error, 0);
  ck_assert_uint_eq(result.bits[0], 17);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 28 << 16);
}
END_TEST

START_TEST(s21_mul_7) {
  s21_decimal value_1 = {{15, 0, 0, 28 << 16}};
  s21_decimal value_2 = {{5, 0, 0, 1 << 16}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);
  if (DECIMAL_OUTPUT) print_decimal_form(7, value_1, value_2, result, error);
  ck_assert_uint_eq(error, 0);
  ck_assert_uint_eq(result.bits[0], 8);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 28 << 16);
}
END_TEST

START_TEST(s21_mul_8) {
  s21_decimal value_1 = {{25, 0, 0, 28 << 16}};
  s21_decimal value_2 = {{25, 0, 0, 1 << 16}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);
  if (DECIMAL_OUTPUT) print_decimal_form(8, value_1, value_2, result, error);
  ck_assert_uint_eq(error, 0);
  ck_assert_uint_eq(result.bits[0], 62);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 28 << 16);
}
END_TEST

START_TEST(s21_mul_9) {
  s21_decimal value_1 = {{UINT32_MAX, UINT32_MAX >> 15, 0, 0}};
  s21_decimal value_2 = {{UINT32_MAX, UINT32_MAX >> 16, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(error, 1);
  ck_assert_uint_eq(result.bits[0], 0);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
  if (DECIMAL_OUTPUT) print_decimal_form(9, value_1, value_2, result, error);
}
END_TEST
START_TEST(s21_mul_10) {
  s21_decimal value_1 = {{1, 1, 1, 10 << 16}};
  s21_decimal value_2 = {{2343453, 0, 0, SIGN_MINUS | 7 << 16}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b00000000001000111100001000011101);
  ck_assert_uint_eq(result.bits[1], 0b00000000001000111100001000011101);
  ck_assert_uint_eq(result.bits[2], 0b1000111100001000011101);
  ck_assert_uint_eq(result.bits[3], SIGN_MINUS | 17 << 16);
  if (DECIMAL_OUTPUT) print_decimal_form(10, value_1, value_2, result, error);
}
END_TEST
START_TEST(s21_mul_11) {
  s21_decimal value_1 = {{1, 1, 1, SIGN_MINUS | 10 << 16}};
  s21_decimal value_2 = {{2343453, 0, 0, SIGN_MINUS | 7 << 16}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);
  if (DECIMAL_OUTPUT) print_decimal_form(11, value_1, value_2, result, error);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b00000000001000111100001000011101);
  ck_assert_uint_eq(result.bits[1], 0b00000000001000111100001000011101);
  ck_assert_uint_eq(result.bits[2], 0b1000111100001000011101);
  ck_assert_uint_eq(result.bits[3], 17 << 16);
}
END_TEST
START_TEST(s21_mul_12) {
  s21_decimal value_1 = {{1, 1, 1, 10 << 16}};
  s21_decimal value_2 = {{133456435, 0, 0, SIGN_MINUS}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b00000111111101000110001000110011);
  ck_assert_uint_eq(result.bits[1], 0b00000111111101000110001000110011);
  ck_assert_uint_eq(result.bits[2], 0b111111101000110001000110011);
  ck_assert_uint_eq(result.bits[3], SIGN_MINUS | 10 << 16);
  if (DECIMAL_OUTPUT) print_decimal_form(12, value_1, value_2, result, error);
}
END_TEST
START_TEST(s21_mul_13) {
  s21_decimal value_2 = {{10, 0, 0, 0}};
  s21_decimal value_1 = {{1, 1, 1, 10 << 16}};

  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 10);
  ck_assert_uint_eq(result.bits[1], 10);
  ck_assert_uint_eq(result.bits[2], 10);
  ck_assert_uint_eq(result.bits[3], 10 << 16);
  if (DECIMAL_OUTPUT) print_decimal_form(13, value_1, value_2, result, error);
}
END_TEST
START_TEST(s21_mul_14) {
  s21_decimal value_1 = {{1, 1, 1, 10 << 16}};

  s21_decimal value_2 = {{0b11, 0b10, 1, 8 << 16}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);

  if (DECIMAL_OUTPUT) print_decimal_form(14, value_1, value_2, result, error);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b00001011010100110101111100010100);
  ck_assert_uint_eq(result.bits[1], 0b10101000110100010110100100011000);
  ck_assert_uint_eq(result.bits[2], 0b1101101111100110111111101101000);
  ck_assert_uint_eq(result.bits[3], 8 << 16);
}
END_TEST
START_TEST(s21_mul_15) {
  s21_decimal value_1 = {{1, 1, 1, 10 << 16}};

  s21_decimal value_2 = {{1, 0, 0, 10 << 16}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);
  if (DECIMAL_OUTPUT) print_decimal_form(15, value_1, value_2, result, error);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 1);
  ck_assert_uint_eq(result.bits[1], 1);
  ck_assert_uint_eq(result.bits[2], 1);
  ck_assert_uint_eq(result.bits[3], 20 << 16);
}
END_TEST
START_TEST(s21_mul_16) {
  s21_decimal value_1 = {{1, 1, 1, 10 << 16}};

  s21_decimal value_2 = {{1, 0, 0, SIGN_MINUS | 10 << 16}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);
  if (DECIMAL_OUTPUT) print_decimal_form(16, value_1, value_2, result, error);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 1);
  ck_assert_uint_eq(result.bits[1], 1);
  ck_assert_uint_eq(result.bits[2], 1);
  ck_assert_uint_eq(result.bits[3], SIGN_MINUS | 20 << 16);
}
END_TEST
START_TEST(s21_mul_17) {
  s21_decimal value_1 = {{1, 1, 1, SIGN_MINUS | 10 << 16}};

  s21_decimal value_2 = {{5, 0, 0, SIGN_MINUS | 10 << 16}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);
  if (DECIMAL_OUTPUT) print_decimal_form(17, value_1, value_2, result, error);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b101);
  ck_assert_uint_eq(result.bits[1], 0b101);
  ck_assert_uint_eq(result.bits[2], 0b101);
  ck_assert_uint_eq(result.bits[3], 20 << 16);
}
END_TEST
START_TEST(s21_mul_18) {
  s21_decimal value_1 = {{0b01011110100110011000010001011010,
                          0b00001101101100010010101010111100,
                          0b11001111011101001001011100000111, 3 << 16}};
  s21_decimal value_2 = {{1234, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);
  if (DECIMAL_OUTPUT) print_decimal_form(18, value_1, value_2, result, error);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], UINT32_MAX - 1);
  ck_assert_uint_eq(result.bits[1], UINT32_MAX);
  ck_assert_uint_eq(result.bits[2], UINT32_MAX);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST
START_TEST(s21_mul_19) {
  s21_decimal value_1 = {{0b00110011001100110011001100110011,
                          0b00110011001100110011001100110011,
                          0b110011001100110011001100110011, 0}};
  s21_decimal value_2 = {{5, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);
  if (DECIMAL_OUTPUT) print_decimal_form(19, value_1, value_2, result, error);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], UINT32_MAX);
  ck_assert_uint_eq(result.bits[1], UINT32_MAX);
  ck_assert_uint_eq(result.bits[2], UINT32_MAX);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST
START_TEST(s21_mul_20) {
  s21_decimal value_1 = {{0b00110011001100110011001100110011,
                          0b00110011001100110011001100110011,
                          0b110011001100110011001100110011, 28 << 16}};
  s21_decimal value_2 = {{5, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);
  if (DECIMAL_OUTPUT) print_decimal_form(20, value_1, value_2, result, error);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], UINT32_MAX);
  ck_assert_uint_eq(result.bits[1], UINT32_MAX);
  ck_assert_uint_eq(result.bits[2], UINT32_MAX);
  ck_assert_uint_eq(result.bits[3], 28 << 16);
}
END_TEST
START_TEST(s21_mul_21) {
  s21_decimal value_1 = {{0b00110011001100110011001100110011,
                          0b00110011001100110011001100110011,
                          0b110011001100110011001100110011, 27 << 16}};
  s21_decimal value_2 = {{5, 0, 0, 1 << 16}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);
  if (DECIMAL_OUTPUT) print_decimal_form(21, value_1, value_2, result, error);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], UINT32_MAX);
  ck_assert_uint_eq(result.bits[1], UINT32_MAX);
  ck_assert_uint_eq(result.bits[2], UINT32_MAX);
  ck_assert_uint_eq(result.bits[3], 28 << 16);
}
END_TEST
START_TEST(s21_mul_22) {
  s21_decimal value_1 = {{0, 0b10000000000000000, 0, 0}};
  s21_decimal value_2 = {{0, 0b10000000000000000, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);
  if (DECIMAL_OUTPUT) print_decimal_form(21, value_1, value_2, result, error);
  ck_assert_uint_eq(error, 1);
  ck_assert_uint_eq(result.bits[0], 0);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST
START_TEST(s21_mul_23) {
  s21_decimal value_1 = {{0, 0b10000000000000000, 0, 1 << 16}};
  s21_decimal value_2 = {{0, 0b10000000000000000, 0, 1 << 16}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);

  if (DECIMAL_OUTPUT) print_decimal_form(23, value_1, value_2, result, error);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b10011001100110011001100110011010);
  ck_assert_uint_eq(result.bits[1], 0b10011001100110011001100110011001);
  ck_assert_uint_eq(result.bits[2], 0b11001100110011001100110011001);
  ck_assert_uint_eq(result.bits[3], 1 << 16);
}
END_TEST
START_TEST(s21_mul_24) {
  s21_decimal value_1 = {{1, 1, 1, 1 << 16}};
  s21_decimal value_2 = {{0b11, 0b10, 1, 8 << 16}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);
  if (DECIMAL_OUTPUT) print_decimal_form(24, value_1, value_2, result, error);
  ck_assert_uint_eq(error, 1);
  ck_assert_uint_eq(result.bits[0], 0);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST
START_TEST(s21_mul_25) {
  s21_decimal value_1 = {{1, 1, 1, SIGN_MINUS | 1 << 16}};
  s21_decimal value_2 = {{0b11, 0b10, 1, 8 << 16}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);
  if (DECIMAL_OUTPUT) print_decimal_form(25, value_1, value_2, result, error);
  ck_assert_uint_eq(error, 2);
  ck_assert_uint_eq(result.bits[0], 0);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST
START_TEST(s21_mul_26) {
  s21_decimal value_1 = {{0b00001000111101111100101011011101,
                          0b00110101101000001111010000001001,
                          0b1110010100000001101110, 1 << 16}};
  s21_decimal value_2 = {{11447, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);
  if (DECIMAL_OUTPUT) print_decimal_form(26, value_1, value_2, result, error);
  ck_assert_uint_eq(error, 1);
  ck_assert_uint_eq(result.bits[0], 0);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST
START_TEST(s21_mul_27) {
  s21_decimal value_1 = {{0b01111101010000110110000000010011,
                          0b00001110111110101011111001011010, 0b110011101001100,
                          1 << 16}};
  s21_decimal value_2 = {{1624171, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);
  if (DECIMAL_OUTPUT) print_decimal_form(27, value_1, value_2, result, error);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], UINT32_MAX - 1);
  ck_assert_uint_eq(result.bits[1], UINT32_MAX);
  ck_assert_uint_eq(result.bits[2], UINT32_MAX);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST
START_TEST(s21_mul_28) {
  s21_decimal value_1 = {{0b01000000111001000110100110101010,
                          0b01100001110100000110010110100001,
                          0b1111100110110011, 1 << 16}};
  s21_decimal value_2 = {{671893, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);
  if (DECIMAL_OUTPUT) print_decimal_form(28, value_1, value_2, result, error);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], UINT32_MAX);
  ck_assert_uint_eq(result.bits[1], UINT32_MAX);
  ck_assert_uint_eq(result.bits[2], UINT32_MAX);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST
START_TEST(s21_mul_29) {
  s21_decimal value_1 = {{0b10001001010001100111111000100101,
                          0b01100111111000100101000110011111,
                          0b100101000110011111100010010100, 1 << 16}};
  s21_decimal value_2 = {{69, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);
  if (DECIMAL_OUTPUT) print_decimal_form(29, value_1, value_2, result, error);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], UINT32_MAX);
  ck_assert_uint_eq(result.bits[1], UINT32_MAX);
  ck_assert_uint_eq(result.bits[2], UINT32_MAX);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST
START_TEST(s21_mul_30) {
  s21_decimal value_1 = {{1, 0, 0, 28 << 16}};
  s21_decimal value_2 = {{1, 0, 0, 28 << 16}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_mul(value_1, value_2, &result);
  if (DECIMAL_OUTPUT) print_decimal_form(30, value_1, value_2, result, error);
  ck_assert_uint_eq(error, 2);
  ck_assert_uint_eq(result.bits[0], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST
START_TEST(s21_add_1) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST
START_TEST(s21_add_2) {
  s21_decimal value_1 = {{1, 2, 3, 0b11100000000000000000}};
  s21_decimal value_2 = {{1, 2, 3, 0b11100000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 2);
  ck_assert_uint_eq(result.bits[1], 4);
  ck_assert_uint_eq(result.bits[2], 6);
  ck_assert_uint_eq(result.bits[3], 0b11100000000000000000);
}
END_TEST

START_TEST(s21_add_3) {
  s21_decimal value_1 = {{2, 4, 6, 0b11100000000000000000}};
  s21_decimal value_2 = {{2, 4, 6, 0b0000000000011100000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 4);
  ck_assert_uint_eq(result.bits[1], 8);
  ck_assert_uint_eq(result.bits[2], 12);
  ck_assert_uint_eq(result.bits[3], 0b0000000000011100000000000000000);
}
END_TEST
START_TEST(s21_add_4) {
  s21_decimal value_1 = {{0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111, 0}};

  s21_decimal value_2 = {{1, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(error, 1);

  ck_assert_uint_eq(result.bits[0], 0);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST
START_TEST(s21_add_5) {
  s21_decimal value_1 = {{0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111, 0}};

  s21_decimal value_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b10000000000111000000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(error, OK);

  ck_assert_uint_eq(result.bits[0], 0b11111111111111111111111111110111);
  ck_assert_uint_eq(result.bits[1], 0b11111111111111111111111111111111);
  ck_assert_uint_eq(result.bits[2], 0b11111111111111111111111111111111);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST
START_TEST(s21_add_6) {
  s21_decimal value_1 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{0b1, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};

  int error = s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(error, 2);
}
END_TEST
START_TEST(s21_add_7) {
  s21_decimal value_1 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b111000000000000000000}};
  s21_decimal value_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b10000000000111000000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST
START_TEST(s21_add_8) {
  s21_decimal value_1 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b111000000000000000000}};
  s21_decimal value_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b111000000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b00110011001100110011001100110011);
  ck_assert_uint_eq(result.bits[1], 0b00110011001100110011001100110011);
  ck_assert_uint_eq(result.bits[2], 0b110011001100110011001100110011);
  ck_assert_uint_eq(result.bits[3], 0b110110000000000000000);
}
END_TEST
START_TEST(s21_add_9) {
  s21_decimal value_1 = {{0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111, 0}};
  s21_decimal value_2 = {{0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(error, 1);
  ck_assert_uint_eq(result.bits[0], 0);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST
START_TEST(s21_add_10) {
  s21_decimal value_1 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b10000000000000000000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(error, 2);
  ck_assert_uint_eq(result.bits[0], 0);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST
START_TEST(s21_add_11) {
  s21_decimal value_1 = {{0b10111011001010001100110100010110,
                          0b00101000000000001100100000001011,
                          0b10110100001101111111000011100000, 0}};

  s21_decimal value_2 = {{0b01000100110101110011001011101001,
                          0b11010111111111110011011111110100,
                          0b1001011110010000000111100011111, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b11111111111111111111111111111111);
  ck_assert_uint_eq(result.bits[1], 0b11111111111111111111111111111111);
  ck_assert_uint_eq(result.bits[2], 0b11111111111111111111111111111111);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST

START_TEST(s21_add_12) {
  s21_decimal value_1 = {{0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111, 0}};

  s21_decimal value_2 = {
      {0b10111011001010001100110100010110, 0b00101000000000001100100000001011,
       0b10110100001101111111000011100000, 0b10000000000000000000000000000000}};

  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b01000100110101110011001011101001);
  ck_assert_uint_eq(result.bits[1], 0b11010111111111110011011111110100);
  ck_assert_uint_eq(result.bits[2], 0b1001011110010000000111100011111);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST

START_TEST(s21_add_13) {
  s21_decimal value_1 = {{0b1, 0b10, 0b11, 0b11100000000000000000}};
  s21_decimal value_2 = {{0b1, 0b10, 0b11, 0b10000000000011100000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST
START_TEST(s21_add_14) {
  s21_decimal value_1 = {{0b1, 0b10, 0b11, 0b11100000000000000000}};

  s21_decimal value_2 = {
      {0b100001, 0b10, 0b101110111000, 0b10000000000101010000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b00000000100110001001011001011111);
  ck_assert_uint_eq(result.bits[1], 0b00000001001100010010110011111110);
  ck_assert_uint_eq(result.bits[2], 0b1110010011011011111001000);
  ck_assert_uint_eq(result.bits[3], 0b101010000000000000000);
}
END_TEST
START_TEST(s21_add_15) {
  s21_decimal value_1 = {{0b1, 0b10, 0b11, 0b11100000000000000000}};

  s21_decimal value_2 = {{0b1010, 0b1100100, 0b11, 0b101010000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b00000000100110001001011010001010);
  ck_assert_uint_eq(result.bits[1], 0b00000001001100010010110101100100);
  ck_assert_uint_eq(result.bits[2], 0b1110010011100001110000011);
  ck_assert_uint_eq(result.bits[3], 0b101010000000000000000);
}
END_TEST
START_TEST(s21_add_16) {
  s21_decimal value_1 = {{0b1, 0b10, 0b11, 0b11100000000000000000}};

  s21_decimal value_2 = {{0b10000, 0b1100100, 0b11, 0b11010000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b10100001);
  ck_assert_uint_eq(result.bits[1], 0b1111101010);
  ck_assert_uint_eq(result.bits[2], 0b100001);

  ck_assert_uint_eq(result.bits[3], 0b11100000000000000000);
}
END_TEST
START_TEST(s21_add_17) {
  s21_decimal value_1 = {{0b1, 0b10, 0b11, 0b11100000000000000000}};

  s21_decimal value_2 = {{0b111111010111100, 0b1100100, 0b1010011110011010101,
                          0b10000000000101110000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b00111011100110100100101101000100);
  ck_assert_uint_eq(result.bits[1], 0b01110111001101011001001110011100);
  ck_assert_uint_eq(result.bits[2], 0b10110010110010110010000100101011);

  ck_assert_uint_eq(result.bits[3], 0b101110000000000000000);
}
END_TEST
START_TEST(s21_add_18) {
  s21_decimal value_1 = {{0b1, 0b10, 0b11, 0b11100000000000000000}};

  s21_decimal value_2 = {{0b1, 0b1, 0b1, 0b11100000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b10);
  ck_assert_uint_eq(result.bits[1], 0b11);
  ck_assert_uint_eq(result.bits[2], 0b100);

  ck_assert_uint_eq(result.bits[3], 0b11100000000000000000);
}
END_TEST
START_TEST(s21_add_19) {
  s21_decimal value_1 = {{0b1, 0b10, 0b11, 0b11100000000000000000}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b1);
  ck_assert_uint_eq(result.bits[1], 0b10);
  ck_assert_uint_eq(result.bits[2], 0b11);

  ck_assert_uint_eq(result.bits[3], 0b11100000000000000000);
}
START_TEST(s21_add_20) {
  s21_decimal value_1 = {{0b1, 0b10, 0b11, 0b11100000000000000000}};

  s21_decimal value_2 = {{0b1, 0b1, 0b1, 0b10000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b01101011111111010001011111010011);
  ck_assert_uint_eq(result.bits[1], 0b00111011101011100111001100101010);
  ck_assert_uint_eq(result.bits[2], 0b111011100110101100101000000000);

  ck_assert_uint_eq(result.bits[3], 0b10100000000000000000);
}
END_TEST
START_TEST(s21_add_21) {
  s21_decimal value_1 = {{0b1, 0b10, 0b11, 0b11100000000000000000}};

  s21_decimal value_2 = {{0b1, 0b1, 0b1, 0b10100000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b10011100010001);
  ck_assert_uint_eq(result.bits[1], 0b10011100010010);
  ck_assert_uint_eq(result.bits[2], 0b10011100010011);

  ck_assert_uint_eq(result.bits[3], 0b11100000000000000000);
}
END_TEST
START_TEST(s21_add_22) {
  s21_decimal value_1 = {
      {0b11000, 0b1, 0b1, 0b10000000000000010000000000000000}};
  s21_decimal value_2 = {{0b1, 0b10, 0b11, 0b11100000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b01100110001000001010001000101101);
  ck_assert_uint_eq(result.bits[1], 0b00111011100001110010000011011011);
  ck_assert_uint_eq(result.bits[2], 0b111011100110101100101000000000);

  ck_assert_uint_eq(result.bits[3], 0b10000000000010100000000000000000);
}
END_TEST
START_TEST(s21_add_23) {
  s21_decimal value_1 = {{0b1, 0b10, 0b11, 0b11100000000000000000}};

  s21_decimal value_2 = {{0b1, 0b1111, 0b1, 0b10100000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b00000000000000000010011100010001);
  ck_assert_uint_eq(result.bits[1], 0b00000000000000100100100111110010);
  ck_assert_uint_eq(result.bits[2], 0b10011100010011);

  ck_assert_uint_eq(result.bits[3], 0b11100000000000000000);
}
END_TEST
START_TEST(s21_add_24) {
  s21_decimal value_1 = {{0b1, 0b10, 0b11, 0b11100000000000000000}};

  s21_decimal value_2 = {{0b1, 0b1, 0b1, 0b10000000000000010000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b00001011001110000111110000101101);
  ck_assert_uint_eq(result.bits[1], 0b00111011100001110010000011010110);
  ck_assert_uint_eq(result.bits[2], 0b111011100110101100101000000000);

  ck_assert_uint_eq(result.bits[3], 0b10000000000010100000000000000000);
}
END_TEST
START_TEST(s21_add_25) {
  s21_decimal value_1 = {{0b1, 0b10, 0b11, 0b11100000000000000000}};
  s21_decimal value_2 = {{1, 0, 0, 0b10100000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b10011100010001);
  ck_assert_uint_eq(result.bits[1], 0b10);
  ck_assert_uint_eq(result.bits[2], 0b11);
  ck_assert_uint_eq(result.bits[3], 0b11100000000000000000);
}
END_TEST
START_TEST(s21_add_26) {
  s21_decimal value_1 = {{0b1, 0b10, 0b11, 0b11100000000000000000}};

  s21_decimal value_2 = {{1, 0, 0, 0b10110000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b1111101001);
  ck_assert_uint_eq(result.bits[1], 0b10);
  ck_assert_uint_eq(result.bits[2], 0b11);

  ck_assert_uint_eq(result.bits[3], 0b11100000000000000000);
}
END_TEST
START_TEST(s21_add_27) {
  s21_decimal value_1 = {{0b1, 0b1, 0b1, 0b10000000000000010000000000000000}};
  s21_decimal value_2 = {{0b1, 0b1, 0b1, 0b10000000000000010000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b10);
  ck_assert_uint_eq(result.bits[1], 0b10);
  ck_assert_uint_eq(result.bits[2], 0b10);

  ck_assert_uint_eq(result.bits[3], 0b10000000000000010000000000000000);
}
END_TEST
START_TEST(s21_add_28) {
  s21_decimal value_1 = {{0b1, 0b1, 0b1, 0b10000000000000010000000000000000}};

  s21_decimal value_2 = {{0b1, 0, 0, 0b10100000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b00111011100110101100100111111111);
  ck_assert_uint_eq(result.bits[1], 0b00111011100110101100101000000000);
  ck_assert_uint_eq(result.bits[2], 0b111011100110101100101000000000);

  ck_assert_uint_eq(result.bits[3], 0b10000000000010100000000000000000);
}
END_TEST
START_TEST(s21_add_29) {
  s21_decimal value_1 = {{0b1, 0b1, 0b1, 0b10000000000000010000000000000000}};

  s21_decimal value_2 = {{0b1, 0, 0, 0b10000000000010100000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b00111011100110101100101000000001);
  ck_assert_uint_eq(result.bits[1], 0b00111011100110101100101000000000);
  ck_assert_uint_eq(result.bits[2], 0b111011100110101100101000000000);

  ck_assert_uint_eq(result.bits[3], 0b10000000000010100000000000000000);
}
END_TEST
START_TEST(s21_add_30) {
  s21_decimal value_1 = {{0b1, 0b1, 0b1, 0b10000000000000010000000000000000}};

  s21_decimal value_2 = {{0b1, 0, 0b1, 0b11100000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b10000000110100111011100100110101);
  ck_assert_uint_eq(result.bits[1], 0b00111011100101000011110001000111);
  ck_assert_uint_eq(result.bits[2], 0b111011100110101100101000000000);

  ck_assert_uint_eq(result.bits[3], 0b10000000000010100000000000000000);
}
END_TEST
START_TEST(s21_add_31) {
  s21_decimal value_1 = {{0b1, 0b1, 0b1, 0b10000000000000010000000000000000}};

  s21_decimal value_2 = {{0b1, 0, 0b1, 0b10000000000011100000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b11110110011000011101101011001011);
  ck_assert_uint_eq(result.bits[1], 0b00111011101000010101011110111000);
  ck_assert_uint_eq(result.bits[2], 0b111011100110101100101000000000);

  ck_assert_uint_eq(result.bits[3], 0b10000000000010100000000000000000);
}
END_TEST
START_TEST(s21_add_32) {
  s21_decimal value_1 = {{0b1, 0b1, 0b1, 0b10000000000000010000000000000000}};

  s21_decimal value_2 = {{0b1, 0b10, 0b11, 0b10000000000000010000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b10);
  ck_assert_uint_eq(result.bits[1], 0b11);
  ck_assert_uint_eq(result.bits[2], 0b100);

  ck_assert_uint_eq(result.bits[3], 0b10000000000000010000000000000000);
}
END_TEST
START_TEST(s21_add_33) {
  s21_decimal value_1 = {{0b1, 0, 0, 0b10100000000000000000}};

  s21_decimal value_2 = {
      {0b11000, 0b1, 0b1, 0b10000000000000010000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b10010110100000101110111111111111);
  ck_assert_uint_eq(result.bits[1], 0b00111011100110101100101000000101);
  ck_assert_uint_eq(result.bits[2], 0b111011100110101100101000000000);

  ck_assert_uint_eq(result.bits[3], 0b10000000000010100000000000000000);
}
END_TEST
START_TEST(s21_add_34) {
  s21_decimal value_1 = {{0b1, 0, 0, 0b10100000000000000000}};

  s21_decimal value_2 = {{0b11, 0b10, 0b1, 0b10000000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b100101101);
  ck_assert_uint_eq(result.bits[1], 0b11001000);
  ck_assert_uint_eq(result.bits[2], 0b1100100);

  ck_assert_uint_eq(result.bits[3], 0b10100000000000000000);
}
END_TEST
START_TEST(s21_add_35) {
  s21_decimal value_1 = {
      {0b10001111111111111111111101010001, 0b00110001000001001111101011101101,
       0b10011101111101011111011100101010, 0b1100000000000000000}};

  s21_decimal value_2 = {
      {0b10100001000001100100110101110101, 0b10111011101101011011100111001111,
       0b111111110100001011001101110, 0b10000000000001110000000000000000}};

  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b10011001011111110101110111111000);
  ck_assert_uint_eq(result.bits[1], 0b10110111110110010011010100100101);
  ck_assert_uint_eq(result.bits[2], 0b10011101001010011100000110111000);

  ck_assert_uint_eq(result.bits[3], 0b1100000000000000000);
}
END_TEST
START_TEST(s21_add_36) {
  s21_decimal value_1 = {
      {0b10001111111111111111111101010001, 0b00110001000001001111101011101101,
       0b10011101111101011111011100101010, 0b1100000000000000000}};

  s21_decimal value_2 = {
      {0b10100001000001100100110101110101, 0b10111011101101011011100111001111,
       0b111111110100001011001101110, 0b1110000000000000000}};

  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b10000110100000001010000010101010);
  ck_assert_uint_eq(result.bits[1], 0b10101010001100001100000010110101);
  ck_assert_uint_eq(result.bits[2], 0b10011110110000100010110010011011);

  ck_assert_uint_eq(result.bits[3], 0b1100000000000000000);
}
END_TEST
START_TEST(s21_add_37) {
  s21_decimal value_1 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0}};
  s21_decimal value_2 = {{5, 0, 0, 1 << 16}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(error, 1);
  ck_assert_uint_eq(result.bits[0], 0);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST
START_TEST(s21_add_38) {
  s21_decimal value_1 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0}};
  s21_decimal value_2 = {{4, 0, 0, 1 << 16}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], UINT32_MAX);
  ck_assert_uint_eq(result.bits[1], UINT32_MAX);
  ck_assert_uint_eq(result.bits[2], UINT32_MAX);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST
START_TEST(s21_add_39) {
  s21_decimal value_1 = {{UINT32_MAX - 1, UINT32_MAX, UINT32_MAX, 0}};
  s21_decimal value_2 = {{5, 0, 0, 1 << 16}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], UINT32_MAX - 1);
  ck_assert_uint_eq(result.bits[1], UINT32_MAX);
  ck_assert_uint_eq(result.bits[2], UINT32_MAX);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST
START_TEST(s21_add_40) {
  s21_decimal value_1 = {{UINT32_MAX - 1, UINT32_MAX, UINT32_MAX, 0}};
  s21_decimal value_2 = {{6, 0, 0, 1 << 16}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], UINT32_MAX);
  ck_assert_uint_eq(result.bits[1], UINT32_MAX);
  ck_assert_uint_eq(result.bits[2], UINT32_MAX);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST
START_TEST(s21_sub_1) {
  s21_decimal value_1 = {{1, 0b10, 0b11, 0b11100000000000000000}};
  s21_decimal value_2 = {{1, 0b10, 0b11, 0b11100000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_sub(value_1, value_2, &result);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST
START_TEST(s21_sub_2) {
  s21_decimal value_1 = {{1, 0b10, 0b11, 0b11100000000000000000}};
  s21_decimal value_2 = {{1, 0b10, 0b11, 0b10000000000011100000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_sub(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b10);
  ck_assert_uint_eq(result.bits[1], 0b100);
  ck_assert_uint_eq(result.bits[2], 0b110);
  ck_assert_uint_eq(result.bits[3], 0b11100000000000000000);
}
END_TEST
START_TEST(s21_sub_3) {
  s21_decimal value_1 = {{1, 0b10, 0b11, 0b11100000000000000000}};

  s21_decimal value_2 = {
      {0b100001, 0b10, 0b101110111000, 0b10000000000101010000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_sub(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b00000000100110001001011010100001);
  ck_assert_uint_eq(result.bits[1], 0b00000001001100010010110100000010);
  ck_assert_uint_eq(result.bits[2], 0b1110010011100111100111000);
  ck_assert_uint_eq(result.bits[3], 0b101010000000000000000);
}
END_TEST
START_TEST(s21_sub_4) {
  s21_decimal value_1 = {{1, 0b10, 0b11, 0b11100000000000000000}};

  s21_decimal value_2 = {{0b1010, 0b1100100, 0b11, 0b101010000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_sub(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b00000000100110001001011001110110);
  ck_assert_uint_eq(result.bits[1], 0b00000001001100010010110010011100);
  ck_assert_uint_eq(result.bits[2], 0b1110010011100001101111101);
  ck_assert_uint_eq(result.bits[3], 0b101010000000000000000);
}
END_TEST
START_TEST(s21_sub_5) {
  s21_decimal value_1 = {{1, 0b10, 0b11, 0b11100000000000000000}};

  s21_decimal value_2 = {{0b10000, 0b1100100, 0b11, 0b11010000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_sub(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b10011111);
  ck_assert_uint_eq(result.bits[1], 0b1111100110);
  ck_assert_uint_eq(result.bits[2], 0b11011);

  ck_assert_uint_eq(result.bits[3], 0b10000000000011100000000000000000);
}
END_TEST
START_TEST(s21_sub_6) {
  s21_decimal value_1 = {{1, 0b10, 0b11, 0b11100000000000000000}};

  s21_decimal value_2 = {{0b111111010111100, 0b1100100, 0b1010011110011010101,
                          0b10000000000101110000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_sub(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b00111011100110110100100010111100);
  ck_assert_uint_eq(result.bits[1], 0b01110111001101011001010001100100);
  ck_assert_uint_eq(result.bits[2], 0b10110010110101011001101011010101);

  ck_assert_uint_eq(result.bits[3], 0b101110000000000000000);
}
END_TEST
START_TEST(s21_sub_7) {
  s21_decimal value_1 = {{1, 0b10, 0b11, 0b11100000000000000000}};

  s21_decimal value_2 = {{0b1, 0b1, 0b1, 0b11100000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_sub(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0);
  ck_assert_uint_eq(result.bits[1], 0b1);
  ck_assert_uint_eq(result.bits[2], 0b10);
  ck_assert_uint_eq(result.bits[3], 0b11100000000000000000);
}
END_TEST
START_TEST(s21_sub_8) {
  s21_decimal value_1 = {{1, 0b10, 0b11, 0b11100000000000000000}};

  s21_decimal value_2 = {{0, 0, 0, 0b11010000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_sub(value_1, value_2, &result);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b1);
  ck_assert_uint_eq(result.bits[1], 0b10);
  ck_assert_uint_eq(result.bits[2], 0b11);
  ck_assert_uint_eq(result.bits[3], 0b11100000000000000000);
}
END_TEST
START_TEST(s21_sub_9) {
  s21_decimal value_1 = {{1, 0b10, 0b11, 0b11100000000000000000}};

  s21_decimal value_2 = {{0b1, 0b1, 0b1, 0b10000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_sub(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b00001011001110000111110000101101);
  ck_assert_uint_eq(result.bits[1], 0b00111011100001110010000011010110);
  ck_assert_uint_eq(result.bits[2], 0b111011100110101100101000000000);

  ck_assert_uint_eq(result.bits[3], 0b10000000000010100000000000000000);
}
END_TEST
START_TEST(s21_sub_10) {
  s21_decimal value_1 = {{1, 0b10, 0b11, 0b11100000000000000000}};

  s21_decimal value_2 = {{0b1, 0b1, 0b1, 0b10100000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_sub(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b10011100001111);
  ck_assert_uint_eq(result.bits[1], 0b10011100001110);
  ck_assert_uint_eq(result.bits[2], 0b10011100001101);

  ck_assert_uint_eq(result.bits[3], 0b10000000000011100000000000000000);
}
END_TEST
START_TEST(s21_sub_11) {
  s21_decimal value_1 = {{1, 0b10, 0b11, 0b11100000000000000000}};

  s21_decimal value_2 = {
      {0b11000, 0b1, 0b1, 0b10000000000000010000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_sub(value_1, value_2, &result);

  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b11000110111001010011110111010011);
  ck_assert_uint_eq(result.bits[1], 0b00111011101011100111001100101111);
  ck_assert_uint_eq(result.bits[2], 0b111011100110101100101000000000);

  ck_assert_uint_eq(result.bits[3], 0b10100000000000000000);
}
END_TEST
START_TEST(s21_div_1) {
  s21_decimal value_1 = {{1, 0b10, 0b11, 14 << 16}};
  s21_decimal value_2 = {{1, 0b10, 0b11, 14 << 16}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_div(value_1, value_2, &result);
  if (DECIMAL_OUTPUT) print_decimal_form(1, value_1, value_2, result, error);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 1);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST
START_TEST(s21_div_2) {
  s21_decimal value_1 = {{1, 0b10, 0b11, 14 << 16}};
  s21_decimal value_2 = {{1, 0b10, 0b11, SIGN_MINUS | 14 << 16}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_div(value_1, value_2, &result);
  if (DECIMAL_OUTPUT) print_decimal_form(2, value_1, value_2, result, error);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 1);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], SIGN_MINUS);
}
END_TEST
START_TEST(s21_div_7) {
  s21_decimal value_1 = {{1, 0b10, 0b11, 14 << 16}};
  s21_decimal value_2 = {{1, 0, 0, 10 << 16}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_div(value_1, value_2, &result);
  if (DECIMAL_OUTPUT) print_decimal_form(7, value_1, value_2, result, error);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 1);
  ck_assert_uint_eq(result.bits[1], 0b10);
  ck_assert_uint_eq(result.bits[2], 0b11);
  ck_assert_uint_eq(result.bits[3], 4 << 16);
}

END_TEST

START_TEST(s21_div_12) {
  s21_decimal value_1 = {{1, 0, 0, 0}};

  s21_decimal value_2 = {{0b00100000000000000000000000000000,
                          0b01111100010010100000010011000010,
                          0b1000000100111111001110010111100, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_div(value_1, value_2, &result);
  if (DECIMAL_OUTPUT) print_decimal_form(12, value_1, value_2, result, error);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST
START_TEST(s21_div_13) {
  s21_decimal value_1 = {{1, 2, 3, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_div(value_1, value_2, &result);
  if (DECIMAL_OUTPUT) print_decimal_form(13, value_1, value_2, result, error);
  ck_assert_uint_eq(error, 3);
  ck_assert_uint_eq(result.bits[0], 0);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST

START_TEST(s21_div_15) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 2 << 16}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_div(value_1, value_2, &result);
  if (DECIMAL_OUTPUT) print_decimal_form(15, value_1, value_2, result, error);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 100);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
}
START_TEST(s21_div_16) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 1 << 16}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_div(value_1, value_2, &result);
  if (DECIMAL_OUTPUT) print_decimal_form(16, value_1, value_2, result, error);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 10);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
}
START_TEST(s21_div_17) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 28 << 16}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_div(value_1, value_2, &result);
  if (DECIMAL_OUTPUT) print_decimal_form(17, value_1, value_2, result, error);
  ck_assert_uint_eq(error, OK);
  ck_assert_uint_eq(result.bits[0], 0b10000000000000000000000000000);
  ck_assert_uint_eq(result.bits[1], 0b111110001001010000001001100001);
  ck_assert_uint_eq(result.bits[2], 0b100000010011111100111001011110);
  ck_assert_uint_eq(result.bits[3], 0);
}
START_TEST(s21_div_18) {
  s21_decimal value_1 = {{1, 0, 0, 28 << 16}};
  s21_decimal value_2 = {{0b10000000000000000000000000000,
                          0b111110001001010000001001100001,
                          0b100000010011111100111001011110, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_div(value_1, value_2, &result);
  if (DECIMAL_OUTPUT) print_decimal_form(18, value_1, value_2, result, error);
  ck_assert_uint_eq(error, 2);
  ck_assert_uint_eq(result.bits[0], 0);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST
Suite *test_s21_arif(void) {
  Suite *s = suite_create("s21_arif");
  TCase *tc = tcase_create("s");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_add_1);
  tcase_add_test(tc, s21_add_2);
  tcase_add_test(tc, s21_add_3);
  tcase_add_test(tc, s21_add_4);
  tcase_add_test(tc, s21_add_5);
  tcase_add_test(tc, s21_add_6);
  tcase_add_test(tc, s21_add_7);
  tcase_add_test(tc, s21_add_8);
  tcase_add_test(tc, s21_add_9);
  tcase_add_test(tc, s21_add_10);
  tcase_add_test(tc, s21_add_11);
  tcase_add_test(tc, s21_add_12);
  tcase_add_test(tc, s21_add_13);
  tcase_add_test(tc, s21_add_14);
  tcase_add_test(tc, s21_add_15);
  tcase_add_test(tc, s21_add_16);
  tcase_add_test(tc, s21_add_17);
  tcase_add_test(tc, s21_add_18);
  tcase_add_test(tc, s21_add_19);
  tcase_add_test(tc, s21_add_20);
  tcase_add_test(tc, s21_add_21);
  tcase_add_test(tc, s21_add_22);
  tcase_add_test(tc, s21_add_23);
  tcase_add_test(tc, s21_add_24);
  tcase_add_test(tc, s21_add_25);
  tcase_add_test(tc, s21_add_26);
  tcase_add_test(tc, s21_add_27);
  tcase_add_test(tc, s21_add_28);
  tcase_add_test(tc, s21_add_29);
  tcase_add_test(tc, s21_add_30);
  tcase_add_test(tc, s21_add_31);
  tcase_add_test(tc, s21_add_32);
  tcase_add_test(tc, s21_add_33);
  tcase_add_test(tc, s21_add_34);
  tcase_add_test(tc, s21_add_35);
  tcase_add_test(tc, s21_add_36);
  tcase_add_test(tc, s21_add_37);
  tcase_add_test(tc, s21_add_38);
  tcase_add_test(tc, s21_add_39);
  tcase_add_test(tc, s21_add_40);
  tcase_add_test(tc, s21_mul_1);
  tcase_add_test(tc, s21_mul_2);
  tcase_add_test(tc, s21_mul_3);
  tcase_add_test(tc, s21_mul_4);
  tcase_add_test(tc, s21_mul_6);
  tcase_add_test(tc, s21_mul_7);
  tcase_add_test(tc, s21_mul_8);
  tcase_add_test(tc, s21_mul_9);
  tcase_add_test(tc, s21_mul_10);
  tcase_add_test(tc, s21_mul_11);
  tcase_add_test(tc, s21_mul_12);
  tcase_add_test(tc, s21_mul_13);
  tcase_add_test(tc, s21_mul_14);
  tcase_add_test(tc, s21_mul_15);
  tcase_add_test(tc, s21_mul_16);
  tcase_add_test(tc, s21_mul_17);
  tcase_add_test(tc, s21_mul_18);
  tcase_add_test(tc, s21_mul_19);
  tcase_add_test(tc, s21_mul_20);
  tcase_add_test(tc, s21_mul_21);
  tcase_add_test(tc, s21_mul_22);
  tcase_add_test(tc, s21_mul_23);
  tcase_add_test(tc, s21_mul_24);
  tcase_add_test(tc, s21_mul_25);
  tcase_add_test(tc, s21_mul_26);
  tcase_add_test(tc, s21_mul_27);
  tcase_add_test(tc, s21_mul_28);
  tcase_add_test(tc, s21_mul_29);
  tcase_add_test(tc, s21_mul_30);
  tcase_add_test(tc, s21_sub_1);
  tcase_add_test(tc, s21_sub_2);
  tcase_add_test(tc, s21_sub_3);
  tcase_add_test(tc, s21_sub_4);
  tcase_add_test(tc, s21_sub_5);
  tcase_add_test(tc, s21_sub_6);
  tcase_add_test(tc, s21_sub_7);
  tcase_add_test(tc, s21_sub_8);
  tcase_add_test(tc, s21_sub_9);
  tcase_add_test(tc, s21_sub_10);
  tcase_add_test(tc, s21_sub_11);
  tcase_add_test(tc, s21_div_1);
  tcase_add_test(tc, s21_div_2);
  tcase_add_test(tc, s21_div_7);
  tcase_add_test(tc, s21_div_12);
  tcase_add_test(tc, s21_div_13);
  tcase_add_test(tc, s21_div_15);
  tcase_add_test(tc, s21_div_16);
  tcase_add_test(tc, s21_div_17);
  tcase_add_test(tc, s21_div_18);
  return s;
}
