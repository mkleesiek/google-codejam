/**
 * @file C.cpp
 *
 * @date 15.04.2017
 * @author NoSheep (marco@kleesiek.com)
 */

#include <iostream>

using namespace std;

int simulate( int Hd, int hd, int ad, int hk, int ak)
{
    if (hd <= 0)
        return -1;

    int n = 0;

    bool lastRoundCured = false;

    while (n < 1000000000)
    {
        ++n;

        // cure
        if (hd <= ak && hk > ad) {
            // give up
            if (lastRoundCured)
                return -1;
            else {
                hd = Hd;
                lastRoundCured = true;
            }
        }
        // attack
        else {
            hk -= ad;
            lastRoundCured = false;
        }

        if (hk <= 0)
            break;

        hd -= ak;

        if (hd <= 0)
            return -1;
    }

    return n;
}

int main()
{
    int T = 0;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int Hd, Ad, Hk, Ak, B, D;
        cin >> Hd >> Ad >> Hk >> Ak >> B >> D;

        int nTurns = -1;

        for (int b = 0; b <= 50000; ++b) {
            for (int d = 0; d <= 5000; ++d) {

                int hd = Hd, ad = Ad, ak = Ak;

                for (int i = 0; i < d; ++i) {
                    ak = max(0, ak - D);
                    hd -= ak;
                }

                ad += b * B;
                hd -= b * ak;

                if (hd <= 0)
                    break;

                int n2Turns = simulate(Hd, hd, ad, Hk, ak);
                if (n2Turns >= 0) {
                    n2Turns += b+d;
                    if (nTurns < 0)
                        nTurns = n2Turns;
                    else
                        nTurns = min( nTurns, n2Turns );
                }

                if (D == 0 || ak == 0)
                    break;
            }

            if (B == 0)
                break;
        }

        cout << "Case #" << t << ": ";
        if (nTurns < 0)
            cout << "IMPOSSIBLE";
        else
            cout << nTurns;
        cout << endl;
    }

    return 0;
}