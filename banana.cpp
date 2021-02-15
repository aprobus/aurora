#include "banana.h"

#include <functional>
#include <vector>

#include "color_function.h"
#include "led_effect.h"
#include "led_strip.h"

Banana::Banana(LedStrip* leds) : leds_(leds), color_function_index_(leds->numPixels(), -1) {}

void Banana::add(std::unique_ptr<ColorFunction> f, std::function<bool (uint16_t)> p) {
  max_color_millis_ = std::max(max_color_millis_, f->length());

  bool did_add = false;
  for (int i = 0; i < leds_->numPixels(); i++) {
    if (!color_function_index_[i] && p(i)) {
      did_add = true;
      color_function_index_[i] = color_functions_.size() - 1;
    }
  }

  if (did_add) {
    color_functions_.push_back(std::move(f));
    color_cache_.push_back({});
  }
}

void Banana::update(unsigned long millis) {
  if (millis >= max_color_millis_) return;

  for (int i = 0; i < color_functions_.size(); i++) {
    color_cache_[i] = color_functions_[i]->color(millis);
  }

  for (int i = 0; i < color_function_index_.size(); i++) {
    int function_index = color_function_index_[i];

    if (function_index >= 0) {
      leds_->setPixelColor(i, color_cache_[function_index]);
    }
  }
}

unsigned long Banana::length() const {
  return max_color_millis_;
}