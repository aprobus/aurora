# Aurora

Led light strip library for Arduino.

## Core Concepts

### LedStrip

A led strip represents a series of individually controllable RGBW leds.

### Implementations

* `neopixel_strip.h`: An led strip of Adafruit Neopixels.

### LedEffect

An led effect controls a set of leds to produce a visual effect. Led effects are generally represented as a function of time.

### Implementations

* `sequential_led_effect.h`: Runs a collection of led effects in series.
* `repeated_led_effect.h`: Repeats an led effect to expand its lifetime.

### ColorFunction

A color function is a function that maps a time to a particular color. These should be pure functions and combined with a LedEffect to produce output.

### Implementations

* `pulse_color_function.h`: Pulses between two colors in a visually linear manner.

