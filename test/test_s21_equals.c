#include <limits.h>

#include "test.h"
START_TEST(s21_is_equal_1) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  int is_equal = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(is_equal, TRUE);
}
END_TEST
START_TEST(s21_is_equal_2) {
  s21_decimal value_1 = {{0, 1, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  int is_equal = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(is_equal, FALSE);
}
END_TEST
START_TEST(s21_is_equal_3) {
  s21_decimal value_1 = {{0, 0, 0, 0b11100000000000000000}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  int is_equal = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(is_equal, TRUE);
}
END_TEST
START_TEST(s21_is_equal_4) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0b110100000000000000000}};
  int is_equal = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(is_equal, TRUE);
}
END_TEST
START_TEST(s21_is_equal_5) {
  s21_decimal value_1 = {{2, 4, 8, 0b10000000000110100000000000000000}};
  s21_decimal value_2 = {{2, 4, 8, 0b10000000000110100000000000000000}};
  int is_equal = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(is_equal, TRUE);
}
END_TEST
START_TEST(s21_is_equal_6) {
  s21_decimal value_1 = {{228, 13, 59, 0b110100000000000000000}};
  s21_decimal value_2 = {{228, 13, 59, 0b110100000000000000000}};
  int is_equal = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(is_equal, TRUE);
}
START_TEST(s21_is_equal_7) {
  s21_decimal value_1 = {{10, 0, 0, 0}};

  s21_decimal value_2 = {{100, 0, 0, 0b10000000000000000}};
  set_scale(&value_2, 1);
  int is_equal = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(is_equal, TRUE);
}
END_TEST
START_TEST(s21_is_equal_8) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0b10000000000000000000000000000000}};
  int is_equal = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(is_equal, TRUE);
}
END_TEST
START_TEST(s21_is_equal_9) {
  s21_decimal value_1 = {{0b10011001100110011001101000000000,
                          0b011001100110011001100110011001, 0, 0}};

  s21_decimal value_2 = {{0b10000000000, 0, 1, 0b10000000000000000}};
  int is_equal = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(is_equal, TRUE);
}
END_TEST

START_TEST(s21_is_equal_10) {
  s21_decimal value_1 = {
      {0b11001000000000000, 0, 0b1100100, 0b110000000000000000}};
  s21_decimal value_2 = {{0b10011001100110011001101000000000,
                          0b011001100110011001100110011001, 0, 0}};
  int is_equal = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(is_equal, TRUE);
}
END_TEST

START_TEST(s21_is_equal_11) {
  s21_decimal value_1 = {{9, 0, 0, 0}};

  s21_decimal value_2 = {
      {0b00101000000000000000000000000000, 0b10011110010101001000001000100100,
       0b11101000101001010000000100001, 0b110110000000000000000}};
  int is_equal = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(is_equal, TRUE);
}
END_TEST
START_TEST(s21_is_equal_12) {
  s21_decimal value_1 = {{0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111, 0}};
  s21_decimal value_2 = {{0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111, 0}};
  int is_equal = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(is_equal, TRUE);
}
END_TEST

START_TEST(s21_is_equal_13) {
  s21_decimal value_1 = {{0b10011001100110011001100110011001,
                          0b10011001100110011001100110011001,
                          0b11001100110011001100110011001, 0}};

  s21_decimal value_2 = {
      {0b11111111111111111111111111111010, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b10000000000000000}};
  int is_equal = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(is_equal, TRUE);
}
END_TEST
START_TEST(s21_is_equal_14) {
  s21_decimal value_1 = {{0b11111111111111111111111111111010,
                          0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111, 0}};
  s21_decimal value_2 = {
      {0b11111111111111111111111111111010, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b10000000000000000}};
  int is_equal = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(is_equal, FALSE);
}
END_TEST
START_TEST(s21_is_equal_15) {
  s21_decimal value_1 = {{7, 0, 0, 0}};

  s21_decimal value_2 = {
      {0b01110000000000000000000000000000, 0b10110011000000110001000010100111,
       0b11100010001011101010010010010011, 0b111000000000000000000}};
  int is_equal = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(is_equal, TRUE);
}
END_TEST
START_TEST(s21_is_equal_16) {
  s21_decimal value_1 = {{0b01100001101010110100000000000000,
                          0b11010010010100100001, 0, 0b101000000000000000000}};

  s21_decimal value_2 = {{37, 0, 0, 0b1100000000000000000}};
  int is_equal = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(is_equal, TRUE);
}
END_TEST
START_TEST(s21_is_equal_17) {
  s21_decimal value_1 = {{0b01100001101010110100000000000000,
                          0b11010010010100100001, 0, 0b111000000000000000000}};

  s21_decimal value_2 = {{37, 0, 0, 0b11100000000000000000}};
  int is_equal = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(is_equal, TRUE);
}
END_TEST
START_TEST(s21_is_equal_18) {
  s21_decimal value_1 = {{0b10000000000000000000000000000000, 0, 0,
                          0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  int is_equal = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(is_equal, FALSE);
}
END_TEST
START_TEST(s21_is_equal_19) {
  s21_decimal value_1 = {
      {0b100110110101000010111, 0, 0, 0b1000000000000000000}};

  s21_decimal value_2 = {{1, 1, 1, 0b10000000000000000}};
  int is_equal = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(is_equal, FALSE);
}
END_TEST
START_TEST(s21_is_equal_20) {
  s21_decimal value_1 = {
      {0b100110110101000010111, 0, 0, 0b1000000000000000000}};

  s21_decimal value_2 = {{1, 1, 1, 0b10000000000000010000000000000000}};
  int is_equal = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(is_equal, FALSE);
}
END_TEST
START_TEST(s21_is_greater_or_equal_1) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  int is_greater_or_equal = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(is_greater_or_equal, TRUE);
}
END_TEST
START_TEST(s21_is_greater_or_equal_2) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  int is_greater_or_equal = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(is_greater_or_equal, TRUE);
}
END_TEST
START_TEST(s21_is_greater_or_equal_3) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  int is_greater_or_equal = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(is_greater_or_equal, FALSE);
}
END_TEST
START_TEST(s21_is_greater_or_equal_4) {
  s21_decimal value_1 = {{0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111, 0}};

  s21_decimal value_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b10000000000000000}};
  int is_greater_or_equal = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(is_greater_or_equal, TRUE);
}
END_TEST
START_TEST(s21_is_greater_or_equal_5) {
  s21_decimal value_1 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b10000000000000000}};
  s21_decimal value_2 = {{0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111, 0}};
  int is_greater_or_equal = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(is_greater_or_equal, FALSE);
}
END_TEST
START_TEST(s21_is_greater_or_equal_6) {
  s21_decimal value_1 = {
      {0b10001100010001111001100000011111, 0b01100100101101000101010010111111,
       0b1101111100100010000011011001001, 0b11000000000000000000}};
  s21_decimal value_2 = {
      {0b11110100101010111110110000011111, 0b11101001001110100011011000011100,
       0b111001001011011011011, 0b10000000000100110000000000000000}};
  int is_greater_or_equal = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(is_greater_or_equal, TRUE);
}
END_TEST
START_TEST(s21_is_greater_or_equal_7) {
  s21_decimal value_1 = {
      {0b10001100010001111001100000011111, 0b01100100101101000101010010111111,
       0b1101111100100010000011011001001, 0b10000000000011000000000000000000}};
  s21_decimal value_2 = {{0b11110100101010111110110000011111,
                          0b11101001001110100011011000011100,
                          0b111001001011011011011, 0b100110000000000000000}};
  int is_greater_or_equal = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(is_greater_or_equal, FALSE);
}
END_TEST
START_TEST(s21_is_greater_or_equal_8) {
  s21_decimal value_1 = {
      {0b10001100010001111001100000011111, 0b01100100101101000101010010111111,
       0b1101111100100010000011011001001, 0b10000000000011000000000000000000}};
  s21_decimal value_2 = {
      {0b11110100101010111110110000011111, 0b11101001001110100011011000011100,
       0b111001001011011011011, 0b10000000000100110000000000000000}};
  int is_greater_or_equal = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(is_greater_or_equal, FALSE);
}
END_TEST
START_TEST(s21_is_greater_or_equal_9) {
  s21_decimal value_1 = {{0b1111011, 0, 0, 0}};

  s21_decimal value_2 = {{0b10110001101110110000000000000000,
                          0b10001000100011101011001111011, 0,
                          0b100000000000000000000}};
  int is_greater_or_equal = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(is_greater_or_equal, TRUE);
}
END_TEST
START_TEST(s21_is_greater_or_equal_10) {
  s21_decimal value_1 = {{0b1111011, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{0b10110001101110110000000000000000,
                          0b10001000100011101011001111011, 0,
                          0b10000000000100000000000000000000}};
  int is_greater_or_equal = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(is_greater_or_equal, TRUE);
}
END_TEST
START_TEST(s21_is_greater_1) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  int is_greater = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(is_greater, FALSE);
}
END_TEST
START_TEST(s21_is_greater_2) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  int is_greater = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(is_greater, TRUE);
}
END_TEST
START_TEST(s21_is_greater_3) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{10, 0, 0, 0}};
  int is_greater = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(is_greater, FALSE);
}
END_TEST
START_TEST(s21_is_greater_4) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_decimal value_2 = {{10, 0, 0, 0}};
  int is_greater = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(is_greater, FALSE);
}
END_TEST
START_TEST(s21_is_greater_5) {
  s21_decimal value_1 = {{0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111, 0}};

  s21_decimal value_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b10000000000000000}};
  int is_greater = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(is_greater, TRUE);
}
END_TEST
START_TEST(s21_is_greater_6) {
  s21_decimal value_1 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b10000000000000000}};
  s21_decimal value_2 = {{0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111, 0}};
  int is_greater = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(is_greater, FALSE);
}
END_TEST
START_TEST(s21_is_greater_7) {
  s21_decimal value_1 = {
      {0b10001100010001111001100000011111, 0b01100100101101000101010010111111,
       0b1101111100100010000011011001001, 0b11000000000000000000}};
  s21_decimal value_2 = {
      {0b11110100101010111110110000011111, 0b11101001001110100011011000011100,
       0b111001001011011011011, 0b10000000000100110000000000000000}};
  int is_greater = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(is_greater, TRUE);
}
END_TEST
START_TEST(s21_is_greater_8) {
  s21_decimal value_1 = {
      {0b10001100010001111001100000011111, 0b01100100101101000101010010111111,
       0b1101111100100010000011011001001, 0b10000000000011000000000000000000}};
  s21_decimal value_2 = {{0b11110100101010111110110000011111,
                          0b11101001001110100011011000011100,
                          0b111001001011011011011, 0b100110000000000000000}};
  int is_greater = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(is_greater, FALSE);
}
END_TEST
START_TEST(s21_is_greater_9) {
  s21_decimal value_1 = {
      {0b10001100010001111001100000011111, 0b01100100101101000101010010111111,
       0b1101111100100010000011011001001, 0b10000000000011000000000000000000}};
  s21_decimal value_2 = {
      {0b11110100101010111110110000011111, 0b11101001001110100011011000011100,
       0b111001001011011011011, 0b10000000000100110000000000000000}};
  int is_greater = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(is_greater, FALSE);
}
END_TEST
START_TEST(s21_is_greater_10) {
  s21_decimal value_1 = {{0b1111011, 0, 0, 0}};

  s21_decimal value_2 = {{0b10110001101110110000000000000000,
                          0b10001000100011101011001111011, 0,
                          0b100000000000000000000}};
  int is_greater = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(is_greater, FALSE);
}
END_TEST
START_TEST(s21_is_greater_11) {
  s21_decimal value_1 = {{0b1111011, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{0b10110001101110110000000000000000,
                          0b10001000100011101011001111011, 0,
                          0b10000000000100000000000000000000}};
  int is_greater = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(is_greater, FALSE);
}
END_TEST
START_TEST(s21_is_less_or_equal_1) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  int is_less_or_equal = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(is_less_or_equal, TRUE);
}
END_TEST
START_TEST(s21_is_less_or_equal_2) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  int is_less_or_equal = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(is_less_or_equal, TRUE);
}
END_TEST
START_TEST(s21_is_less_or_equal_3) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  int is_less_or_equal = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(is_less_or_equal, FALSE);
}
END_TEST
START_TEST(s21_is_less_or_equal_4) {
  s21_decimal value_1 = {{0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111, 0}};

  s21_decimal value_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b10000000000000000}};
  int is_less_or_equal = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(is_less_or_equal, FALSE);
}
END_TEST
START_TEST(s21_is_less_or_equal_5) {
  s21_decimal value_1 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b10000000000000000}};
  s21_decimal value_2 = {{0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111, 0}};
  int is_less_or_equal = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(is_less_or_equal, TRUE);
}
END_TEST
START_TEST(s21_is_less_or_equal_6) {
  s21_decimal value_1 = {
      {0b10001100010001111001100000011111, 0b01100100101101000101010010111111,
       0b1101111100100010000011011001001, 0b11000000000000000000}};
  s21_decimal value_2 = {
      {0b11110100101010111110110000011111, 0b11101001001110100011011000011100,
       0b111001001011011011011, 0b10000000000100110000000000000000}};
  int is_less_or_equal = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(is_less_or_equal, FALSE);
}
END_TEST
START_TEST(s21_is_less_or_equal_7) {
  s21_decimal value_1 = {
      {0b10001100010001111001100000011111, 0b01100100101101000101010010111111,
       0b1101111100100010000011011001001, 0b10000000000011000000000000000000}};
  s21_decimal value_2 = {{0b11110100101010111110110000011111,
                          0b11101001001110100011011000011100,
                          0b111001001011011011011, 0b100110000000000000000}};
  int is_less_or_equal = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(is_less_or_equal, TRUE);
}
END_TEST
START_TEST(s21_is_less_or_equal_8) {
  s21_decimal value_1 = {
      {0b10001100010001111001100000011111, 0b01100100101101000101010010111111,
       0b1101111100100010000011011001001, 0b10000000000011000000000000000000}};
  s21_decimal value_2 = {
      {0b11110100101010111110110000011111, 0b11101001001110100011011000011100,
       0b111001001011011011011, 0b10000000000100110000000000000000}};
  int is_less_or_equal = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(is_less_or_equal, TRUE);
}
END_TEST
START_TEST(s21_is_less_or_equal_9) {
  s21_decimal value_1 = {{0b1111011, 0, 0, 0}};

  s21_decimal value_2 = {{0b10110001101110110000000000000000,
                          0b10001000100011101011001111011, 0,
                          0b100000000000000000000}};
  int is_less_or_equal = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(is_less_or_equal, TRUE);
}
END_TEST
START_TEST(s21_is_less_or_equal_10) {
  s21_decimal value_1 = {{0b1111011, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{0b10110001101110110000000000000000,
                          0b10001000100011101011001111011, 0,
                          0b10000000000100000000000000000000}};
  int is_less_or_equal = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(is_less_or_equal, TRUE);
}
END_TEST
START_TEST(s21_is_less_1) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  int is_less = s21_is_less(value_1, value_2);
  ck_assert_int_eq(is_less, FALSE);
}
END_TEST
START_TEST(s21_is_less_2) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  int is_less = s21_is_less(value_1, value_2);
  ck_assert_int_eq(is_less, FALSE);
}
END_TEST
START_TEST(s21_is_less_3) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{10, 0, 0, 0}};
  int is_less = s21_is_less(value_1, value_2);
  ck_assert_int_eq(is_less, TRUE);
}
END_TEST
START_TEST(s21_is_less_4) {
  s21_decimal value_1 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b10000000000000000}};
  s21_decimal value_2 = {{0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111, 0}};
  int is_less = s21_is_less(value_1, value_2);
  ck_assert_int_eq(is_less, TRUE);
}
END_TEST
START_TEST(s21_is_less_5) {
  s21_decimal value_1 = {{0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111, 0}};
  s21_decimal value_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b110000000000000000}};
  int is_less = s21_is_less(value_1, value_2);
  ck_assert_int_eq(is_less, FALSE);
}
END_TEST
START_TEST(s21_is_less_6) {
  s21_decimal value_1 = {{0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111, 0}};

  s21_decimal value_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b111000000000000000000}};
  int is_less = s21_is_less(value_1, value_2);
  ck_assert_int_eq(is_less, FALSE);
}
END_TEST
START_TEST(s21_is_less_7) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0b110000000000000000}};
  int is_less = s21_is_less(value_1, value_2);
  ck_assert_int_eq(is_less, FALSE);
}
END_TEST
START_TEST(s21_is_less_8) {
  s21_decimal value_1 = {{1, 0, 0, 0b10000000000000000000000000000000}};

  s21_decimal value_2 = {{10, 0, 0, 0b10000000000000000000000000000000}};
  int is_less = s21_is_less(value_1, value_2);
  ck_assert_int_eq(is_less, FALSE);
}
END_TEST
START_TEST(s21_is_less_9) {
  s21_decimal value_1 = {{10, 0, 0, 0b10000000000000000000000000000000}};

  s21_decimal value_2 = {{1, 0, 0, 0b10000000000000000000000000000000}};
  int is_less = s21_is_less(value_1, value_2);
  ck_assert_int_eq(is_less, TRUE);
}
END_TEST
START_TEST(s21_is_less_10) {
  s21_decimal value_1 = {{0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111, 0}};

  s21_decimal value_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b10000000000000000}};
  int is_less = s21_is_less(value_1, value_2);
  ck_assert_int_eq(is_less, FALSE);
}
END_TEST
START_TEST(s21_is_less_11) {
  s21_decimal value_1 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b10000000000000000}};
  s21_decimal value_2 = {{0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111, 0}};
  int is_less = s21_is_less(value_1, value_2);
  ck_assert_int_eq(is_less, TRUE);
}
END_TEST

START_TEST(s21_is_less_12) {
  s21_decimal value_1 = {
      {0b10001100010001111001100000011111, 0b01100100101101000101010010111111,
       0b1101111100100010000011011001001, 0b11000000000000000000}};

  s21_decimal value_2 = {
      {0b11110100101010111110110000011111, 0b11101001001110100011011000011100,
       0b111001001011011011011, 0b10000000000100110000000000000000}};
  int is_less = s21_is_less(value_1, value_2);
  ck_assert_int_eq(is_less, FALSE);
}
END_TEST
START_TEST(s21_is_less_13) {
  s21_decimal value_1 = {
      {0b10001100010001111001100000011111, 0b01100100101101000101010010111111,
       0b1101111100100010000011011001001, 0b10000000000011000000000000000000}};
  s21_decimal value_2 = {{0b11110100101010111110110000011111,
                          0b11101001001110100011011000011100,
                          0b111001001011011011011, 0b100110000000000000000}};
  int is_less = s21_is_less(value_1, value_2);
  ck_assert_int_eq(is_less, TRUE);
}
END_TEST
START_TEST(s21_is_less_14) {
  s21_decimal value_1 = {
      {0b10001100010001111001100000011111, 0b01100100101101000101010010111111,
       0b1101111100100010000011011001001, 0b10000000000011000000000000000000}};
  s21_decimal value_2 = {
      {0b11110100101010111110110000011111, 0b11101001001110100011011000011100,
       0b111001001011011011011, 0b10000000000100110000000000000000}};
  int is_less = s21_is_less(value_1, value_2);
  ck_assert_int_eq(is_less, TRUE);
}
END_TEST
START_TEST(s21_is_less_15) {
  s21_decimal value_1 = {{0b1111011, 0, 0, 0}};

  s21_decimal value_2 = {{0b10110001101110110000000000000000,
                          0b10001000100011101011001111011, 0,
                          0b100000000000000000000}};
  int is_less = s21_is_less(value_1, value_2);
  ck_assert_int_eq(is_less, FALSE);
}
END_TEST
START_TEST(s21_is_less_16) {
  s21_decimal value_1 = {{0b1111011, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{0b10110001101110110000000000000000,
                          0b10001000100011101011001111011, 0,
                          0b10000000000100000000000000000000}};
  int is_less = s21_is_less(value_1, value_2);
  ck_assert_int_eq(is_less, FALSE);
}
END_TEST
START_TEST(s21_is_not_equal_1) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  int is_not_eq = s21_is_not_equal(value_1, value_2);
  ck_assert_uint_eq(is_not_eq, FALSE);
}
END_TEST
START_TEST(s21_is_not_equal_2) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0b111000000000000000000}};
  int is_not_eq = s21_is_not_equal(value_1, value_2);
  ck_assert_uint_eq(is_not_eq, FALSE);
}
END_TEST
START_TEST(s21_is_not_equal_3) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  int is_not_eq = s21_is_not_equal(value_1, value_2);
  ck_assert_uint_eq(is_not_eq, TRUE);
}
END_TEST
START_TEST(s21_is_not_equal_4) {
  s21_decimal value_1 = {{1, 2, 3, 0}};
  s21_decimal value_2 = {{1, 2, 4, 0}};
  int is_not_eq = s21_is_not_equal(value_1, value_2);
  ck_assert_uint_eq(is_not_eq, TRUE);
}
END_TEST
START_TEST(s21_is_not_equal_5) {
  s21_decimal value_1 = {{1, 2, 3, 0}};
  s21_decimal value_2 = {{1, 2, 3, 0b10000000000000000000000000000000}};
  int is_not_eq = s21_is_not_equal(value_1, value_2);
  ck_assert_uint_eq(is_not_eq, TRUE);
}
END_TEST
START_TEST(s21_is_not_equal_6) {
  s21_decimal value_1 = {{1, 2, 3, 0}};
  s21_decimal value_2 = {{1, 2, 3, 0b10000000000000000}};
  int is_not_eq = s21_is_not_equal(value_1, value_2);
  ck_assert_uint_eq(is_not_eq, TRUE);
}
END_TEST
START_TEST(s21_is_not_equal_7) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_decimal value_2 = {{100, 0, 0, 0b10000000000000000}};
  int is_not_eq = s21_is_not_equal(value_1, value_2);
  ck_assert_uint_eq(is_not_eq, FALSE);
}
END_TEST
START_TEST(s21_is_not_equal_8) {
  s21_decimal value_1 = {{0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111, 0}};
  s21_decimal value_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b10000000000000000}};
  int is_not_eq = s21_is_not_equal(value_1, value_2);
  ck_assert_uint_eq(is_not_eq, TRUE);
}
END_TEST
START_TEST(s21_is_not_equal_9) {
  s21_decimal value_1 = {{0b10011001100110011001100110011001,
                          0b10011001100110011001100110011001,
                          0b11001100110011001100110011001, 0}};

  s21_decimal value_2 = {
      {0b11111111111111111111111111111010, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b10000000000000000}};
  int is_not_eq = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(is_not_eq, FALSE);
}
Suite *test_s21_equals(void) {
  Suite *s = suite_create("s21_equals");
  TCase *tc = tcase_create("s21_equals");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_is_equal_1);
  tcase_add_test(tc, s21_is_equal_2);
  tcase_add_test(tc, s21_is_equal_3);
  tcase_add_test(tc, s21_is_equal_4);
  tcase_add_test(tc, s21_is_equal_5);
  tcase_add_test(tc, s21_is_equal_6);
  tcase_add_test(tc, s21_is_equal_7);
  tcase_add_test(tc, s21_is_equal_8);
  tcase_add_test(tc, s21_is_equal_9);
  tcase_add_test(tc, s21_is_equal_10);
  tcase_add_test(tc, s21_is_equal_11);
  tcase_add_test(tc, s21_is_equal_12);
  tcase_add_test(tc, s21_is_equal_13);
  tcase_add_test(tc, s21_is_equal_14);
  tcase_add_test(tc, s21_is_equal_15);
  tcase_add_test(tc, s21_is_equal_16);
  tcase_add_test(tc, s21_is_equal_17);
  tcase_add_test(tc, s21_is_equal_18);
  tcase_add_test(tc, s21_is_equal_19);
  tcase_add_test(tc, s21_is_equal_20);
  tcase_add_test(tc, s21_is_greater_or_equal_1);
  tcase_add_test(tc, s21_is_greater_or_equal_2);
  tcase_add_test(tc, s21_is_greater_or_equal_3);
  tcase_add_test(tc, s21_is_greater_or_equal_4);
  tcase_add_test(tc, s21_is_greater_or_equal_5);
  tcase_add_test(tc, s21_is_greater_or_equal_6);
  tcase_add_test(tc, s21_is_greater_or_equal_7);
  tcase_add_test(tc, s21_is_greater_or_equal_8);
  tcase_add_test(tc, s21_is_greater_or_equal_9);
  tcase_add_test(tc, s21_is_greater_or_equal_10);
  tcase_add_test(tc, s21_is_greater_1);
  tcase_add_test(tc, s21_is_greater_2);
  tcase_add_test(tc, s21_is_greater_3);
  tcase_add_test(tc, s21_is_greater_4);
  tcase_add_test(tc, s21_is_greater_5);
  tcase_add_test(tc, s21_is_greater_6);
  tcase_add_test(tc, s21_is_greater_7);
  tcase_add_test(tc, s21_is_greater_8);
  tcase_add_test(tc, s21_is_greater_9);
  tcase_add_test(tc, s21_is_greater_10);
  tcase_add_test(tc, s21_is_greater_11);
  tcase_add_test(tc, s21_is_less_or_equal_1);
  tcase_add_test(tc, s21_is_less_or_equal_2);
  tcase_add_test(tc, s21_is_less_or_equal_3);
  tcase_add_test(tc, s21_is_less_or_equal_4);
  tcase_add_test(tc, s21_is_less_or_equal_5);
  tcase_add_test(tc, s21_is_less_or_equal_6);
  tcase_add_test(tc, s21_is_less_or_equal_7);
  tcase_add_test(tc, s21_is_less_or_equal_8);
  tcase_add_test(tc, s21_is_less_or_equal_9);
  tcase_add_test(tc, s21_is_less_or_equal_10);
  tcase_add_test(tc, s21_is_less_1);
  tcase_add_test(tc, s21_is_less_2);
  tcase_add_test(tc, s21_is_less_3);
  tcase_add_test(tc, s21_is_less_4);
  tcase_add_test(tc, s21_is_less_5);
  tcase_add_test(tc, s21_is_less_6);
  tcase_add_test(tc, s21_is_less_7);
  tcase_add_test(tc, s21_is_less_8);
  tcase_add_test(tc, s21_is_less_9);
  tcase_add_test(tc, s21_is_less_10);
  tcase_add_test(tc, s21_is_less_11);
  tcase_add_test(tc, s21_is_less_12);
  tcase_add_test(tc, s21_is_less_13);
  tcase_add_test(tc, s21_is_less_14);
  tcase_add_test(tc, s21_is_less_15);
  tcase_add_test(tc, s21_is_less_16);
  tcase_add_test(tc, s21_is_not_equal_1);
  tcase_add_test(tc, s21_is_not_equal_2);
  tcase_add_test(tc, s21_is_not_equal_3);
  tcase_add_test(tc, s21_is_not_equal_4);
  tcase_add_test(tc, s21_is_not_equal_5);
  tcase_add_test(tc, s21_is_not_equal_6);
  tcase_add_test(tc, s21_is_not_equal_7);
  tcase_add_test(tc, s21_is_not_equal_8);
  tcase_add_test(tc, s21_is_not_equal_9);
  return s;
}
