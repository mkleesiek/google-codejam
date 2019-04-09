#include <gtest/gtest.h>

#define GTEST

#include "C.cpp"

using namespace std;

TEST( GreatestCommonDivisor, Basic )
{
    ASSERT_EQ( __gcd(12, 8), 4 );
    ASSERT_EQ( __gcd(8, 12), 4 );
    ASSERT_EQ( __gcd(8, 8), 8 );
}

TEST( Solve, Basic )
{

}
