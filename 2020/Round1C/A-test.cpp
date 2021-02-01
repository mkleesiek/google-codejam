#include "testing.h"
#include "utilities.h"

#include "A.cpp"

using namespace std;

TEST( Solve, Custom)
{
    ASSERT_EQ(solve(0, 0, "NESW"), 0);
    ASSERT_EQ(solve(1, 0, "EEEEE"), -1);
    ASSERT_EQ(solve(1, 0, "EEEEEW"), 6);
    ASSERT_EQ(solve(6, 0, "WWW"), 3);
}

TEST( Main, Basic )
{
    string input = R"(5
4 4 SSSS
3 0 SNSS
2 10 NSNNSN
0 1 S
2 7 SSSSSSSS
)";

    string expectation = R"(Case #1: 4
Case #2: IMPOSSIBLE
Case #3: IMPOSSIBLE
Case #4: 1
Case #5: 5
)";

    ASSERT_MAIN_RETURNS(input, 0);
    ASSERT_OUTPUT_EQ(expectation);
}

TEST( Main, Advanced )
{
    string input = R"(2
3 2 SSSW
4 0 NESW
)";

    string expectation = R"(Case #1: 4
Case #2: 4
)";

    ASSERT_MAIN_RETURNS(input, 0);
    ASSERT_OUTPUT_EQ(expectation);
}