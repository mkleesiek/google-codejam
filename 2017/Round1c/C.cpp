/**
 * @file C.cpp
 *
 * @date 30.04.2017
 * @author NoSheep (marco@kleesiek.com)
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>

using namespace std;

double h_k(int K, const vector<double>& P)
{
    int N = P.size();

    double result = 0.0;

    vector<bool> flags(N);
    vector<double> Q(P.begin(), P.end());
    for (size_t i = 0; i < Q.size(); ++i) {
        Q[i] = (1.0 - Q[i]);
    }

    for (int l = K; l <= N; ++l) {

        auto it = fill_n(flags.begin(), N-l, false);
        fill_n(it, l, true);

        do {
            double summand = 1.0;
            for (int i = 0; i < N; ++i) {
                summand *= (flags[i]) ? P[i] : Q[i];
            }
            result += summand;
        }
        while( next_permutation(flags.begin(), flags.end()) );
    }

    return result;
}

double h_n(const vector<double>& P)
{
    return accumulate(P.begin(), P.end(), 1.0, std::multiplies<double>());
}

int main()
{
    int T = 0;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int N, K;
        double U;
        cin >> N >> K >> U;

        vector<double> P(N);
        for (int i = 0; i < N; ++i)
            cin >> P[i];

//        double sumP = accumulate(P.begin(), P.end(), 0.0);
        sort(P.begin(), P.end());

        vector<double> PK( next(P.begin(), N-K), P.end() );

        double maxResult = h_k(K, PK);

        const double eps = U / (double) N / 1000.0;

        while (U > 0.0 && maxResult < 1.0) {

            int bestI = 0;
            double bestResult = maxResult;

            for (int i = 0; i < N; ++i) {

                if (PK[i] == 1.0)
                    continue;

                double u = min(U, min(eps, 1.0 - PK[i]));

                PK[i] += u;
                double newResult = h_n(PK);
                PK[i] -= u;

                if (newResult > bestResult || bestResult == 0.0 || PK[i] == 0.0) {
                    bestI = i;
                    bestResult = newResult;
                }
            }

            double u = min(U, min(eps, 1.0 - PK[bestI]));
            PK[bestI] += u;
            U -= u;
            maxResult = bestResult;
        }

        copy(PK.begin(), PK.end(), next(P.begin(), N-K));

        cout << "Case #" << t << ": " << setprecision(12) << h_k(K, P) << endl;
    }

    return 0;
}
