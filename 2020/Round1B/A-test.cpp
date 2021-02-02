#include "testing.h"
#include "utilities.h"

#include "A.cpp"

using namespace std;

TEST( Round_2020_1B_A, MSB ){
	ASSERT_EQ(msb(1), 0);
	ASSERT_EQ(msb(-1), 0);
	ASSERT_EQ(msb(2), 1);
	ASSERT_EQ(msb(3), 1);
	ASSERT_EQ(msb(8), 3);
	ASSERT_EQ(msb(-8), 3);
}

TEST( Round_2020_1B_A, Basic ){
	string r{};

	r = {};
	solve(1,4,r);
	ASSERT_EQ(r, "IMPOSSIBLE");

	r = {};
	solve(0,4,r);
	ASSERT_EQ(r, "IMPOSSIBLE");

	r = {};
	solve(2,4,r);
	ASSERT_EQ(r, "IMPOSSIBLE");

	r = {};
	solve(3,3,r);
	ASSERT_EQ(r, "IMPOSSIBLE");

	r = {};
	solve(1,3,r);
	ASSERT_EQ(r, "IMPOSSIBLE");

	r = {};
	solve(3,4,r);
	ASSERT_EQ(r, "EEN");

	r = {};
	solve(-3,4,r);
	ASSERT_EQ(r, "WWN");

	r = {};
	solve(1,2,r);
	ASSERT_EQ(r, "EN");

	r = {};
	solve(2,1,r);
	ASSERT_EQ(r, "NE");

	r = {};
	solve(4,4,r);
	ASSERT_EQ(r, "IMPOSSIBLE");

	r = {};
	solve(-4,-4,r);
	ASSERT_EQ(r, "IMPOSSIBLE");

	r = {};
	solve(1,0,r);
	ASSERT_EQ(r, "E");

	r = {};
	solve(-1,0,r);
	ASSERT_EQ(r, "W");

	r = {};
	solve(0,1,r);
	ASSERT_EQ(r, "N");

	r = {};
	solve(0,-1,r);
	ASSERT_EQ(r, "S");
}

TEST( Round_2020_1B_A, Main ){
    string input = R"(4
2 3
-2 -3
3 0
-1 1
)";

    string expectation = R"(Case #1: SEN
Case #2: NWS
Case #3: EE
Case #4: IMPOSSIBLE
)";

    ASSERT_MAIN_RETURNS(input, 0);
    ASSERT_OUTPUT_EQ(expectation);
}
