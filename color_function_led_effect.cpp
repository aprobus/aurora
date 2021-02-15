#include "color_function_led_effect.h"

#include <functional>
#include <limits>
#include <memory>
#include <vector>

#include "color_function.h"
#include "led_effect.h"
#include "led_strip.h"

namespace {
  int kUnassigned = -1;
}

ColorFunctionLedEffect::ColorFunctionLedEffect(LedStrip* leds) : leds_(leds), color_function_index_(leds->numPixels(), kUnassigned) {}

bool ColorFunctionLedEffect::add(std::unique_ptr<ColorFunction> f, std::function<bool (uint16_t)> p) {
  bool did_add = false;
  for (int i = 0; i < leds_->numPixels(); i++) {
    if (color_function_index_[i] == kUnassigned && p(i)) {
      if (!did_add) {
        did_add = true;
        color_functions_.emplace_back(std::move(f));
      }
      color_function_index_[i] = color_functions_.size() - 1;
    }
  }

  return did_add;
}

void ColorFunctionLedEffect::update(unsigned long millis) {
  for (int i = 0; i < color_functions_.size(); i++) {
    auto& cf = color_functions_[i];
    cf.color = cf.color_function->color(millis % cf.color_function->length());
  }

  for (int i = 0; i < color_function_index_.size(); i++) {
    int f_index = color_function_index_[i];

    if (f_index >= 0) {
      leds_->setPixelColor(i, color_functions_[f_index].color);
    }
  }

  leds_->show();
}

unsigned long ColorFunctionLedEffect::length() const {
  return std::numeric_limits<unsigned long>::max();
}
