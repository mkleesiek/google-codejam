/**
 * @file B.cpp
 *
 * @date 15.04.2017
 * @author NoSheep (marco@kleesiek.com)
 */

#include <iostream>
#include <set>
#include <tuple>
#include <limits>

using namespace std;

constexpr uint8_t kMaxN = 50;
constexpr uint8_t kMaxP = 50;

int main()
{
    int T = 0;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int N, P;
        cin >> N >> P;

        int R[kMaxN] = {};

        for (int i = 0; i < N; ++i)
            cin >> R[i];

        struct Cmp {
            bool operator()(const pair<int, int>& p1, const pair<int, int>& p2)
            {
                return p1.second < p2.second;
            }
        };

        multiset<pair<int, int>, Cmp> packages[kMaxN];

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < P; ++j) {
                int Qij;
                cin >> Qij;

                pair<int, int> newRange{0,0};

                int nServ = Qij / R[i];
                while ( nServ > 0 && nServ*R[i] >= 10*abs(Qij - nServ*R[i]) ) {
                    newRange.first = nServ--;
                }

                nServ = Qij / R[i] + 1;
                while ( nServ < numeric_limits<int>::max() && nServ*R[i] >= 10*abs(Qij - nServ*R[i]) ) {
                    newRange.second = nServ++;
                }

                if (newRange.first == 0 && newRange.second == 0)
                    continue;

                if (newRange.first == 0)
                    newRange.first = newRange.second;
                else if (newRange.second == 0)
                    newRange.second = newRange.first;

                packages[i].insert(newRange);
            }
        }

        int nKits = 0;

        while (!packages[0].empty()) {

            auto smallestHighRange = packages[0].begin();
            int smallestHighRangeIndex = 0;
            int low = smallestHighRange->first;
            int high = smallestHighRange->second;

            for (int i = 0; i < N; ++i) {
                if (packages[i].empty())
                    break;

                auto rangeIt = packages[i].begin();
                if (rangeIt->second < high) {
                    low = rangeIt->first;
                    high = rangeIt->second;
                    smallestHighRange = rangeIt;
                    smallestHighRangeIndex = i;
                }
            }

            packages[smallestHighRangeIndex].erase(smallestHighRange);

            for (int i = 0; i < N; ++i) {

                if (i == smallestHighRangeIndex)
                    continue;

                bool rangeIFound = false;
                for (auto rangeIt = packages[i].begin(); rangeIt != packages[i].end(); ++rangeIt) {
                    if (rangeIt->first <= high && rangeIt->second >= low) {
                        low = max(low, rangeIt->first);
                        high = min(high, rangeIt->second);
                        packages[i].erase(rangeIt);
                        rangeIFound = true;
                        break;
                    }
                }

                if (!rangeIFound) {
                    low = high = 0;
                }
            }

            if (low != 0 && high != 0)
                ++nKits;
        }

        cout << "Case #" << t << ": " << nKits << endl;
    }

    return 0;
}
