#ifndef BANANA_H
#define BANANA_H

#include <functional>
#include <vector>

#include "color_function.h"
#include "led_effect.h"
#include "led_strip.h"

class Banana : public LedEffect {
  public:
  Banana(LedStrip* leds);

  void add(std::unique_ptr<ColorFunction> f, std::function<bool (uint16_t)> p);

  void update(unsigned long millis) override;
  unsigned long length() const override;

  private:
  LedStrip* leds_ = nullptr;
  unsigned long max_color_millis_ = 0;
  std::vector<std::unique_ptr<ColorFunction>> color_functions_;
  std::vector<color_t> color_cache_;
  std::vector<int> color_function_index_;
};

#endif