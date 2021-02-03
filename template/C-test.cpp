#include "testing.h"
#include <string>

#include "C.cpp"

using namespace std;

TEST( Round_X_C, Main )
{
    string input = R"()";

    string expectation = R"()";

    ASSERT_MAIN_RETURNS(input, 0);
    ASSERT_OUTPUT_EQ(expectation);
}
