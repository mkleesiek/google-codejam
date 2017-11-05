/**
 * @file sheep.cpp
 *
 * @date 17.10.2016
 * @author marco@kleesiek.com
 */

#include <iostream>
#include <bitset>

using namespace std;

int solve(int N)
{
    bitset<10> bs;
    for (int i = 1; i <= 100; i++) {
        const int x = i * N;
        int tmp = x;
        do {
            bs.set( tmp % 10 );
            tmp /= 10;
        } while ( tmp > 0);
        if ( bs.all() )
            return x;
    }
    return -1;
}

int main()
{
    int nTestCases = 0;
    cin >> nTestCases;

    for (int i = 1; i <= nTestCases; i++) {
        int N = 0;
        cin >> N;

        int result = solve(N);

        cout << "Case #" << i << ": ";
        if (result < 0)
            cout << "INSOMNIA";
        else
            cout << result;
        cout << endl;
    }
}
