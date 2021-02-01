#ifndef ARDUINO

#include "led_strip.h"

#include <stdint.h>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

TEST(color_t, Rgbw) {
  color_t c(1, 2, 4, 8);

  uint32_t r = 1;
  uint32_t g = 2;
  uint32_t b = 4;
  uint32_t w = 8;
  uint32_t int_color = (w << 24) | (r << 16) | (g << 8) | b;

  EXPECT_EQ(static_cast<uint32_t>(c), int_color);
  EXPECT_EQ(static_cast<color_t>(int_color), c);
}

TEST(color_t, Rgb) {
  color_t c(1, 2, 4);

  uint32_t r = 1;
  uint32_t g = 2;
  uint32_t b = 4;
  uint32_t w = 0;
  uint32_t int_color = (w << 24) | (r << 16) | (g << 8) | b;

  EXPECT_EQ(static_cast<uint32_t>(c), int_color);
  EXPECT_EQ(static_cast<color_t>(int_color), c);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#endif
