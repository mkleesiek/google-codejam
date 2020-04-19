#include <gtest/gtest.h>
#include <iostream>
#include <string>

#define GTEST

#define main(...) test(__VA_ARGS__)
//undef main

template<typename F>
int execute_main(F& f, const std::string& input)
{
	std::istringstream in(input);
    std::cin.rdbuf(in.rdbuf());
    testing::internal::CaptureStdout();
    return f();
}

std::string capture_output()
{
	return testing::internal::GetCapturedStdout();
}
