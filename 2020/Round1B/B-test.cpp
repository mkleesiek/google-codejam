#include "testing.h"
#include "utilities.h"

#include "B.cpp"

using namespace std;

TEST( Main, Basic )
{
    string input = R"(0
)";

    string expectation = R"()";

    ASSERT_MAIN_RETURNS(input, 0);
    ASSERT_OUTPUT_EQ(expectation);
}
