#include <gtest/gtest.h>

#include "C.h"

using namespace std;

TEST( GreatestCommonDivisor, Basic )
{
    ASSERT_EQ( gcd(12, 8), 4 );
    ASSERT_EQ( gcd(8, 12), 4 );
    ASSERT_EQ( gcd(8, 8), 8 );
}