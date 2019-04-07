#pragma once

#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    if (a < b)
        swap(a, b);
    return gcd(b, a % b);
}
