#include "testing.h"
#include "utilities.h"

#include "B.cpp"

#include <random>
#include <stdexcept>

using namespace std;

static mt19937 gen;

TEST( calc_sum, Examples )
{
    vector<uint32_t> pancakes = {2, 1, 2};
    ASSERT_EQ(calc_sum(pancakes), 1);

    pancakes = {1, 6, 2, 5, 7};
    ASSERT_EQ(calc_sum(pancakes), 16);

    pancakes = {1000000000, 1, 1, 1000000000};
    ASSERT_EQ(calc_sum(pancakes), 999999991);
}

TEST( calc_sum, SmallGeneratedSets )
{
    for (int t = 0; t < 100; t++) {

        cout << "Testcase: " << t+1 << " ...";
        cout.flush();

        size_t S = 3000;
        vector<uint32_t> pancakes(S, 0);

        uniform_int_distribution<uint32_t> dist(1, 1'000'000'000);
        for (auto& p : pancakes)
            p = dist(gen);

        precalc(pancakes);

        cout << endl;
        cout.flush();
    }
}

TEST( calc_sum, LargeGeneratedSets )
{
    for (int t = 0; t < 100; t++) {

        cout << "Testcase: " << t+1 << " ...";
        cout.flush();

        size_t S = 100'000;
        vector<uint32_t> pancakes(S, 0);

        uniform_int_distribution<uint32_t> dist(1, 1'000'000'000);
        for (auto& p : pancakes)
            p = dist(gen);

        precalc(pancakes);

        cout << endl;
        cout.flush();
    }
}

TEST( Main, Basic )
{
    string input = R"(0)";
    string expectation = R"()";

    ASSERT_MAIN_RETURNS(input, 0);
    ASSERT_OUTPUT_EQ(expectation);
}

TEST( Main, Examples )
{
    string input = R"(3
3
2 1 2
5
1 6 2 5 7
4
1000000000 1 1 1000000000
)";
    string expectation = R"(Case #1: 1
Case #2: 16
Case #3: 999999991
)";

    ASSERT_MAIN_RETURNS(input, 0);
    ASSERT_OUTPUT_EQ(expectation);
}