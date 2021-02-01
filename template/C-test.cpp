#include "testing.h"
#include "utilities.h"

#include "C.cpp"

using namespace std;

TEST( Main, Basic )
{
    string input = R"(
)";

    string expectation = R"(
)";

    ASSERT_MAIN_RETURNS(input, 0);
    ASSERT_OUTPUT_EQ(expectation);
}
