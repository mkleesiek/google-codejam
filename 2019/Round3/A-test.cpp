#include "testing.h"
#include "utilities.h"

#include "A.cpp"

#include <random>
#include <stdexcept>

using namespace std;

static mt19937 mt;

TEST( Zillionim, FirstTurn )
{
    Zillionim z(1000, 10);
    ASSERT_EQ(z.turn(0), false);

    ASSERT_EQ(z.turn(1), true);
    ASSERT_EQ(z.turn(1), false);
    ASSERT_EQ(z.turn(10), false);
    ASSERT_EQ(z.CheckCoin(1), false);
    ASSERT_EQ(z.CheckCoin(10), false);
    ASSERT_EQ(z.CheckCoin(11), true);

    ASSERT_EQ(z.turn(11), true);
    ASSERT_EQ(z.CheckCoin(11), false);

    ASSERT_EQ(z.turn(100), true);
    ASSERT_EQ(z.CheckCoin(99), true);
    ASSERT_EQ(z.CheckCoin(100), false);
    ASSERT_EQ(z.CheckCoin(109), false);
    ASSERT_EQ(z.CheckCoin(110), true);
    ASSERT_EQ(z.CheckCoin(1000), true);
}

TEST( Zillionim, RandomPlaySmall )
{
    Zillionim z(1000, 10);
    while (z.IsPlayable())
    {
        uint64_t M = z.chooseNext();
        ASSERT_GT(M, 0);
        ASSERT_EQ(z.turn(M), true);
    }

    ASSERT_EQ(z.chooseNext(), 0);
}

TEST( Zillionim, RandomPlayLarge )
{
    Zillionim z;
    while (z.IsPlayable())
    {
        uint64_t M = z.chooseNext();
        ASSERT_GT(M, 0);
        ASSERT_EQ(z.turn(M), true);
    }

    ASSERT_EQ(z.chooseNext(), 0);
}

TEST( Main, Basic )
{
    string input = R"(0)";

    string expectation = R"()";

    PROVIDE_INPUT(input);
    ASSERT_EQ(test(), 0);
    CAPTURE_OUTPUT(output);

    ASSERT_EQ(output, expectation);
}
