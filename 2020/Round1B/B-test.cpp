#include "testing.h"
#include "utilities.h"

#include "B.cpp"

using namespace std;

TEST( Round_2020_1B_B, Main ){
    string input = R"(0
)";

    string expectation = R"()";

    ASSERT_MAIN_RETURNS(input, 0);
    ASSERT_OUTPUT_EQ(expectation);
}
