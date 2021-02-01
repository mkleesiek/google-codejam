#include "testing.h"
#include "utilities.h"

#include "C.cpp"

using namespace std;

TEST( Main, Basic )
{
    string input = R"(4
1 3
1
5 2
10 5 359999999999 123456789 10
2 3
8 4
3 2
1 2 3
)";

    string expectation = R"(Case #1: 2
Case #2: 0
Case #3: 1
Case #4: 1
)";

    ASSERT_MAIN_RETURNS(input, 0);
    ASSERT_OUTPUT_EQ(expectation);
}
