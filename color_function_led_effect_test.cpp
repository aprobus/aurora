#include "color_function_led_effect.h"

#include <memory>

#include "gtest/gtest.h"
#include "mock_led_effect.h"
#include "mock_led_strip.h"

using ::testing::Eq;
using ::testing::Return;
using ::testing::_;

namespace {
  bool isEven(uint16_t i) {
    return i % 2 == 0;
  }

  bool alwaysTrue(uint16_t i) {
    return true;
  }
}

TEST(ColorFunctionLedEffect, UpdateOverlapPredicate) {
  auto mock_leds = std::unique_ptr<FakeLedStrip<8>>(new FakeLedStrip<8>());
  ColorFunctionLedEffect effect(mock_leds.get());

  color_t color_even(0, 0, 0, 1);
  auto mock_color_even = std::unique_ptr<MockColorFunction>(new MockColorFunction());
  EXPECT_CALL(*mock_color_even, length()).WillRepeatedly(Return(10));
  EXPECT_CALL(*mock_color_even, color(Eq(8))).WillRepeatedly(Return(color_even));

  color_t color_any(0, 0, 0, 2);
  auto mock_color_any = std::unique_ptr<MockColorFunction>(new MockColorFunction());
  EXPECT_CALL(*mock_color_any, length()).WillRepeatedly(Return(10));
  EXPECT_CALL(*mock_color_any, color(Eq(8))).WillRepeatedly(Return(color_any));

  EXPECT_TRUE(effect.add(std::move(mock_color_even), isEven));
  EXPECT_TRUE(effect.add(std::move(mock_color_any), alwaysTrue));

  effect.update(8);

  EXPECT_EQ(mock_leds->getPixelColor(0), color_even);
  EXPECT_EQ(mock_leds->getPixelColor(1), color_any);
  EXPECT_EQ(mock_leds->getPixelColor(2), color_even);
}

TEST(ColorFunctionLedEffect, UpdateGap) {
  auto mock_leds = std::unique_ptr<FakeLedStrip<8>>(new FakeLedStrip<8>());
  ColorFunctionLedEffect effect(mock_leds.get());

  color_t color_even(0, 0, 0, 1);
  auto mock_color_even = std::unique_ptr<MockColorFunction>(new MockColorFunction());
  EXPECT_CALL(*mock_color_even, length()).WillRepeatedly(Return(10));
  EXPECT_CALL(*mock_color_even, color(Eq(8))).WillRepeatedly(Return(color_even));

  EXPECT_TRUE(effect.add(std::move(mock_color_even), isEven));

  effect.update(8);

  EXPECT_EQ(mock_leds->getPixelColor(0), color_even);
  EXPECT_EQ(mock_leds->getPixelColor(1), color_t(0, 0, 0));
}

TEST(ColorFunctionLedEffect, UpdateUnusedFunction) {
  auto mock_leds = std::unique_ptr<FakeLedStrip<8>>(new FakeLedStrip<8>());
  ColorFunctionLedEffect effect(mock_leds.get());

  auto mock_color_even = std::unique_ptr<MockColorFunction>(new MockColorFunction());
  EXPECT_CALL(*mock_color_even, length()).WillRepeatedly(Return(10));

  auto mock_color_any = std::unique_ptr<MockColorFunction>(new MockColorFunction());
  EXPECT_CALL(*mock_color_any, length()).WillRepeatedly(Return(10));

  EXPECT_TRUE(effect.add(std::move(mock_color_even), isEven));
  // Second function will be dropped because all pixels are assigned already.
  EXPECT_FALSE(effect.add(std::move(mock_color_any), isEven));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
