/**
 * @file A.cpp
 *
 * @date 22.04.2017
 * @author NoSheep (marco@kleesiek.com)
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int T = 0;
    cin >> T;

//    int K[1000];
//    int S[1000];
//    double eta[1000];

    for (int t = 1; t <= T; ++t)
    {
        int D, N;
        cin >> D >> N;

        double maxEta = 0.0;

        for (int i = 0; i < N; ++i) {
//            cin >> K[i] >> S[i];
//            eta[i] = (double) (D-K[i]) / (double) S[i];

            int K, S;
            cin >> K >> S;
            double eta = (double) (D-K) / (double) S;

            maxEta = max(maxEta, eta);
        }

        double speed = (double) D / maxEta;

        cout << "Case #" << t << ": " << setprecision(12) << speed << endl;
    }

    return 0;
}