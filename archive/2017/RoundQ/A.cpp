/**
 * @file quali-a.cpp
 *
 * @date 08.04.2017
 * @author NoSheep (marco@kleesiek.com)
 */

#include <iostream>

using namespace std;

int solve(string& S, size_t K)
{
    size_t c = 0;
    size_t i = 0;

    for (; i <= S.length()-K; ++i)
    {
        if (S[i] == '-')
        {
            for (size_t k = 0; k < K; ++k)
            {
                S[i+k] = (S[i+k] == '-') ? '+' : '-';
            }
            ++c;
        }
    }

    for (; i < S.length(); ++i)
    {
        if (S[i] == '-')
            return -1;
    }

    return c;
}

int main()
{
    int nTestCases = 0;
    cin >> nTestCases;

    for (int i = 1; i <= nTestCases; ++i)
    {
        string S;
        cin >> S;

        int K;
        cin >> K;

        int result = solve(S, K);

        cout << "Case #" << i << ": ";
        if (result < 0)
            cout << "IMPOSSIBLE";
        else
            cout << result;
        cout << endl;
    }
}
