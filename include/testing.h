#include <gtest/gtest.h>
#include <iostream>
#include <string>

#define GTEST

#define main(...) test(__VA_ARGS__)
//undef main

#define PROVIDE_INPUT(input) \
    std::istringstream in(input); \
    cin.rdbuf(in.rdbuf()); \
    testing::internal::CaptureStdout();

#define CAPTURE_OUTPUT(output) \
    std::string output = testing::internal::GetCapturedStdout();
    