#include "testing.h"
#include "utilities.h"

#include "C.cpp"

using namespace std;

TEST( Main, Basic )
{
    string input = R"(3
2 2
3 2
2 3
)";

    string expectation = R"(Case #1: 1
2 1
Case #2: 2
3 2
2 1
Case #3: 2
2 3
2 2
)";

    ASSERT_MAIN_RETURNS(input, 0);
    ASSERT_OUTPUT_EQ(expectation);
}
