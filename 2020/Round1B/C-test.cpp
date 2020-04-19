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

    ASSERT_EQ(execute_main(test, input), 0);

    string output = capture_output();
    ASSERT_EQ(output, expectation);
}
