cc_library(
    name = "neopixel",
    hdrs = ["neopixel.h"],
    visibility = ["//visibility:public"]
)

cc_test(
    name = "neopixel_test",
    srcs = ["neopixel_test.cpp"],
    size = "small",
    deps = [
        "@googletest//:gtest",
        ":neopixel",
    ]
)

cc_library(
    name = "mock_neopixel",
    hdrs = ["mock_neopixel.h"],
    deps = [
        "@googletest//:gtest",
        ":neopixel",
    ],
    visibility = ["//visibility:public"]
)

cc_library(
    name = "neopixel_wrapper",
    hdrs = ["neopixel_wrapper.h"],
    srcs = ["neopixel_wrapper.cpp"],
    deps = [
        ":neopixel",
    ],
    visibility = ["//visibility:public"]
)
