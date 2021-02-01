#include "testing.h"
#include "utilities.h"

#include "B.cpp"

#include <random>
#include <stdexcept>

using namespace std;

static mt19937 mt;

TEST( Main, Basic )
{
    string input = R"(0)";

    string expectation = R"()";

    ASSERT_MAIN_RETURNS(input, 0);
    ASSERT_OUTPUT_EQ(expectation);
}
