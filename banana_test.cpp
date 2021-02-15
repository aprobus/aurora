#include "banana.h"

#include <memory>

#include "gtest/gtest.h"
#include "mock_led_effect.h"
#include "mock_led_strip.h"

using ::testing::Eq;
using ::testing::Return;

namespace {
  bool isEven(uint16_t i) {
    return i % 2 == 0;
  }

  bool alwaysTrue(uint16_t i) {
    return true;
  }
}

TEST(Banana, Update) {
  auto mock_leds = std::unique_ptr<FakeLedStrip<8>>(new FakeLedStrip<8>());
  Banana effect(mock_leds.get());
  auto mock_color_even = std::unique_ptr<MockColorFunction>();
  EXPECT_CALL(*mock_color_even, length()).WillRepeatedly(Return(10));

  auto mock_color_all = std::unique_ptr<MockColorFunction>();
  EXPECT_CALL(*mock_color_all, length()).WillRepeatedly(Return(10));

  effect.add(std::move(mock_color_even), isEven);
  effect.add(std::move(mock_color_all), alwaysTrue);

  effect.update(8);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
