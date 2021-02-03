#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int round_closest(int dividend, int divisor)
{
    return (dividend + (divisor / 2)) / divisor;
}

int round_down(int dividend, int divisor)
{
    return dividend / divisor;
}

int main(int argc, char* argv[])
{
    ifstream in;
    if(argc == 3)
    {
        const string inFile = argv[2];
        in =  ifstream(inFile);
        cin.rdbuf(in.rdbuf());
    }

//int main()
//{
    int T = 0;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {

        int N, L;
        cin >> N >> L;

        vector<int> C(N, 0);
        int S = 0;

        for (int l = 0; l < L; ++l) {
            cin >> C[l];
            S += C[l];
        }

        if (round_closest(100, N) > round_down(100, N))
        {
            for (; S < N; ++S)
            {
                 C[L++] = 1;
            }
        }

        for (; S < N; ++S)
        {
            for (int l = 0; l < N; ++l) {

                if (C[l] == 0) {
                    C[l]++;
                    break;
                }

                int c1 = round_closest(C[l]*100, N);
                int d1 = round_down(C[l]*100, N);
                int c2 = round_closest((C[l]+1)*100, N);
                int d2 = round_down((C[l]+1)*100, N);

                if (c1-d1 < c2-d2) {
                    C[l]++;
                    break;
                }
            }
        }

        int MAX = 0;

        for (int l = 0; l < N; ++l) {
            MAX += round_closest(C[l]*100, N);
        }

        cout << "Case #" << (t+1) << ": " << MAX << endl;
    }

    return 0;
}
