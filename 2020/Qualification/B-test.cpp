#include "testing.h"
#include "utilities.h"

#include "B.cpp"

#include <stdexcept>

using namespace std;

TEST( solve, Simple )
{
	ASSERT_EQ(solve(""), "");
	ASSERT_EQ(solve("0"), "0");
    ASSERT_EQ(solve("021"), "0((2)1)");
	ASSERT_EQ(solve("312"), "(((3))1(2))");
	ASSERT_EQ(solve("4"), "((((4))))");
	ASSERT_EQ(solve("221"), "((22)1)");
	ASSERT_EQ(solve("9"), "(((((((((9)))))))))");
}

TEST( Main, Basic )
{
    string input = R"(4
0000
101
111000
1
)";

    string expectation = R"(Case #1: 0000
Case #2: (1)0(1)
Case #3: (111)000
Case #4: (1)
)";

    ASSERT_EQ(execute_main(test, input), 0);

    string output = capture_output();
    ASSERT_EQ(output, expectation);
}
