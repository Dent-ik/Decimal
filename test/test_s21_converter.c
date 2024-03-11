#include "test.h"

START_TEST(s21_from_decimal_to_float_01) {
  s21_decimal src_decimal = {
      .bits = {0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  float dst_float;
  float etalon_float = 0.f;
  int s21_error = s21_from_decimal_to_float(src_decimal, &dst_float);
  ck_assert_float_eq(etalon_float, dst_float);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_float_02) {
  s21_decimal src_decimal = {
      .bits = {0x00000000, 0x00000000, 0x00000000, 0x80000000}};
  float dst_float;
  float etalon_float = -0.f;
  int s21_error = s21_from_decimal_to_float(src_decimal, &dst_float);
  ck_assert_float_eq(etalon_float, dst_float);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_float_03) {
  s21_decimal src_decimal = {
      .bits = {0x00000C8E, 0x00000000, 0x00000000, 0x80010000}};
  float dst_float;
  float etalon_float = -321.4f;
  int s21_error = s21_from_decimal_to_float(src_decimal, &dst_float);
  ck_assert_float_eq(etalon_float, dst_float);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_float_04) {
  s21_decimal src_decimal = {
      .bits = {0x3FC56AB0, 0x00000000, 0x00000000, 0x801C0000}};
  float dst_float;
  float etalon_float = -0.0000000000000000001069902512f;
  int s21_error = s21_from_decimal_to_float(src_decimal, &dst_float);
  ck_assert_float_eq(etalon_float, dst_float);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_float_05) {
  s21_decimal src_decimal = {
      .bits = {0x00000001, 0x00000000, 0x00000000, 0x001C0000}};
  float dst_float;
  float etalon_float = 0.0000000000000000000000000001f;
  int s21_error = s21_from_decimal_to_float(src_decimal, &dst_float);
  ck_assert_float_eq(etalon_float, dst_float);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_float_06) {
  s21_decimal src_decimal = {
      .bits = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  float dst_float;
  float etalon_float = 7.9228162514264337593543950335f;
  int s21_error = s21_from_decimal_to_float(src_decimal, &dst_float);
  ck_assert_float_eq(etalon_float, dst_float);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_float_07) {
  s21_decimal src_decimal = {
      .bits = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  float dst_float;
  float etalon_float = 79228162514264337593543950335.f;
  int s21_error = s21_from_decimal_to_float(src_decimal, &dst_float);
  ck_assert_float_eq(etalon_float, dst_float);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_float_08) {
  s21_decimal src_decimal = {
      .bits = {0x0004F3AC, 0x00000000, 0x00000000, 0x00060000}};
  float dst_float;
  float etalon_float = 0.324524f;
  int s21_error = s21_from_decimal_to_float(src_decimal, &dst_float);
  ck_assert_float_eq(etalon_float, dst_float);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_float_09) {
  s21_decimal src_decimal = {
      .bits = {0x0008FD43, 0x00000000, 0x00000000, 0x000A0000}};
  float dst_float;
  float etalon_float = 0.0000589123f;
  int s21_error = s21_from_decimal_to_float(src_decimal, &dst_float);
  ck_assert_float_eq(etalon_float, dst_float);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_float_10) {
  s21_decimal src_decimal = {
      .bits = {0x0382EE63, 0x00000000, 0x00000000, 0x00050000}};
  float dst_float;
  float etalon_float = 589.12355;
  int s21_error = s21_from_decimal_to_float(src_decimal, &dst_float);
  ck_assert_float_eq(etalon_float, dst_float);
  ck_assert_int_eq(0, s21_error);
}
END_TEST
START_TEST(s21_from_decimal_to_int_01) {
  s21_decimal src_decimal = {.bits = {0x00000000, 0, 0, 0x00000000}};
  int dst_int;
  int etalon_int = 0;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_02) {
  s21_decimal src_decimal = {.bits = {0x00000000, 0, 0, 0x80000000}};
  int dst_int;
  int etalon_int = 0;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_03) {
  s21_decimal src_decimal = {.bits = {0x00000C8E, 0, 0, 0x00010000}};
  int dst_int;
  int etalon_int = 321;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_04) {
  s21_decimal src_decimal = {.bits = {0x00000C8E, 0, 0, 0x80010000}};
  int dst_int;
  int etalon_int = -321;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_05) {
  s21_decimal src_decimal = {.bits = {0x00000141, 0, 0, 0x00030000}};
  int dst_int;
  int etalon_int = 0;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_06) {
  s21_decimal src_decimal = {.bits = {0x00000141, 0, 0, 0x80030000}};
  int dst_int;
  int etalon_int = 0;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_07) {
  s21_decimal src_decimal = {.bits = {0x00007DA7, 0, 0, 0x00020000}};
  int dst_int;
  int etalon_int = 321;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_08) {
  s21_decimal src_decimal = {.bits = {0x00007DA7, 0, 0, 0x80020000}};
  int dst_int;
  int etalon_int = -321;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_09) {
  s21_decimal src_decimal = {.bits = {0x00000141, 0, 0, 0x00000000}};
  int dst_int;
  int etalon_int = 321;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_10) {
  s21_decimal src_decimal = {.bits = {0x00000141, 0, 0, 0x80000000}};
  int dst_int;
  int etalon_int = -321;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_11) {
  s21_decimal src_decimal = {.bits = {0x01E9FED9, 0, 0, 0x00050000}};
  int dst_int;
  int etalon_int = 321;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_12) {
  s21_decimal src_decimal = {.bits = {0x01E9FED9, 0, 0, 0x80050000}};
  int dst_int;
  int etalon_int = -321;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_13) {
  s21_decimal src_decimal = {.bits = {INT_MAX, 0, 0, 0x00000000}};
  int dst_int;
  int etalon_int = INT_MAX;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_14) {
  s21_decimal src_decimal = {.bits = {2147483648U, 0, 0, 0x80000000}};
  int dst_int;
  int etalon_int = INT_MIN;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_15) {
  s21_decimal src_decimal = {.bits = {0x00000001, 0, 0, 0x001C0000}};
  int dst_int;
  int etalon_int = 0;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_16) {
  s21_decimal src_decimal = {.bits = {0x00000001, 0, 0, 0x801C0000}};
  int dst_int;
  int etalon_int = 0;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_17) {
  s21_decimal src_decimal = {
      .bits = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  int dst_int;
  int etalon_int = 7;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_18) {
  s21_decimal src_decimal = {
      .bits = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  int dst_int;
  int etalon_int = -7;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_19) {
  s21_decimal src_decimal = {.bits = {0xFFFFFFFF, 0, 0, 0x00000000}};
  int dst_int = 0;
  int etalon_int = 0;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(1, s21_error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_20) {
  s21_decimal src_decimal = {.bits = {0xFFFFFFFF, 0, 0, 0x80000000}};
  int dst_int = 0;
  int etalon_int = 0;
  int s21_error = s21_from_decimal_to_int(src_decimal, &dst_int);
  ck_assert_int_eq(etalon_int, dst_int);
  ck_assert_int_eq(1, s21_error);
}
END_TEST
START_TEST(s21_from_float_to_decimal_001) {
  float src_float = 1.0f / 0.0f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {.bits = {0, 0, 0, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(1, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_002) {
  float src_float = -1.0f / 0.0f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {.bits = {0, 0, 0, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(1, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_003) {
  float src_float = 0.0f / 0.0f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {.bits = {0, 0, 0, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(1, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_004) {
  float src_float = -321.2f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {.bits = {0x00000C8C, 0, 0, 0x80010000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_005) {
  float src_float = 321213152.f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {.bits = {0x13255310, 0, 0, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_006) {
  float src_float = 9732131234575756436473.f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xC7238000, 0x9472ED75, 0x0000020F, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_007) {
  float src_float = 73.329959999f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {.bits = {0x006FE484, 0, 0, 0x00050000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_008) {
  float src_float = 0.00312345f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {.bits = {0x0004C419, 0, 0, 0x00080000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_009) {
  float src_float = 0.00000003123959595945f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {.bits = {0x0004C44C, 0, 0, 0x000D0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_010) {
  float src_float = 0.00000000000000000000000000013929383838292f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {.bits = {0x00000001, 0, 0, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_011) {
  float src_float = 0.000000000000000000000000000000001939293838382f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {.bits = {0, 0, 0, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(1, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_012) {
  float src_float = 2183182381923912939123.365656f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x8ADB0000, 0x59BC8E01, 0x00000076, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_013) {
  float src_float = 79215000000000000000000000000.f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xCF000000, 0xAC05AE5D, 0xFFF51CBA, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

int a = 0b111111111111010100011101;

START_TEST(s21_from_float_to_decimal_014) {
  float src_float = 7015000000000000000000000000.f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xC7000000, 0xFFD18396, 0x16AAAC07, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_015) {
  float src_float = 0.00000000000000000000000005646473736464f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {.bits = {0x00000235, 0, 0, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_016) {
  float src_float = 0.0000000000000000000007373636f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {.bits = {0x00708344, 0, 0, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_017) {
  float src_float = 0.0000000000000000000008585982f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {.bits = {0x008302FE, 0, 0, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_018) {
  float src_float = 0.0000000000000000099999999999f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {.bits = {0x00000001, 0, 0, 0x00110000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_019) {
  float src_float = 0.000000000000000000007376667f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {.bits = {0x00708F1B, 0, 0, 0x001B0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_020) {
  float src_float = 0.0000000000000000000073736361612636f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {.bits = {0x00708344, 0, 0, 0x001B0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_021) {
  float src_float = 0.99999999f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {.bits = {0x00000001, 0, 0, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_022) {
  float src_float = -1.307818E+07f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00C78EA4, 0x00000000, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_023) {
  float src_float = -30914.76f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x002F2C14, 0x00000000, 0x00000000, 0x80020000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_024) {
  float src_float = 1.9999999;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00000002, 0x00000000, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_025) {
  float src_float = -750.9904f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00729790, 0x00000000, 0x00000000, 0x80040000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_026) {
  float src_float = 72932.2f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x000B20EA, 0x00000000, 0x00000000, 0x00010000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_027) {
  float src_float = 7.526432E-06f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0072D820, 0x00000000, 0x00000000, 0x000C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_028) {
  float src_float = 0.00000000000000000000000000016929383838292f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {.bits = {0x00000002, 0, 0, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_029) {
  float src_float = -1.391184E+17f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x9DB88000, 0x01EE3F72, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_030) {
  float src_float = 3.693497E-09f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00385BB9, 0x00000000, 0x00000000, 0x000F0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_031) {
  float src_float = 351871.4f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0035B0FA, 0x00000000, 0x00000000, 0x00010000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_032) {
  float src_float = 0.1175977f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0011F1A9, 0x00000000, 0x00000000, 0x00070000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_033) {
  float src_float = -2.013319E-14f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x001EB887, 0x00000000, 0x00000000, 0x80140000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_034) {
  float src_float = -280.7036f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x002AD4FC, 0x00000000, 0x00000000, 0x80040000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_035) {
  float src_float = -3.196059E+18f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x2030B000, 0x2C5AAEBA, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_036) {
  float src_float = -1.38892E+14f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x50527800, 0x00007E52, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_037) {
  float src_float = 6.068951E+09f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x69BCD7D8, 0x00000001, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_038) {
  float src_float = -1.190043E+24f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xF98C0000, 0x5C3C75F5, 0x0000FC00, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_039) {
  float src_float = 4.511203E-27f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0000002D, 0x00000000, 0x00000000, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_040) {
  float src_float = -7.442655E+23f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x1B360000, 0xB6AE8261, 0x00009D9A, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_041) {
  float src_float = 8.763741E+26f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x8CD00000, 0x28107A63, 0x02D4EB6F, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_042) {
  float src_float = -5.447201E-28f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00000005, 0x00000000, 0x00000000, 0x801C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_043) {
  float src_float = 1.333345E+13f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x6F8D0680, 0x00000C20, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_044) {
  float src_float = -3.85058E-06f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0005E022, 0x00000000, 0x00000000, 0x800B0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_045) {
  float src_float = 1.325723E-09f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00143A9B, 0x00000000, 0x00000000, 0x000F0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_046) {
  float src_float = -5.831514E+23f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x30840000, 0xB3639777, 0x00007B7C, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_047) {
  float src_float = -1.337444E-22f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00146864, 0x00000000, 0x00000000, 0x801C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_048) {
  float src_float = 1.230342E+28f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xAD800000, 0xA66BA8BD, 0x27C12686, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_049) {
  float src_float = -8.335803E-07f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x007F31BB, 0x00000000, 0x00000000, 0x800D0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_050) {
  float src_float = 9.197;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x000023ED, 0x00000000, 0x00000000, 0x00030000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_051) {
  float src_float = 2.922531E+25f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x9AB80000, 0x3ACC2F60, 0x00182CB3, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_052) {
  float src_float = 1.581408E+19f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x319C0000, 0xDB76E5F9, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_053) {
  float src_float = -3.22218E-27f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00000020, 0x00000000, 0x00000000, 0x801C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_054) {
  float src_float = 1.290434E-09f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0013B0C2, 0x00000000, 0x00000000, 0x000F0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_055) {
  float src_float = -1.162378E-20f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0011BC8A, 0x00000000, 0x00000000, 0x801A0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_056) {
  float src_float = -1.609435E+11f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x78FAEAE0, 0x00000025, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_057) {
  float src_float = -2.747507E-06f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0029EC73, 0x00000000, 0x00000000, 0x800C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_058) {
  float src_float = -2.233666E-28f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00000002, 0x00000000, 0x00000000, 0x801C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_059) {
  float src_float = -9.564972E-05f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0091F32C, 0x00000000, 0x00000000, 0x800B0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_060) {
  float src_float = 6.76729E-11f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x000A5379, 0x00000000, 0x00000000, 0x00100000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_061) {
  float src_float = -1.56421E+08f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0952CB88, 0x00000000, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_062) {
  float src_float = 1.248784E-11f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00130E10, 0x00000000, 0x00000000, 0x00110000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_063) {
  float src_float = 3.830389E-28f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00000004, 0x00000000, 0x00000000, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_064) {
  float src_float = -7.518575E+13f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x8BEBC180, 0x00004461, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_065) {
  float src_float = 1.759471E+20f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0821C000, 0x89C1AB3E, 0x00000009, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_066) {
  float src_float = -1.730171E+16f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x468E8C00, 0x003D77D0, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_067) {
  float src_float = -0.005833615f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0059038F, 0x00000000, 0x00000000, 0x80090000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_068) {
  float src_float = -1.083782E+27f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x27C00000, 0xF1EDC3B6, 0x03807BC3, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_069) {
  float src_float = -2.543952E+11f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x3B22B200, 0x0000003B, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_070) {
  float src_float = 8.122079E+09f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xE41D1718, 0x00000001, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_071) {
  float src_float = -1.381688E-13f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00151538, 0x00000000, 0x00000000, 0x80130000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_072) {
  float src_float = 5.3419E+17f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x8890E000, 0x0769D2F9, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_073) {
  float src_float = -1.899235E+25f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xD8B80000, 0x5B459112, 0x000FB5C9, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_074) {
  float src_float = 0.01434358f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0015E2F6, 0x00000000, 0x00000000, 0x00080000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_075) {
  float src_float = -8.395913E+08f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x320B2584, 0x00000000, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_076) {
  float src_float = 2.963941E-09f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x002D39E5, 0x00000000, 0x00000000, 0x000F0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_077) {
  float src_float = -4.554593f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00457F61, 0x00000000, 0x00000000, 0x80060000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_078) {
  float src_float = 1.511913E-20f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x001711E9, 0x00000000, 0x00000000, 0x001A0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_079) {
  float src_float = 12.18852f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00129924, 0x00000000, 0x00000000, 0x00050000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_080) {
  float src_float = 8.216155E-11f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x007D5E5B, 0x00000000, 0x00000000, 0x00110000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_081) {
  float src_float = -0.7325138f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x006FC5D2, 0x00000000, 0x00000000, 0x80070000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_082) {
  float src_float = 49394.41f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x004B5EB1, 0x00000000, 0x00000000, 0x00020000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_083) {
  float src_float = 0.0002621874f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x002801B2, 0x00000000, 0x00000000, 0x000A0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_084) {
  float src_float = 5.880856E+15f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x7CDAF000, 0x0014E49B, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_085) {
  float src_float = -7.048725E-24f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00011357, 0x00000000, 0x00000000, 0x801C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_086) {
  float src_float = 1.661392E-16f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x001959D0, 0x00000000, 0x00000000, 0x00160000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_087) {
  float src_float = -3.749618E-17f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x003936F2, 0x00000000, 0x00000000, 0x80170000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_088) {
  float src_float = -1.078071E+10f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x82949470, 0x00000002, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_089) {
  float src_float = -942.165f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x000E6055, 0x00000000, 0x00000000, 0x80030000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_090) {
  float src_float = 8.128622E+24f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0CF80000, 0x7B4932DD, 0x0006B94D, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_091) {
  float src_float = 3.478075E-10f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0035123B, 0x00000000, 0x00000000, 0x00100000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_092) {
  float src_float = -0.2220105f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0021E049, 0x00000000, 0x00000000, 0x80070000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_093) {
  float src_float = -4.057507E-11f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x003DE9A3, 0x00000000, 0x00000000, 0x80110000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_094) {
  float src_float = -7.703651E+13f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x75D03380, 0x00004610, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_095) {
  float src_float = 4.329224E-09f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00420F08, 0x00000000, 0x00000000, 0x000F0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_096) {
  float src_float = -3.238849E-06f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00316BC1, 0x00000000, 0x00000000, 0x800C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_097) {
  float src_float = -5.937755E-18f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x005A9A5B, 0x00000000, 0x00000000, 0x80180000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_098) {
  float src_float = 9.214601E-09f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x008C9A89, 0x00000000, 0x00000000, 0x000F0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_099) {
  float src_float = -2.788572E+14f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x80595C00, 0x0000FD9E, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_100) {
  float src_float = -0.2386963f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00246C13, 0x00000000, 0x00000000, 0x80070000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_101) {
  float src_float = -4.803305E-20f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00494AE9, 0x00000000, 0x00000000, 0x801A0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_102) {
  float src_float = -6.715998E+27f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xFEC00000, 0x19B4CE7F, 0x15B357E5, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_103) {
  float src_float = 1.001074E+27f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xE3400000, 0x47EB885C, 0x033C11AA, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_104) {
  float src_float = 1.061498E+12f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x26361280, 0x000000F7, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_105) {
  float src_float = -5.398762E+13f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xF8E99100, 0x00003119, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_106) {
  float src_float = 2.011937E-05f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x001EB321, 0x00000000, 0x00000000, 0x000B0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_107) {
  float src_float = 1.208047E+28f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xE9C00000, 0xEEAB1663, 0x2708BB06, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_108) {
  float src_float = -3.577309f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x003695DD, 0x00000000, 0x00000000, 0x80060000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_109) {
  float src_float = -0.01349936f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00149930, 0x00000000, 0x00000000, 0x80080000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_110) {
  float src_float = 2.636795E+21f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x4E1F8000, 0xF0E1AA29, 0x0000008E, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_111) {
  float src_float = 1.886762E+28f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xBE800000, 0xAE79E847, 0x3CF6EDF1, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_112) {
  float src_float = 1.137225E+20f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xED5C4000, 0x2A377B38, 0x00000006, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_113) {
  float src_float = 2.03361E-23f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00031A61, 0x00000000, 0x00000000, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_114) {
  float src_float = -3.082871E+14f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xAF159700, 0x00011862, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_115) {
  float src_float = -4.087111E-10f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x003E5D47, 0x00000000, 0x00000000, 0x80100000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_116) {
  float src_float = -1.082272E+23f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x14400000, 0x021DDBB8, 0x000016EB, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_117) {
  float src_float = -9.243464E-20f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x008D0B48, 0x00000000, 0x00000000, 0x801A0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_118) {
  float src_float = -1.351883E-11f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0014A0CB, 0x00000000, 0x00000000, 0x80110000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_119) {
  float src_float = 1.067036E+22f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x811C0000, 0x70FDEE02, 0x00000242, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_120) {
  float src_float = -1.655359E-07f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0019423F, 0x00000000, 0x00000000, 0x800D0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_121) {
  float src_float = -2.818527E-09f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x002B01DF, 0x00000000, 0x00000000, 0x800F0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_122) {
  float src_float = 2.024663E-23f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x000316E2, 0x00000000, 0x00000000, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_123) {
  float src_float = 2.310628E-10f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x002341E4, 0x00000000, 0x00000000, 0x00100000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_124) {
  float src_float = 2968.287f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x002D4ADF, 0x00000000, 0x00000000, 0x00030000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_125) {
  float src_float = 1.229755E-18f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0012C3BB, 0x00000000, 0x00000000, 0x00180000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_126) {
  float src_float = 1.059234E-14f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x001029A2, 0x00000000, 0x00000000, 0x00140000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_127) {
  float src_float = -64208.49f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0061F971, 0x00000000, 0x00000000, 0x80020000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_128) {
  float src_float = 2.186795E+15f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xE32BEE00, 0x0007C4E0, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_129) {
  float src_float = -2.191804E+07f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x014E7158, 0x00000000, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_130) {
  float src_float = 6.5419E-24f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0000FF8B, 0x00000000, 0x00000000, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_131) {
  float src_float = -1.152604E+26f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xF9C00000, 0xCDD8046A, 0x005F5756, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_132) {
  float src_float = 6.767653E+21f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0AB08000, 0xE00D62F0, 0x0000016E, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_133) {
  float src_float = -4.926002E+14f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x6BEFF200, 0x0001C004, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_134) {
  float src_float = 1.194919E+26f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x4F700000, 0xE0F3DC90, 0x0062D764, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_135) {
  float src_float = 0.2616035f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0027EAE3, 0x00000000, 0x00000000, 0x00070000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_136) {
  float src_float = -2.989957E+13f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x893FB080, 0x00001B31, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_137) {
  float src_float = -4.61851E-24f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0000B469, 0x00000000, 0x00000000, 0x801C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_138) {
  float src_float = -0.003898347f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x003B7BEB, 0x00000000, 0x00000000, 0x80090000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_139) {
  float src_float = 11.08692f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0010EAD4, 0x00000000, 0x00000000, 0x00050000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_140) {
  float src_float = -0.003970314f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x003C950A, 0x00000000, 0x00000000, 0x80090000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_141) {
  float src_float = 1.054338E-15f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00101682, 0x00000000, 0x00000000, 0x00150000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_142) {
  float src_float = -32.53767f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0031A607, 0x00000000, 0x00000000, 0x80050000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_143) {
  float src_float = 0.06596097f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0064A601, 0x00000000, 0x00000000, 0x00080000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_144) {
  float src_float = 8.861377E+25f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xE7E80000, 0x18E914DA, 0x00494CB2, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_145) {
  float src_float = 2.324943E-28f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00000002, 0x00000000, 0x00000000, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_146) {
  float src_float = 3191.227f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0030B1BB, 0x00000000, 0x00000000, 0x00030000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_147) {
  float src_float = 0.938446f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x000E51CE, 0x00000000, 0x00000000, 0x00060000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_148) {
  float src_float = -3.894784E-17f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x003B6E00, 0x00000000, 0x00000000, 0x80170000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_149) {
  float src_float = 7.679175E+14f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xB9CDE700, 0x0002BA6A, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_150) {
  float src_float = 9.389545E+08f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x37F74F04, 0x00000000, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_151) {
  float src_float = -8.570058E+07f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x051BAFE4, 0x00000000, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_152) {
  float src_float = 1.069406E-20f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0010515E, 0x00000000, 0x00000000, 0x001A0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_153) {
  float src_float = 1963320.0f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x001DF538, 0x00000000, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_154) {
  float src_float = 1631.409f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0018E4B1, 0x00000000, 0x00000000, 0x00030000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_155) {
  float src_float = -9.583782E-09f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00923CA6, 0x00000000, 0x00000000, 0x800F0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_156) {
  float src_float = 4.934571E+14f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xEF284B00, 0x0001C0CB, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_157) {
  float src_float = 10.23795f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x000F9F33, 0x00000000, 0x00000000, 0x00050000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_158) {
  float src_float = -703088.8f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x006B4868, 0x00000000, 0x00000000, 0x80010000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_159) {
  float src_float = -1.061253E+17f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xE82E8800, 0x01790865, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_160) {
  float src_float = 0.0001655871f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0019443F, 0x00000000, 0x00000000, 0x000A0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_161) {
  float src_float = -158.45f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00003DE5, 0x00000000, 0x00000000, 0x80020000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_162) {
  float src_float = 2.961945E+11f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xF69165A0, 0x00000044, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_163) {
  float src_float = -1.617612E-26f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x000000A2, 0x00000000, 0x00000000, 0x801C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_164) {
  float src_float = -212.0078f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0020598E, 0x00000000, 0x00000000, 0x80040000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_165) {
  float src_float = 1.683534E-20f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0019B04E, 0x00000000, 0x00000000, 0x001A0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_166) {
  float src_float = 1.360221E+25f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x01480000, 0x4818EABE, 0x000B4061, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_167) {
  float src_float = 4.304772E-15f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0041AF84, 0x00000000, 0x00000000, 0x00150000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_168) {
  float src_float = 2.341019E+14f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x18973B00, 0x0000D4EA, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_169) {
  float src_float = 2.241625E-06f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00223459, 0x00000000, 0x00000000, 0x000C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_170) {
  float src_float = -1.303562E-27f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0000000D, 0x00000000, 0x00000000, 0x801C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_171) {
  float src_float = 3.300137E-28f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00000003, 0x00000000, 0x00000000, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_172) {
  float src_float = -6.89053E+23f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xD4540000, 0xA35284BD, 0x000091E9, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_173) {
  float src_float = -1.335107E-17f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00145F43, 0x00000000, 0x00000000, 0x80170000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_174) {
  float src_float = 4.299471E+28f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xA1C00000, 0x5E84AF70, 0x8AEC63FB, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_175) {
  float src_float = 5.439797E-13f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00530135, 0x00000000, 0x00000000, 0x00130000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_176) {
  float src_float = 9283997.0f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x008DA99D, 0x00000000, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_177) {
  float src_float = -5.917783E-20f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x005A4C57, 0x00000000, 0x00000000, 0x801A0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_178) {
  float src_float = -4.605351E-08f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x004645A7, 0x00000000, 0x00000000, 0x800E0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_179) {
  float src_float = 3.67147E-07f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00059A2B, 0x00000000, 0x00000000, 0x000C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_180) {
  float src_float = 7.805752E-14f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00771B38, 0x00000000, 0x00000000, 0x00140000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_181) {
  float src_float = -4.665166E-28f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00000005, 0x00000000, 0x00000000, 0x801C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_182) {
  float src_float = 1.029686E+16f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x8A9A1800, 0x002494F0, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_183) {
  float src_float = -1.623241E+11f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xCB4533A0, 0x00000025, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_184) {
  float src_float = 0.01401084f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x001560FC, 0x00000000, 0x00000000, 0x00080000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_185) {
  float src_float = 16.07887f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x001888CF, 0x00000000, 0x00000000, 0x00050000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_186) {
  float src_float = -2.094895E+21f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x45F18000, 0x90821F45, 0x00000071, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_187) {
  float src_float = -4.274481E-16f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00413931, 0x00000000, 0x00000000, 0x80160000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_188) {
  float src_float = 7.869093E+14f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x994C0500, 0x0002CBB0, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_189) {
  float src_float = -1.272028E-09f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x001368DC, 0x00000000, 0x00000000, 0x800F0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_190) {
  float src_float = -5.217951E-12f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x004F9E9F, 0x00000000, 0x00000000, 0x80120000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_191) {
  float src_float = -386648.3f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x003AFF73, 0x00000000, 0x00000000, 0x80010000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_192) {
  float src_float = 3.61813E+09f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xD7A84850, 0x00000000, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_193) {
  float src_float = -109.3412f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0010AF24, 0x00000000, 0x00000000, 0x80040000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_194) {
  float src_float = 4.581238E+18f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x45856000, 0x3F93D3B0, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_195) {
  float src_float = -6.603116E-17f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0064C16C, 0x00000000, 0x00000000, 0x80170000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_196) {
  float src_float = -1.320119E+10f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x12DA2C70, 0x00000003, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_197) {
  float src_float = 2.82232E-12f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00044E78, 0x00000000, 0x00000000, 0x00110000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_198) {
  float src_float = -1.841507E+09f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x6DC32AB8, 0x00000000, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_199) {
  float src_float = -2.262675E-19f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00228693, 0x00000000, 0x00000000, 0x80190000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_200) {
  float src_float = 2.464824E-20f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00259C38, 0x00000000, 0x00000000, 0x001A0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_201) {
  float src_float = 1.511738E-07f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0017113A, 0x00000000, 0x00000000, 0x000D0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_202) {
  float src_float = 1.720869E-06f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x001A4225, 0x00000000, 0x00000000, 0x000C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_203) {
  float src_float = 8.188374E-27f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00000052, 0x00000000, 0x00000000, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_204) {
  float src_float = -10.51995f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00100D5B, 0x00000000, 0x00000000, 0x80050000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_205) {
  float src_float = 1.603923E+24f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x896C0000, 0xD70DD7BD, 0x000153A4, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_206) {
  float src_float = 119471.1f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00123AD7, 0x00000000, 0x00000000, 0x00010000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_207) {
  float src_float = 6.965003E+25f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x44F80000, 0xB125DD81, 0x00399CF7, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_208) {
  float src_float = 1.296483E+17f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x233BB800, 0x01CC9A71, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_209) {
  float src_float = -5.872053E+13f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xF054E880, 0x00003567, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_210) {
  float src_float = -1.481293E+23f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x26820000, 0x1AFE5755, 0x00001F5E, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_211) {
  float src_float = -2.851002E-18f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x002B80BA, 0x00000000, 0x00000000, 0x80180000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_212) {
  float src_float = 112195.3f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00111EA1, 0x00000000, 0x00000000, 0x00010000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_213) {
  float src_float = 1.039634E+08f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x06325B08, 0x00000000, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_214) {
  float src_float = 3.40683E+13f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x24EB6B00, 0x00001EFC, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_215) {
  float src_float = 6.772869E+11f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xB171F120, 0x0000009D, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_216) {
  float src_float = -1.268637E+15f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x91BBE200, 0x000481D1, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_217) {
  float src_float = -0.001798262f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x001B7076, 0x00000000, 0x00000000, 0x80090000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_218) {
  float src_float = -3.38201E-15f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00052919, 0x00000000, 0x00000000, 0x80140000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_219) {
  float src_float = -3.263142E-13f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0031CAA6, 0x00000000, 0x00000000, 0x80130000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_220) {
  float src_float = 1.231812E-27f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0000000C, 0x00000000, 0x00000000, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_221) {
  float src_float = 3.812988E+22f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xCF7C0000, 0x06623F3C, 0x00000813, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_222) {
  float src_float = 3.308621E+16f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x92039400, 0x00758BBB, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_223) {
  float src_float = -1.322553E-20f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00142E39, 0x00000000, 0x00000000, 0x801A0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_224) {
  float src_float = 1.148738E+08f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x06D8D5C8, 0x00000000, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_225) {
  float src_float = -1.991151E+10f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xA2D187F0, 0x00000004, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_226) {
  float src_float = 884496.5f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0086F6A5, 0x00000000, 0x00000000, 0x00010000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_227) {
  float src_float = 4.103006E-27f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00000029, 0x00000000, 0x00000000, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_228) {
  float src_float = 4.647867E-26f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x000001D1, 0x00000000, 0x00000000, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_229) {
  float src_float = 9.713084E+17f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xF55A6000, 0x0D7AC7D7, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_230) {
  float src_float = -2.557154E+19f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x6BB14000, 0x62E05C25, 0x00000001, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_231) {
  float src_float = -0.6512141f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00635E0D, 0x00000000, 0x00000000, 0x80070000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_232) {
  float src_float = 3.490169E+16f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xF282C400, 0x007BFEE6, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_233) {
  float src_float = 5.061718E-20f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x004D3C56, 0x00000000, 0x00000000, 0x001A0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_234) {
  float src_float = 6.59684E+22f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xEEE80000, 0x27750C6F, 0x00000DF8, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_235) {
  float src_float = -1.918654E-19f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x001D46BE, 0x00000000, 0x00000000, 0x80190000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_236) {
  float src_float = -1.215304E-18f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00128B48, 0x00000000, 0x00000000, 0x80180000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_237) {
  float src_float = -3.20701E-15f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x0004E4BD, 0x00000000, 0x00000000, 0x80140000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_238) {
  float src_float = -2.55141E+17f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x40A35000, 0x038A7163, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_239) {
  float src_float = -1.751754E+22f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x684A0000, 0xA0B3FA18, 0x000003B5, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_240) {
  float src_float = -1.188452E+26f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xD2400000, 0x3393C802, 0x00624E73, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_241) {
  float src_float = 3.866995E-25f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00000F1B, 0x00000000, 0x00000000, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_242) {
  float src_float = 44301.02f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00439916, 0x00000000, 0x00000000, 0x00020000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_243) {
  float src_float = 2.47909E-26f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x000000F8, 0x00000000, 0x00000000, 0x001C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_244) {
  float src_float = -3.094722E-11f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x002F38C2, 0x00000000, 0x00000000, 0x80110000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_245) {
  float src_float = -0.0001411886f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00158B2E, 0x00000000, 0x00000000, 0x800A0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_246) {
  float src_float = 4.721357E-18f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00480ACD, 0x00000000, 0x00000000, 0x00180000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_247) {
  float src_float = -6.247398E+10f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x8BBD4860, 0x0000000E, 0x00000000, 0x80000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_248) {
  float src_float = -1.663049E-18f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00196049, 0x00000000, 0x00000000, 0x80180000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_249) {
  float src_float = 4.894282E+14f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0xE2010A00, 0x0001BD21, 0x00000000, 0x00000000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_250) {
  float src_float = 7.748195E-06f;
  s21_decimal dst_decimal;
  s21_decimal etalon = {
      .bits = {0x00763A63, 0x00000000, 0x00000000, 0x000C0000}};
  int s21_error = s21_from_float_to_decimal(src_float, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST
START_TEST(s21_from_int_to_decimal_01) {
  int src_int = 0;
  s21_decimal etalon_decimal = {.bits = {0, 0, 0, 0x00000000}}, dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_02) {
  int src_int = 1;
  s21_decimal etalon_decimal = {.bits = {1, 0, 0, 0x00000000}}, dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_03) {
  int src_int = -1;
  s21_decimal etalon_decimal = {.bits = {1, 0, 0, 0x80000000}}, dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_04) {
  int src_int = INT_MAX;
  s21_decimal etalon_decimal = {.bits = {INT_MAX, 0, 0, 0x00000000}},
              dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_05) {
  int src_int = INT_MIN;
  s21_decimal etalon_decimal = {.bits = {2147483648U, 0, 0, 0x80000000}},
              dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_06) {
  int src_int = -12345;
  s21_decimal etalon_decimal = {.bits = {12345, 0, 0, 0x80000000}}, dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_07) {
  int src_int = 12345;
  s21_decimal etalon_decimal = {.bits = {12345, 0, 0, 0x00000000}}, dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_08) {
  int src_int = -0;
  s21_decimal etalon_decimal = {.bits = {0, 0, 0, 0x00000000}}, dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_09) {
  int src_int = 32167;
  s21_decimal etalon_decimal = {.bits = {32167, 0, 0, 0x00000000}}, dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_10) {
  int src_int = -32167;
  s21_decimal etalon_decimal = {.bits = {32167, 0, 0, 0x80000000}}, dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_11) {
  int src_int = -43543;
  s21_decimal etalon_decimal = {.bits = {43543, 0, 0, 0x80000000}}, dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_12) {
  int src_int = 43543;
  s21_decimal etalon_decimal = {.bits = {43543, 0, 0, 0x00000000}}, dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_13) {
  int src_int = -32767;
  s21_decimal etalon_decimal = {.bits = {32767, 0, 0, 0x80000000}}, dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_14) {
  int src_int = 32767;
  s21_decimal etalon_decimal = {.bits = {32767, 0, 0, 0x00000000}}, dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_15) {
  int src_int = -123456;
  s21_decimal etalon_decimal = {.bits = {123456, 0, 0, 0x80000000}},
              dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_16) {
  int src_int = 123456;
  s21_decimal etalon_decimal = {.bits = {123456, 0, 0, 0x00000000}},
              dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_17) {
  int src_int = -320167;
  s21_decimal etalon_decimal = {.bits = {320167, 0, 0, 0x80000000}},
              dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_18) {
  int src_int = 320167;
  s21_decimal etalon_decimal = {.bits = {320167, 0, 0, 0x00000000}},
              dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_19) {
  int src_int = -1234567890;
  s21_decimal etalon_decimal = {.bits = {1234567890, 0, 0, 0x80000000}},
              dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_20) {
  int src_int = 1234567890;
  s21_decimal etalon_decimal = {.bits = {1234567890, 0, 0, 0x00000000}},
              dst_decimal;
  int s21_error = s21_from_int_to_decimal(src_int, &dst_decimal);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(etalon_decimal.bits[i], dst_decimal.bits[i]);
  ck_assert_int_eq(0, s21_error);
}
END_TEST

Suite *test_s21_converter(void) {
  Suite *s = suite_create("s21_converter");
  TCase *tc = tcase_create("s21_converter");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_from_decimal_to_float_01);
  tcase_add_test(tc, s21_from_decimal_to_float_02);
  tcase_add_test(tc, s21_from_decimal_to_float_03);
  tcase_add_test(tc, s21_from_decimal_to_float_04);
  tcase_add_test(tc, s21_from_decimal_to_float_05);
  tcase_add_test(tc, s21_from_decimal_to_float_06);
  tcase_add_test(tc, s21_from_decimal_to_float_07);
  tcase_add_test(tc, s21_from_decimal_to_float_08);
  tcase_add_test(tc, s21_from_decimal_to_float_09);
  tcase_add_test(tc, s21_from_decimal_to_float_10);
  tcase_add_test(tc, s21_from_decimal_to_int_01);
  tcase_add_test(tc, s21_from_decimal_to_int_02);
  tcase_add_test(tc, s21_from_decimal_to_int_03);
  tcase_add_test(tc, s21_from_decimal_to_int_04);
  tcase_add_test(tc, s21_from_decimal_to_int_06);
  tcase_add_test(tc, s21_from_decimal_to_int_05);
  tcase_add_test(tc, s21_from_decimal_to_int_07);
  tcase_add_test(tc, s21_from_decimal_to_int_08);
  tcase_add_test(tc, s21_from_decimal_to_int_09);
  tcase_add_test(tc, s21_from_decimal_to_int_10);
  tcase_add_test(tc, s21_from_decimal_to_int_11);
  tcase_add_test(tc, s21_from_decimal_to_int_12);
  tcase_add_test(tc, s21_from_decimal_to_int_13);
  tcase_add_test(tc, s21_from_decimal_to_int_14);
  tcase_add_test(tc, s21_from_decimal_to_int_15);
  tcase_add_test(tc, s21_from_decimal_to_int_16);
  tcase_add_test(tc, s21_from_decimal_to_int_17);
  tcase_add_test(tc, s21_from_decimal_to_int_18);
  tcase_add_test(tc, s21_from_decimal_to_int_19);
  tcase_add_test(tc, s21_from_decimal_to_int_20);
  tcase_add_test(tc, s21_from_float_to_decimal_001);
  tcase_add_test(tc, s21_from_float_to_decimal_002);
  tcase_add_test(tc, s21_from_float_to_decimal_003);
  tcase_add_test(tc, s21_from_float_to_decimal_004);
  tcase_add_test(tc, s21_from_float_to_decimal_005);
  tcase_add_test(tc, s21_from_float_to_decimal_006);
  tcase_add_test(tc, s21_from_float_to_decimal_007);
  tcase_add_test(tc, s21_from_float_to_decimal_008);
  tcase_add_test(tc, s21_from_float_to_decimal_009);
  tcase_add_test(tc, s21_from_float_to_decimal_010);
  tcase_add_test(tc, s21_from_float_to_decimal_011);
  tcase_add_test(tc, s21_from_float_to_decimal_012);
  tcase_add_test(tc, s21_from_float_to_decimal_013);
  tcase_add_test(tc, s21_from_float_to_decimal_014);
  tcase_add_test(tc, s21_from_float_to_decimal_015);
  tcase_add_test(tc, s21_from_float_to_decimal_016);
  tcase_add_test(tc, s21_from_float_to_decimal_017);
  tcase_add_test(tc, s21_from_float_to_decimal_018);
  tcase_add_test(tc, s21_from_float_to_decimal_019);
  tcase_add_test(tc, s21_from_float_to_decimal_020);
  tcase_add_test(tc, s21_from_float_to_decimal_021);
  tcase_add_test(tc, s21_from_float_to_decimal_022);
  tcase_add_test(tc, s21_from_float_to_decimal_023);
  tcase_add_test(tc, s21_from_float_to_decimal_024);
  tcase_add_test(tc, s21_from_float_to_decimal_025);
  tcase_add_test(tc, s21_from_float_to_decimal_026);
  tcase_add_test(tc, s21_from_float_to_decimal_027);
  tcase_add_test(tc, s21_from_float_to_decimal_028);
  tcase_add_test(tc, s21_from_float_to_decimal_029);
  tcase_add_test(tc, s21_from_float_to_decimal_030);
  tcase_add_test(tc, s21_from_float_to_decimal_031);
  tcase_add_test(tc, s21_from_float_to_decimal_032);
  tcase_add_test(tc, s21_from_float_to_decimal_033);
  tcase_add_test(tc, s21_from_float_to_decimal_034);
  tcase_add_test(tc, s21_from_float_to_decimal_035);
  tcase_add_test(tc, s21_from_float_to_decimal_036);
  tcase_add_test(tc, s21_from_float_to_decimal_037);
  tcase_add_test(tc, s21_from_float_to_decimal_038);
  tcase_add_test(tc, s21_from_float_to_decimal_039);
  tcase_add_test(tc, s21_from_float_to_decimal_040);
  tcase_add_test(tc, s21_from_float_to_decimal_041);
  tcase_add_test(tc, s21_from_float_to_decimal_042);
  tcase_add_test(tc, s21_from_float_to_decimal_043);
  tcase_add_test(tc, s21_from_float_to_decimal_044);
  tcase_add_test(tc, s21_from_float_to_decimal_045);
  tcase_add_test(tc, s21_from_float_to_decimal_046);
  tcase_add_test(tc, s21_from_float_to_decimal_047);
  tcase_add_test(tc, s21_from_float_to_decimal_048);
  tcase_add_test(tc, s21_from_float_to_decimal_049);
  tcase_add_test(tc, s21_from_float_to_decimal_050);
  tcase_add_test(tc, s21_from_float_to_decimal_051);
  tcase_add_test(tc, s21_from_float_to_decimal_052);
  tcase_add_test(tc, s21_from_float_to_decimal_053);
  tcase_add_test(tc, s21_from_float_to_decimal_054);
  tcase_add_test(tc, s21_from_float_to_decimal_055);
  tcase_add_test(tc, s21_from_float_to_decimal_056);
  tcase_add_test(tc, s21_from_float_to_decimal_057);
  tcase_add_test(tc, s21_from_float_to_decimal_058);
  tcase_add_test(tc, s21_from_float_to_decimal_059);
  tcase_add_test(tc, s21_from_float_to_decimal_060);
  tcase_add_test(tc, s21_from_float_to_decimal_061);
  tcase_add_test(tc, s21_from_float_to_decimal_062);
  tcase_add_test(tc, s21_from_float_to_decimal_063);
  tcase_add_test(tc, s21_from_float_to_decimal_064);
  tcase_add_test(tc, s21_from_float_to_decimal_065);
  tcase_add_test(tc, s21_from_float_to_decimal_066);
  tcase_add_test(tc, s21_from_float_to_decimal_067);
  tcase_add_test(tc, s21_from_float_to_decimal_068);
  tcase_add_test(tc, s21_from_float_to_decimal_069);
  tcase_add_test(tc, s21_from_float_to_decimal_070);
  tcase_add_test(tc, s21_from_float_to_decimal_071);
  tcase_add_test(tc, s21_from_float_to_decimal_072);
  tcase_add_test(tc, s21_from_float_to_decimal_073);
  tcase_add_test(tc, s21_from_float_to_decimal_074);
  tcase_add_test(tc, s21_from_float_to_decimal_075);
  tcase_add_test(tc, s21_from_float_to_decimal_076);
  tcase_add_test(tc, s21_from_float_to_decimal_077);
  tcase_add_test(tc, s21_from_float_to_decimal_078);
  tcase_add_test(tc, s21_from_float_to_decimal_079);
  tcase_add_test(tc, s21_from_float_to_decimal_080);
  tcase_add_test(tc, s21_from_float_to_decimal_081);
  tcase_add_test(tc, s21_from_float_to_decimal_082);
  tcase_add_test(tc, s21_from_float_to_decimal_083);
  tcase_add_test(tc, s21_from_float_to_decimal_084);
  tcase_add_test(tc, s21_from_float_to_decimal_085);
  tcase_add_test(tc, s21_from_float_to_decimal_086);
  tcase_add_test(tc, s21_from_float_to_decimal_087);
  tcase_add_test(tc, s21_from_float_to_decimal_088);
  tcase_add_test(tc, s21_from_float_to_decimal_089);
  tcase_add_test(tc, s21_from_float_to_decimal_090);
  tcase_add_test(tc, s21_from_float_to_decimal_091);
  tcase_add_test(tc, s21_from_float_to_decimal_092);
  tcase_add_test(tc, s21_from_float_to_decimal_093);
  tcase_add_test(tc, s21_from_float_to_decimal_094);
  tcase_add_test(tc, s21_from_float_to_decimal_095);
  tcase_add_test(tc, s21_from_float_to_decimal_096);
  tcase_add_test(tc, s21_from_float_to_decimal_097);
  tcase_add_test(tc, s21_from_float_to_decimal_098);
  tcase_add_test(tc, s21_from_float_to_decimal_099);
  tcase_add_test(tc, s21_from_float_to_decimal_100);
  tcase_add_test(tc, s21_from_float_to_decimal_101);
  tcase_add_test(tc, s21_from_float_to_decimal_102);
  tcase_add_test(tc, s21_from_float_to_decimal_103);
  tcase_add_test(tc, s21_from_float_to_decimal_104);
  tcase_add_test(tc, s21_from_float_to_decimal_105);
  tcase_add_test(tc, s21_from_float_to_decimal_106);
  tcase_add_test(tc, s21_from_float_to_decimal_107);
  tcase_add_test(tc, s21_from_float_to_decimal_108);
  tcase_add_test(tc, s21_from_float_to_decimal_109);
  tcase_add_test(tc, s21_from_float_to_decimal_110);
  tcase_add_test(tc, s21_from_float_to_decimal_111);
  tcase_add_test(tc, s21_from_float_to_decimal_112);
  tcase_add_test(tc, s21_from_float_to_decimal_113);
  tcase_add_test(tc, s21_from_float_to_decimal_114);
  tcase_add_test(tc, s21_from_float_to_decimal_115);
  tcase_add_test(tc, s21_from_float_to_decimal_116);
  tcase_add_test(tc, s21_from_float_to_decimal_117);
  tcase_add_test(tc, s21_from_float_to_decimal_118);
  tcase_add_test(tc, s21_from_float_to_decimal_119);
  tcase_add_test(tc, s21_from_float_to_decimal_120);
  tcase_add_test(tc, s21_from_float_to_decimal_121);
  tcase_add_test(tc, s21_from_float_to_decimal_122);
  tcase_add_test(tc, s21_from_float_to_decimal_123);
  tcase_add_test(tc, s21_from_float_to_decimal_124);
  tcase_add_test(tc, s21_from_float_to_decimal_125);
  tcase_add_test(tc, s21_from_float_to_decimal_126);
  tcase_add_test(tc, s21_from_float_to_decimal_127);
  tcase_add_test(tc, s21_from_float_to_decimal_128);
  tcase_add_test(tc, s21_from_float_to_decimal_129);
  tcase_add_test(tc, s21_from_float_to_decimal_130);
  tcase_add_test(tc, s21_from_float_to_decimal_131);
  tcase_add_test(tc, s21_from_float_to_decimal_132);
  tcase_add_test(tc, s21_from_float_to_decimal_133);
  tcase_add_test(tc, s21_from_float_to_decimal_134);
  tcase_add_test(tc, s21_from_float_to_decimal_135);
  tcase_add_test(tc, s21_from_float_to_decimal_136);
  tcase_add_test(tc, s21_from_float_to_decimal_137);
  tcase_add_test(tc, s21_from_float_to_decimal_138);
  tcase_add_test(tc, s21_from_float_to_decimal_139);
  tcase_add_test(tc, s21_from_float_to_decimal_140);
  tcase_add_test(tc, s21_from_float_to_decimal_141);
  tcase_add_test(tc, s21_from_float_to_decimal_142);
  tcase_add_test(tc, s21_from_float_to_decimal_143);
  tcase_add_test(tc, s21_from_float_to_decimal_144);
  tcase_add_test(tc, s21_from_float_to_decimal_145);
  tcase_add_test(tc, s21_from_float_to_decimal_146);
  tcase_add_test(tc, s21_from_float_to_decimal_147);
  tcase_add_test(tc, s21_from_float_to_decimal_148);
  tcase_add_test(tc, s21_from_float_to_decimal_149);
  tcase_add_test(tc, s21_from_float_to_decimal_150);
  tcase_add_test(tc, s21_from_float_to_decimal_151);
  tcase_add_test(tc, s21_from_float_to_decimal_152);
  tcase_add_test(tc, s21_from_float_to_decimal_153);
  tcase_add_test(tc, s21_from_float_to_decimal_154);
  tcase_add_test(tc, s21_from_float_to_decimal_155);
  tcase_add_test(tc, s21_from_float_to_decimal_156);
  tcase_add_test(tc, s21_from_float_to_decimal_157);
  tcase_add_test(tc, s21_from_float_to_decimal_158);
  tcase_add_test(tc, s21_from_float_to_decimal_159);
  tcase_add_test(tc, s21_from_float_to_decimal_160);
  tcase_add_test(tc, s21_from_float_to_decimal_161);
  tcase_add_test(tc, s21_from_float_to_decimal_162);
  tcase_add_test(tc, s21_from_float_to_decimal_163);
  tcase_add_test(tc, s21_from_float_to_decimal_164);
  tcase_add_test(tc, s21_from_float_to_decimal_165);
  tcase_add_test(tc, s21_from_float_to_decimal_166);
  tcase_add_test(tc, s21_from_float_to_decimal_167);
  tcase_add_test(tc, s21_from_float_to_decimal_168);
  tcase_add_test(tc, s21_from_float_to_decimal_169);
  tcase_add_test(tc, s21_from_float_to_decimal_170);
  tcase_add_test(tc, s21_from_float_to_decimal_171);
  tcase_add_test(tc, s21_from_float_to_decimal_172);
  tcase_add_test(tc, s21_from_float_to_decimal_173);
  tcase_add_test(tc, s21_from_float_to_decimal_174);
  tcase_add_test(tc, s21_from_float_to_decimal_175);
  tcase_add_test(tc, s21_from_float_to_decimal_176);
  tcase_add_test(tc, s21_from_float_to_decimal_177);
  tcase_add_test(tc, s21_from_float_to_decimal_178);
  tcase_add_test(tc, s21_from_float_to_decimal_179);
  tcase_add_test(tc, s21_from_float_to_decimal_180);
  tcase_add_test(tc, s21_from_float_to_decimal_181);
  tcase_add_test(tc, s21_from_float_to_decimal_182);
  tcase_add_test(tc, s21_from_float_to_decimal_183);
  tcase_add_test(tc, s21_from_float_to_decimal_184);
  tcase_add_test(tc, s21_from_float_to_decimal_185);
  tcase_add_test(tc, s21_from_float_to_decimal_186);
  tcase_add_test(tc, s21_from_float_to_decimal_187);
  tcase_add_test(tc, s21_from_float_to_decimal_188);
  tcase_add_test(tc, s21_from_float_to_decimal_189);
  tcase_add_test(tc, s21_from_float_to_decimal_190);
  tcase_add_test(tc, s21_from_float_to_decimal_191);
  tcase_add_test(tc, s21_from_float_to_decimal_192);
  tcase_add_test(tc, s21_from_float_to_decimal_193);
  tcase_add_test(tc, s21_from_float_to_decimal_194);
  tcase_add_test(tc, s21_from_float_to_decimal_195);
  tcase_add_test(tc, s21_from_float_to_decimal_196);
  tcase_add_test(tc, s21_from_float_to_decimal_197);
  tcase_add_test(tc, s21_from_float_to_decimal_198);
  tcase_add_test(tc, s21_from_float_to_decimal_199);
  tcase_add_test(tc, s21_from_float_to_decimal_200);
  tcase_add_test(tc, s21_from_float_to_decimal_201);
  tcase_add_test(tc, s21_from_float_to_decimal_202);
  tcase_add_test(tc, s21_from_float_to_decimal_203);
  tcase_add_test(tc, s21_from_float_to_decimal_204);
  tcase_add_test(tc, s21_from_float_to_decimal_205);
  tcase_add_test(tc, s21_from_float_to_decimal_206);
  tcase_add_test(tc, s21_from_float_to_decimal_207);
  tcase_add_test(tc, s21_from_float_to_decimal_208);
  tcase_add_test(tc, s21_from_float_to_decimal_209);
  tcase_add_test(tc, s21_from_float_to_decimal_210);
  tcase_add_test(tc, s21_from_float_to_decimal_211);
  tcase_add_test(tc, s21_from_float_to_decimal_212);
  tcase_add_test(tc, s21_from_float_to_decimal_213);
  tcase_add_test(tc, s21_from_float_to_decimal_214);
  tcase_add_test(tc, s21_from_float_to_decimal_215);
  tcase_add_test(tc, s21_from_float_to_decimal_216);
  tcase_add_test(tc, s21_from_float_to_decimal_217);
  tcase_add_test(tc, s21_from_float_to_decimal_218);
  tcase_add_test(tc, s21_from_float_to_decimal_219);
  tcase_add_test(tc, s21_from_float_to_decimal_220);
  tcase_add_test(tc, s21_from_float_to_decimal_221);
  tcase_add_test(tc, s21_from_float_to_decimal_222);
  tcase_add_test(tc, s21_from_float_to_decimal_223);
  tcase_add_test(tc, s21_from_float_to_decimal_224);
  tcase_add_test(tc, s21_from_float_to_decimal_225);
  tcase_add_test(tc, s21_from_float_to_decimal_226);
  tcase_add_test(tc, s21_from_float_to_decimal_227);
  tcase_add_test(tc, s21_from_float_to_decimal_228);
  tcase_add_test(tc, s21_from_float_to_decimal_229);
  tcase_add_test(tc, s21_from_float_to_decimal_230);
  tcase_add_test(tc, s21_from_float_to_decimal_231);
  tcase_add_test(tc, s21_from_float_to_decimal_232);
  tcase_add_test(tc, s21_from_float_to_decimal_233);
  tcase_add_test(tc, s21_from_float_to_decimal_234);
  tcase_add_test(tc, s21_from_float_to_decimal_235);
  tcase_add_test(tc, s21_from_float_to_decimal_236);
  tcase_add_test(tc, s21_from_float_to_decimal_237);
  tcase_add_test(tc, s21_from_float_to_decimal_238);
  tcase_add_test(tc, s21_from_float_to_decimal_239);
  tcase_add_test(tc, s21_from_float_to_decimal_240);
  tcase_add_test(tc, s21_from_float_to_decimal_241);
  tcase_add_test(tc, s21_from_float_to_decimal_242);
  tcase_add_test(tc, s21_from_float_to_decimal_243);
  tcase_add_test(tc, s21_from_float_to_decimal_244);
  tcase_add_test(tc, s21_from_float_to_decimal_245);
  tcase_add_test(tc, s21_from_float_to_decimal_246);
  tcase_add_test(tc, s21_from_float_to_decimal_247);
  tcase_add_test(tc, s21_from_float_to_decimal_248);
  tcase_add_test(tc, s21_from_float_to_decimal_249);
  tcase_add_test(tc, s21_from_float_to_decimal_250);
  tcase_add_test(tc, s21_from_int_to_decimal_01);
  tcase_add_test(tc, s21_from_int_to_decimal_02);
  tcase_add_test(tc, s21_from_int_to_decimal_03);
  tcase_add_test(tc, s21_from_int_to_decimal_04);
  tcase_add_test(tc, s21_from_int_to_decimal_05);
  tcase_add_test(tc, s21_from_int_to_decimal_06);
  tcase_add_test(tc, s21_from_int_to_decimal_07);
  tcase_add_test(tc, s21_from_int_to_decimal_08);
  tcase_add_test(tc, s21_from_int_to_decimal_09);
  tcase_add_test(tc, s21_from_int_to_decimal_10);
  tcase_add_test(tc, s21_from_int_to_decimal_11);
  tcase_add_test(tc, s21_from_int_to_decimal_12);
  tcase_add_test(tc, s21_from_int_to_decimal_13);
  tcase_add_test(tc, s21_from_int_to_decimal_14);
  tcase_add_test(tc, s21_from_int_to_decimal_15);
  tcase_add_test(tc, s21_from_int_to_decimal_16);
  tcase_add_test(tc, s21_from_int_to_decimal_17);
  tcase_add_test(tc, s21_from_int_to_decimal_18);
  tcase_add_test(tc, s21_from_int_to_decimal_19);
  tcase_add_test(tc, s21_from_int_to_decimal_20);
  return s;
}
