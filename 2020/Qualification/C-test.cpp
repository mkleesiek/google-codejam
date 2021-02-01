#include "testing.h"
#include "utilities.h"

#include "C.cpp"

#include <stdexcept>

using namespace std;

TEST( Main, Basic )
{
    string input = R"(4
3
360 480
420 540
600 660
3
0 1440
1 3
2 4
5
99 150
1 100
100 301
2 5
150 250
2
0 720
720 1440
)";

    string expectation = R"(Case #1: CJC
Case #2: IMPOSSIBLE
Case #3: JCCJJ
Case #4: CC
)";

    ASSERT_MAIN_RETURNS(input, 0);
    ASSERT_OUTPUT_EQ(expectation);
}
