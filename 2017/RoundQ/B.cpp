/**
 * @file quali-b.cpp
 *
 * @date 08.04.2017
 * @author NoSheep (marco@kleesiek.com)
 */

#include <iostream>

using namespace std;

uint64_t solve( uint64_t n )
{
    int previousDigit = 10;
    uint64_t base = n;
    uint64_t divisor = 1;

    while (base > 0)
    {
        int currentDigit = base % 10;

        if (currentDigit > previousDigit) {
            n -= n % divisor + 1;
            --currentDigit;
        }

        divisor *= 10;
        base /= 10;
        previousDigit = move( currentDigit );
    }

    return n;
}

int main()
{
    int T = 0;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        uint64_t N;
        cin >> N;

        uint64_t result = solve( N );

        cout << "Case #" << t << ": " << result << endl;
    }
}
