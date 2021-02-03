/**
 * @file A.cpp
 *
 * @date 30.04.2017
 * @author NoSheep (marco@kleesiek.com)
 */

#include <iostream>
#include <iomanip>
#include <map>
#include <cmath>
#include <set>

using namespace std;

constexpr int NMAX = 1000;

constexpr double PI = 3.141592653589793;

template <class T>
struct Cmp1 {
    bool operator() (const T& p1, const T& p2) {
        return (p1.first == p2.first) ? p1.second > p2.second : p1.first > p2.first;
    };
};

template <class T>
struct Cmp2 {
    bool operator() (const T& p1, const T& p2) {
        return 2.0*PI*p1.first*p1.second > 2.0*PI*p2.first*p2.second;
    };
};

int main()
{
    int T = 0;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int N, K;
        cin >> N >> K;

        multiset<pair<int, int>, Cmp1<pair<int, int>>> pancakes;

        for (int i = 0; i < N; ++i)
        {
            int R, H;
            cin >> R >> H;
            pancakes.emplace( R, H );
        }

        double maxResult = 0.0;
        for (int s = 0; s <= N-K; ++s)
        {
            auto it = next(pancakes.begin(), s);
            double result = PI*pow(it->first, 2.0) + 2.0*PI*it->first*it->second;;

            multiset<pair<int, int>, Cmp2<pair<int, int>>> kPancakes(next(it, 1), pancakes.end());

            for (auto it2 = kPancakes.begin(); it2 != next(kPancakes.begin(), K-1); ++it2)
            {
                result += 2.0*PI*it2->first*it2->second;
            }

            maxResult = max(maxResult, result);
        }

        cout << "Case #" << t << ": " << setprecision(12) << maxResult << endl;
    }

    return 0;
}
