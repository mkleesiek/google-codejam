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

    ASSERT_EQ(z.Turn(0), false);
    ASSERT_EQ(z.MovesLeft(), 100);

    ASSERT_EQ(z.Turn(1), true);
    ASSERT_EQ(z.MovesLeft(), 99);

    ASSERT_EQ(z.Turn(1), false);
    ASSERT_EQ(z.Turn(10), false);
    ASSERT_EQ(z.CheckCoin(1), false);
    ASSERT_EQ(z.CheckCoin(10), false);
    ASSERT_EQ(z.CheckCoin(11), true);

    ASSERT_EQ(z.Turn(11), true);
    ASSERT_EQ(z.MovesLeft(), 98);
    ASSERT_EQ(z.CheckCoin(11), false);

    ASSERT_EQ(z.Turn(100), true);
    ASSERT_EQ(z.MovesLeft(), 96);
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
        uint64_t M = z.ChooseNext();
        ASSERT_GT(M, 0);
        ASSERT_EQ(z.Turn(M), true);
    }

    ASSERT_EQ(z.ChooseNext(), 0);
}

TEST( Zillionim, RandomPlayLarge )
{
    Zillionim z;
    while (z.IsPlayable())
    {
        uint64_t M = z.ChooseNext();
        ASSERT_GT(M, 0);
        ASSERT_EQ(z.Turn(M), true);
    }

    ASSERT_EQ(z.ChooseNext(), 0);
}

TEST( Main, Basic )
{
    string input = R"(0)";

    string expectation = R"()";

    ASSERT_MAIN_RETURNS(input, 0);
    ASSERT_OUTPUT_EQ(expectation);
}
