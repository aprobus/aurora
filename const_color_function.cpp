#include "const_color_function.h"

#include "led_strip.h"

ConstColorFunction::ConstColorFunction(color_t color, unsigned long length) : color_(color), length_(length) {}

unsigned long ConstColorFunction::length() const {
  return length_;
}

color_t ConstColorFunction::color(unsigned long millis) const {
  return color_;
}
