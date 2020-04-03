#include "testing.h"
#include "utilities.h"

#include "A.cpp"

#include <stdexcept>

using namespace std;

TEST( solve, Basic )
{
	string input = "4";
	ASSERT_EQ(solve(input), "1");
	ASSERT_EQ(input, "3");
}

TEST( Main, Basic )
{
    string input = R"(
3
4
940
4444
)";

    string expectation = R"(Case #1: 3 1
Case #2: 930 10
Case #3: 3333 1111
)";

    PROVIDE_INPUT(input);
    ASSERT_EQ(test(), 0);
    CAPTURE_OUTPUT(output);

    ASSERT_EQ(output, expectation);
}
