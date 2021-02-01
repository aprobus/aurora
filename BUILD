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

cc_library(
    name = "led_effect",
    hdrs = ["led_effect.h"],
    visibility = ["//visibility:public"]
    )

cc_library(
    name = "color_function",
    hdrs = ["color_function.h"],
    deps = [":led_strip"],
    visibility = ["//visibility:public"]
    )

cc_library(
    name = "mock_led_effect",
    hdrs = ["mock_led_effect.h"],
    deps = [
        ":color_function",
        ":led_effect",
        ":led_strip",
        ],
    testonly = True,
    visibility = ["//visibility:public"]
    )

cc_library(
    name = "repeated_led_effect",
    hdrs = ["repeated_led_effect.h"],
    deps = [":led_effect"],
    visibility = ["//visibility:public"]
    )

cc_test(
    name = "repeated_led_effect_test",
    srcs = ["repeated_led_effect_test.cpp"],
    deps = [
        ":mock_led_effect",
        ":repeated_led_effect",
        "@googletest//:gtest",
        ]
    )

cc_library(
    name = "sequential_led_effect",
    hdrs = ["sequential_led_effect.h"],
    srcs = ["sequential_led_effect.cpp"],
    deps = [":led_effect"],
    visibility = ["//visibility:public"]
    )

cc_test(
    name = "sequential_led_effect_test",
    srcs = ["sequential_led_effect_test.cpp"],
    deps = [
        ":led_strip",
        ":mock_led_effect",
        ":sequential_led_effect",
        "@googletest//:gtest",
        ]
    )

cc_library(
    name = "pulse_color_function",
    hdrs = ["pulse_color_function.h"],
    srcs = ["pulse_color_function.cpp"],
    deps = [
        ":color_function",
        ":led_strip"
        ],
    visibility = ["//visibility:public"]
    )

cc_test(
    name = "pulse_color_function_test",
    srcs = ["pulse_color_function_test.cpp"],
    size = "small",
    deps = [
        ":pulse_color_function",
        ":led_strip",
        "@googletest//:gtest",
        ]
    )
