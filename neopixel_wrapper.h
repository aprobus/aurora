#ifndef NEOPIXEL_WRAPPER_H
#define NEOPIXEL_WRAPPER_H

#include "neopixel.h"

#include <stdint.h>

#include <Adafruit_NeoPixel.h>

class NeopixelWrapper : public Neopixel {
  public:
    NeopixelWrapper(Adafruit_NeoPixel* pixels) : pixels_(pixels) {}

    void begin() override {
      pixels_->begin();
    }

    void show() override {
      if (is_dirty_) {
        pixels_->show();
        is_dirty_ = false;
      }
    }

    void setPixelColor(uint16_t index, color_t color) override {
      pixels_->setPixelColor(index, color);
      is_dirty_ = true;
    }

    void clear() override {
      pixels_->clear();
      is_dirty_ = true;
    }

    uint16_t numPixels() const override {
      return pixels_->numPixels();
    }

    color_t getPixelColor(uint16_t index) const override {
      return pixels_->getPixelColor(index);
    }

  private:
    Adafruit_NeoPixel* pixels_; // Does not own
    bool is_dirty_ = false;
};

#endif
