#include "testing.h"
#include "utilities.h"

#include "A.cpp"

using namespace std;

TEST( Main, Basic )
{
    string input = R"(4
1
RS
3
R
P
S
7
RS
RS
RS
RS
RS
RS
RS
2
PPP
RRR
)";

    string expectation = R"(Case #1: P
Case #2: IMPOSSIBLE
Case #3: P
Case #4: PS
)";

    ASSERT_MAIN_RETURNS(input, 0);
    ASSERT_OUTPUT_EQ(expectation);
}
