#include "testing.h"
#include "utilities.h"

#include "B.cpp"

using namespace std;

TEST( Round_X_B, Main )
{
    string input = R"()";

    string expectation = R"()";

    ASSERT_MAIN_RETURNS(input, 0);
    ASSERT_OUTPUT_EQ(expectation);
}