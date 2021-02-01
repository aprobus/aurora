#ifndef NEOPIXEL_H
#define NEOPIXEL_H

#include <stdint.h>

struct color_t {
  uint8_t b = 0;       /**< Blue component */
  uint8_t g = 0;       /**< Green component */
  uint8_t r = 0;       /**< Red component */
  uint8_t w = 0;       /**< White component */

  color_t() {}

  color_t(uint32_t c) {
    w = static_cast<uint8_t>(c >> 24);
    r = static_cast<uint8_t>(c >> 16);
    g = static_cast<uint8_t>(c >> 8);
    b = static_cast<uint8_t>(c);
  }

  constexpr color_t(uint8_t red, uint8_t green, uint8_t blue) : b{blue}, g{green}, r{red} {
  }

  constexpr color_t(uint8_t red, uint8_t green, uint8_t blue, uint8_t white) : b{blue}, g{green}, r{red}, w{white} {
  }

  operator uint32_t () const {
    uint32_t c = (w << 24) | (r << 16) | (g << 8) | b;
    return c;
  }
};

class LedStrip {
  public:
    virtual ~LedStrip() = default;
    virtual void begin() = 0;
    virtual void show() = 0;
    virtual void setPixelColor(uint16_t index, color_t color) = 0;
    virtual void clear() = 0;
    virtual uint16_t numPixels() const = 0;
    virtual color_t getPixelColor(uint16_t index) const = 0;
};
#endif
