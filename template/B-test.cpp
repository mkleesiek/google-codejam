#include "testing.h"
#include "utilities.h"

#include "B.cpp"

using namespace std;

TEST( Main, Basic )
{
    string input = R"(
)";

    string expectation = R"(
)";

    ASSERT_EQ(execute_main(test, input), 0);

    string output = capture_output();
    ASSERT_EQ(output, expectation);
}