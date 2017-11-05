/**
 * @file quali-c.cpp
 *
 * @date 08.04.2017
 * @author NoSheep (marco@kleesiek.com)
 */

#include <iostream>
#include <tuple>
#include <map>

using namespace std;

pair<uint64_t, uint64_t> solve( uint64_t N, uint64_t K )
{
    map<uint64_t, uint64_t, greater<uint64_t>> intervalCounter;

    if (N > 2)
        intervalCounter[(N-1)/2]++;
    if (N > 1)
        intervalCounter[N/2]++;
    --K;

    while (K > 0 && intervalCounter.size() > 0)
    {
        auto currentIntervalIt = intervalCounter.begin();

        uint64_t n = currentIntervalIt->first;

        --(currentIntervalIt->second);
        if (currentIntervalIt->second == 0)
            intervalCounter.erase( currentIntervalIt );
        --K;

        if (n > 2)
            intervalCounter[ (n-1)/2 ]++;
        if (n > 1)
            intervalCounter[ n/2 ]++;

        if (K == 0)
            return { n/2, (n-1)/2 };
    }

    if (intervalCounter.size() > 0 && intervalCounter.cbegin()->second > 1)
        return { intervalCounter.cbegin()->first, intervalCounter.cbegin()->first };
    else if (intervalCounter.size() > 1)
        return { intervalCounter.cbegin()->first, intervalCounter.crbegin()->first };
    else if (intervalCounter.size() > 0)
        return { intervalCounter.cbegin()->first, 0 };
    else
        return { 0, 0 };
}

int main()
{
    int T = 0;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        uint64_t N, K;
        cin >> N >> K;

        uint64_t minS, maxS;
        tie( maxS, minS ) = solve( N, K );

        cout << "Case #" << t << ": " << maxS << ' ' << minS << endl;
    }
}
