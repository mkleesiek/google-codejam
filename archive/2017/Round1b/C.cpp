/**
 * @file C.cpp
 *
 * @date 22.04.2017
 * @author NoSheep (marco@kleesiek.com)
 */

#include <iostream>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <iomanip>

using namespace std;

constexpr size_t NMAX = 100;

int main()
{
    int T = 0;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int N, Q;
        cin >> N >> Q;

        int E[NMAX], S[NMAX];
        int D[NMAX][NMAX];

        for (int i = 0; i < N; ++i) {
            cin >> E[i] >> S[i];
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> D[i][j];
            }
        }

        double T[NMAX][NMAX] = { 0 };

        for (int i = 0; i < N; ++i)
        {
            int speed = S[i];
            unordered_map<int, int> cityToEnduranceMap = { {i, E[i]} };
            T[i][i] = 0.0;

            while (!cityToEnduranceMap.empty())
            {
                int cCity = cityToEnduranceMap.begin()->first;
                int cEndurance = cityToEnduranceMap.begin()->second;
                cityToEnduranceMap.erase(cityToEnduranceMap.begin());

                for (int j = 0; j < N; ++j)
                {
                    if (i == j || j == cCity || D[cCity][j] <= 0 || D[cCity][j] > cEndurance)
                        continue;

                    double nextCityTime = T[i][cCity] + (double) D[cCity][j] / (double) speed;
                    if (T[i][j] <= 0.0 || T[i][j] > nextCityTime) {
                        T[i][j] = nextCityTime;
                        if (cEndurance > D[cCity][j])
                            cityToEnduranceMap[j] = cEndurance - D[cCity][j];
                    }
                }
            }

        }

        cout << "Case #" << t << ":";

        for (int k = 0; k < Q; ++k) {
            int U, V;
            cin >> U >> V;

            --U; --V;

            double totalTime = 0.0;

            bool visited[NMAX] = { };
            multimap<double, int> visitQueue = { {0.0, U} };

            while(!visitQueue.empty())
            {
                double cTime = visitQueue.begin()->first;
                int cCity = visitQueue.begin()->second;
                visitQueue.erase(visitQueue.begin());
                visited[cCity] = true;

                if (cCity == V) {
                    totalTime = cTime;
                    break;
                }

                for (int j = 0; j < N; ++j)
                {
                    if (!visited[j] && T[cCity][j] > 0.0)
                    {
                        visitQueue.emplace(cTime + T[cCity][j], j);
                    }
                }
            }

            cout << " " << setprecision(12) << totalTime;
        }

        cout << endl;
    }

    return 0;
}