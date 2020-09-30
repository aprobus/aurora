cc_library(
    name = "neopixel",
    hdrs = ["neopixel.h"],
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
    ]
)
