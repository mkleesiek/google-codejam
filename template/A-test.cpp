#include "testing.h"
#include "utilities.h"

#include "A.cpp"

using namespace std;

TEST( Main, Basic )
{
    string input = R"(
)";

    string expectation = R"(
)";

    ASSERT_EQ(execute_main(input), 0);

    string output = capture_output();
    ASSERT_EQ(output, expectation);
}
