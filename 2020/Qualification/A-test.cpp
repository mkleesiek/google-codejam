#include "testing.h"
#include "utilities.h"

#include "A.cpp"

#include <stdexcept>

using namespace std;

TEST( Main, Basic )
{
    string input = R"(3
4
1 2 3 4
2 1 4 3
3 4 1 2
4 3 2 1
4
2 2 2 2
2 3 2 3
2 2 2 3
2 2 2 2
3
2 1 3
1 3 2
1 2 3
)";

    string expectation = R"(Case #1: 4 0 0
Case #2: 9 4 4
Case #3: 8 0 2
)";

    ASSERT_MAIN_RETURNS(input, 0);
    ASSERT_OUTPUT_EQ(expectation);
}
