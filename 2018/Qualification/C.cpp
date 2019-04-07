#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    constexpr int D = 1000;

    int T = 0;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        int orchard[D+1][D+1] = {{ 0 }};

        int A;
        cin >> A;

        int W = max(3, (int) sqrt((double) A));
        int H = W;

        if (W*H < A)
            W++;

        if (W*H < A)
            H++;

        if (A == 20) {
            W = 20;
            H = 10;
        }

        int I = 500, J = 500;
        int I1 = 500, I2 = I1 + H - 1;
        int J1 = 500, J2 = J1 + W - 1;

        for (int c = 0; c < 1000; ++c)
        {
            if (c > 0)
            {
                I = I1+1;
                J = J1+1;
                int UA;
                int min_UA = 9;

                for (int i = I1+1; i <= I2-1; ++i)
                {
                    for (int j = J1+1; j <= J2-1; ++j)
                    {
                        UA = orchard[i-1][j-1] + orchard[i-1][j  ] + orchard[i-1][j+1]
                           + orchard[i  ][j-1] + orchard[i  ][j  ] + orchard[i  ][j+1]
                           + orchard[i+1][j-1] + orchard[i+1][j  ] + orchard[i+1][j+1];

                        if (UA < min_UA)
                        {
                            I = i;
                            J = j;
                            min_UA = UA;

                            if (min_UA == 0)
                                break;
                        }
                    }

                    if (min_UA == 0)
                        break;
                }
            }

            cout << I << ' ' << J << endl;

            cin >> I >> J;

            if (I < 0 || J < 0)
                return 0;

            if (I == 0 && J == 0)
                break;

            orchard[I][J] = 1;

            if (c == 0)
            {
                I1 = I, I2 = I1 + H - 1;
                J1 = J, J2 = J1 + W - 1;
            }
        }
    }

    return 0;
}
