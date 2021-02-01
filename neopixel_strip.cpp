#ifdef ARDUINO

#include "neopixel_strip.h"

#include <stdint.h>
#include <Adafruit_NeoPixel.h>

#include "led_strip.h"

NeopixelStrip::NeopixelStrip(Adafruit_NeoPixel* pixels) : pixels_(pixels) {}

void NeopixelStrip::begin() {
  pixels_->begin();
}

void NeopixelStrip::show() {
  if (is_dirty_) {
    pixels_->show();
    is_dirty_ = false;
  }
}

void NeopixelStrip::setPixelColor(uint16_t index, color_t color) {
  pixels_->setPixelColor(index, color);
  is_dirty_ = true;
}

void NeopixelStrip::clear() {
  pixels_->clear();
  is_dirty_ = true;
}

uint16_t NeopixelStrip::numPixels() const {
  return pixels_->numPixels();
}

color_t NeopixelStrip::getPixelColor(uint16_t index) const {
  return pixels_->getPixelColor(index);
}

#endif
