#ifndef COLOR_FUNCTION_LED_EFFECT_H
#define COLOR_FUNCTION_LED_EFFECT_H

#include <functional>
#include <memory>
#include <vector>

#include "color_function.h"
#include "led_effect.h"
#include "led_strip.h"

// Applies color functions to all pixels within a led strip that match the predicates.
class ColorFunctionLedEffect : public LedEffect {
  public:
  ColorFunctionLedEffect(LedStrip* leds);

  // Adds a new color function / predicate pair. The color function will be applied to all
  // pixels that the predicate returns true for. Once a pixel has been assigned it cannot
  // be reassigned. Returns true if the function will be applied to one or more pixels,
  // false otherwise.
  bool add(std::unique_ptr<ColorFunction> f, std::function<bool (uint16_t)> p);

  void update(unsigned long millis) override;
  unsigned long length() const override;

  private:
  struct CachedColorFunction {
    std::unique_ptr<ColorFunction> color_function;
    color_t color;
    CachedColorFunction(std::unique_ptr<ColorFunction> f) : color_function(std::move(f)), color() {}
  };

  LedStrip* leds_ = nullptr;
  std::vector<CachedColorFunction> color_functions_;
  std::vector<int> color_function_index_;
};

#endif
