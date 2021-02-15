#ifndef CONST_COLOR_FUNCTION_H
#define CONST_COLOR_FUNCTION_H

#include "color_function.h"
#include "led_strip.h"

// Color function that returns the same color regardless of the time.
class ConstColorFunction : public ColorFunction {
  public:
  ConstColorFunction(color_t color, unsigned long length);
  unsigned long length() const override;
  color_t color(unsigned long millis) const override;

  private:
  color_t color_;
  unsigned long length_;
};

#endif
