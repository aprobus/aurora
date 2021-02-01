#ifndef NEOPIXEL_WRAPPER_H
#define NEOPIXEL_WRAPPER_H

#include <stdint.h>

#ifdef ARDUINO
#include <Adafruit_NeoPixel.h>
#else
class Adafruit_NeoPixel;
#endif

#include "led_strip.h"

class NeopixelStrip : public LedStrip {
  public:
    NeopixelStrip(Adafruit_NeoPixel* pixels);

    void begin() override;

    void show() override;

    void setPixelColor(uint16_t index, color_t color) override;

    void clear() override;

    uint16_t numPixels() const override;

    color_t getPixelColor(uint16_t index) const override;

  private:
    Adafruit_NeoPixel* pixels_; // Does not own
    bool is_dirty_ = false;
};

#endif