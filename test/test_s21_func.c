#include <limits.h>

#include "test.h"

START_TEST(s21_floor_1) {
  s21_decimal value = {{1, 2, 3, 917504}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_floor(value, &result);
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(result.bits[0], 553402);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(s21_floor_2) {
  s21_decimal value = {{1, 2, 3, 0b10000000000011000000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_floor(value, &result);
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(result.bits[0], 55340233);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 2147483648);
}
END_TEST

START_TEST(s21_floor_3) {
  s21_decimal value = {{10, 100, 3, 1376256}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_floor(value, &result);
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(s21_floor_4) {
  s21_decimal value = {{0, 0, 0, 851968}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_floor(value, &result);
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(s21_floor_5) {
  s21_decimal value = {{1, 1, 1, 917504}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_floor(value, &result);
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(result.bits[0], 184467);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(s21_floor_6) {
  s21_decimal value = {{1, 1, 1, 65536}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_floor(value, &result);
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(result.bits[0], 3006477107);
  ck_assert_int_eq(result.bits[1], 429496729);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(s21_floor_7) {
  s21_decimal value = {{1, 1, 1, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_floor(value, &result);
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(result.bits[0], 1);
  ck_assert_int_eq(result.bits[1], 1);
  ck_assert_int_eq(result.bits[2], 1);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(s21_floor_8) {
  s21_decimal value = {{178532910, 4081246736, 2119837296, 2149384192}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_floor(value, &result);

  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST
START_TEST(s21_negate_1) {
  s21_decimal value = {{1, 2, 3, 917504}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_negate(value, &result);
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(result.bits[0], 1);
  ck_assert_int_eq(result.bits[1], 2);
  ck_assert_int_eq(result.bits[2], 3);
  ck_assert_int_eq(result.bits[3], 2148401152);
}
END_TEST

START_TEST(s21_negate_2) {
  s21_decimal value = {{1, 2, 3, 2148401152}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_negate(value, &result);
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(result.bits[0], 1);
  ck_assert_int_eq(result.bits[1], 2);
  ck_assert_int_eq(result.bits[2], 3);
  ck_assert_int_eq(result.bits[3], 917504);
}
END_TEST

START_TEST(s21_negate_3) {
  s21_decimal value = {{10, 100, 3, 1376256}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_negate(value, &result);
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(result.bits[0], 10);
  ck_assert_int_eq(result.bits[1], 100);
  ck_assert_int_eq(result.bits[2], 3);
  ck_assert_int_eq(result.bits[3], 2148859904);
}
END_TEST

START_TEST(s21_negate_4) {
  s21_decimal value = {{32444, 100, 343253, 2148401152}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_negate(value, &result);
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(result.bits[0], 32444);
  ck_assert_int_eq(result.bits[1], 100);
  ck_assert_int_eq(result.bits[2], 343253);
  ck_assert_int_eq(result.bits[3], 917504);
}
END_TEST

START_TEST(s21_negate_5) {
  s21_decimal value = {{178532910, 4081246736, 2119837296, 2149384192}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_negate(value, &result);

  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST
START_TEST(s21_round_1) {
  s21_decimal value = {{1, 0, 1, 917504}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_round(value, &result);
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(result.bits[0], 184467);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(s21_round_2) {
  s21_decimal value = {{1, 15, 1, 655360}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_round(value, &result);
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(result.bits[0], 1844674414);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(s21_round_3) {
  s21_decimal value = {{16491, 0, 0, 0b00000000000000110000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_round(value, &result);
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(result.bits[0], 16);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(s21_round_4) {
  s21_decimal value = {{16491, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_round(value, &result);
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(result.bits[0], 16491);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(s21_round_5) {
  s21_decimal value = {{16501, 0, 0, 0b00000000000000110000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_round(value, &result);
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(result.bits[0], 17);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(s21_round_6) {
  s21_decimal value = {{178532910, 4081246736, 2119837296, 2149384192}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(value, &result);

  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(s21_round_7) {
  s21_decimal value = {{15507, 0, 0, 0b10000000000000110000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_round(value, &result);
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(result.bits[0], 16);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(s21_round_8) {
  s21_decimal value = {{15407, 0, 0, 0b10000000000000110000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_round(value, &result);
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(result.bits[0], 15);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0b10000000000000000000000000000000);
}
END_TEST
START_TEST(s21_truncate_1) {
  s21_decimal value = {{1, 2, 3, 0b11100000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_truncate(value, &result);
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(result.bits[0], 553402);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(s21_truncate_2) {
  s21_decimal value = {{10, 100, 3, 1376256}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_truncate(value, &result);
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(s21_truncate_3) {
  s21_decimal value = {{1, 0, 0, 655360}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_truncate(value, &result);
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(s21_truncate_4) {
  s21_decimal value = {{1272343, 0, 0, 262144}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_truncate(value, &result);
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(result.bits[0], 127);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(s21_truncate_5) {
  s21_decimal value = {{2, 4, 8, 0b10000000000110100000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_truncate(value, &result);
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(s21_truncate_6) {
  s21_decimal value = {{178532910, 4081246736, 2119837296, 2149253120}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_truncate(value, &result);
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(result.bits[0], 39);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 2147483648);
}
END_TEST

START_TEST(s21_truncate_7) {
  s21_decimal value = {{77, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_truncate(value, &result);
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(result.bits[0], 77);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(s21_truncate_8) {
  s21_decimal value = {{178532910, 4081246736, 2119837296, 2149384192}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(value, &result);

  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(s21_truncate_9) {
  s21_decimal value = {{167000, 0, 0, 0b00000000000000110000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error = s21_truncate(value, &result);
  ck_assert_int_eq(error, OK);

  ck_assert_int_eq(result.bits[0], 167);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

Suite *test_s21_func(void) {
  Suite *s = suite_create("s21_func");
  TCase *tc = tcase_create("s21_func");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_floor_1);
  tcase_add_test(tc, s21_floor_2);
  tcase_add_test(tc, s21_floor_3);
  tcase_add_test(tc, s21_floor_4);
  tcase_add_test(tc, s21_floor_5);
  tcase_add_test(tc, s21_floor_6);
  tcase_add_test(tc, s21_floor_7);
  tcase_add_test(tc, s21_floor_8);
  tcase_add_test(tc, s21_negate_1);
  tcase_add_test(tc, s21_negate_2);
  tcase_add_test(tc, s21_negate_3);
  tcase_add_test(tc, s21_negate_4);
  tcase_add_test(tc, s21_negate_5);
  tcase_add_test(tc, s21_round_1);
  tcase_add_test(tc, s21_round_2);
  tcase_add_test(tc, s21_round_3);
  tcase_add_test(tc, s21_round_4);
  tcase_add_test(tc, s21_round_5);
  tcase_add_test(tc, s21_round_6);
  tcase_add_test(tc, s21_round_7);
  tcase_add_test(tc, s21_round_8);
  tcase_add_test(tc, s21_truncate_1);
  tcase_add_test(tc, s21_truncate_2);
  tcase_add_test(tc, s21_truncate_3);
  tcase_add_test(tc, s21_truncate_4);
  tcase_add_test(tc, s21_truncate_5);
  tcase_add_test(tc, s21_truncate_6);
  tcase_add_test(tc, s21_truncate_7);
  tcase_add_test(tc, s21_truncate_8);
  tcase_add_test(tc, s21_truncate_9);
  return s;
}
