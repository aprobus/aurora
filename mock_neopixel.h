#ifndef ARDUINO

#include <stdint.h>
#include <array>

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "neopixel.h"

class MockNeopixel : public Neopixel {
  public:
    MOCK_METHOD(uint16_t, numPixels, (), (const override));
    MOCK_METHOD(void, setPixelColor, (uint16_t, color_t), (override));
    MOCK_METHOD(void, clear, (), (override));
    MOCK_METHOD(void, begin, (), (override));
    MOCK_METHOD(void, show, (), (override));
    MOCK_METHOD(color_t, getPixelColor, (uint16_t), (const override));
};

template <uint16_t N>
class FakeNeopixel : public Neopixel {
  public:
    uint16_t numPixels() const override {
      return N;
    }

    void setPixelColor(uint16_t pin, color_t color) override {
      pixels_[pin] = color;
    }

    void clear() override {
      pixels_ = std::array<color_t, N>();
    }

    void begin() override {}

    void show() override {}

    color_t getPixelColor(uint16_t pin) const override {
      return pixels_[pin];
    }

  private:
    std::array<color_t, N> pixels_;
};

#endif
