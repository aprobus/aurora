cc_library(
    name = "led_strip",
    hdrs = ["led_strip.h"],
    visibility = ["//visibility:public"]
)

cc_test(
    name = "led_strip_test",
    srcs = ["led_strip_test.cpp"],
    size = "small",
    deps = [
        "@googletest//:gtest",
        ":led_strip",
    ]
)

cc_library(
    name = "mock_led_strip",
    hdrs = ["mock_led_strip.h"],
    deps = [
        "@googletest//:gtest",
        ":led_strip",
    ],
    visibility = ["//visibility:public"]
)

cc_library(
    name = "neopixel_strip",
    hdrs = ["neopixel_strip.h"],
    srcs = ["neopixel_strip.cpp"],
    deps = [
        ":led_strip",
    ],
    visibility = ["//visibility:public"]
)
