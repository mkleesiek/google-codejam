#include "testing.h"
#include "utilities.h"

#include "A.cpp"

#include <random>
#include <stdexcept>

using namespace std;

static mt19937 mt;

TEST( Main, Basic )
{
    string input = R"(0)";

    string expectation = R"()";

    PROVIDE_INPUT(input);
    ASSERT_EQ(test(), 0);
    CAPTURE_OUTPUT(output);

    ASSERT_EQ(output, expectation);
}
