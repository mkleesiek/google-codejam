#include <gtest/gtest.h>
#include <iostream>
#include <string>

#define GTEST

#define main(...) test(__VA_ARGS__)
//undef main

#define ASSERT_MAIN_RETURNS(input, output) \
{ \
	std::istringstream in(input); \
    std::cin.rdbuf(in.rdbuf()); \
    testing::internal::CaptureStdout(); \
    const int return_value = main(); \
    ASSERT_EQ(return_value, output); \
}

#define ASSERT_OUTPUT_EQ(expected) \
{ \
    const string output = testing::internal::GetCapturedStdout(); \
    ASSERT_EQ(output, expected); \
}
