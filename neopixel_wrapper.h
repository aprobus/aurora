#ifndef NEOPIXEL_WRAPPER_H
#define NEOPIXEL_WRAPPER_H

#include "neopixel.h"

#include <stdint.h>

#include <Adafruit_NeoPixel.h>

class NeopixelWrapper : public Neopixel {
  public:
    NeopixelWrapper(Adafruit_NeoPixel* pixels);

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
