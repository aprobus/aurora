#ifdef ARDUINO

#include "neopixel_strip.h"

#include <stdint.h>
#include <Adafruit_NeoPixel.h>

#include "led_strip.h"

NeopixelWrapper::NeopixelWrapper(Adafruit_NeoPixel* pixels) : pixels_(pixels) {}

void NeopixelWrapper::begin() {
  pixels_->begin();
}

void NeopixelWrapper::show() {
  if (is_dirty_) {
    pixels_->show();
    is_dirty_ = false;
  }
}

void NeopixelWrapper::setPixelColor(uint16_t index, color_t color) {
  pixels_->setPixelColor(index, color);
  is_dirty_ = true;
}

void NeopixelWrapper::clear() {
  pixels_->clear();
  is_dirty_ = true;
}

uint16_t NeopixelWrapper::numPixels() const {
  return pixels_->numPixels();
}

color_t NeopixelWrapper::getPixelColor(uint16_t index) const {
  return pixels_->getPixelColor(index);
}

#endif