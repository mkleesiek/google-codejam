#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int ceil_div(int a, int b)
{
    return a/b + (a % b != 0);
}

int main()
{
    int T = 0;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int N, C, M;
        cin >> N >> C >> M;

        vector<int> nTicketsAtPos(N, 0);
        vector<int> nTicketsUptoPos(N, 0);
        vector<int> nTicketsPerCust(C, 0);

        int P, B;
        for (int t = 0; t < M; ++t)
        {
            cin >> P >> B;

            ++nTicketsAtPos[P-1];

            for (int i = P-1; i < N; ++i)
                ++nTicketsUptoPos[i];

            ++nTicketsPerCust[B-1];
        }

        // number of trains
        int R = *max_element(nTicketsPerCust.begin(), nTicketsPerCust.end());
        for (int p = 1; p <= N; ++p) {
            const int PS = ceil_div(nTicketsUptoPos[p - 1], p);
            R = max(R, PS);
        }

        // number of ticket promotions
        int T = 0;
        for (int p = 0; p < N; ++p) {
            if (nTicketsAtPos[p] > R)
                T += nTicketsAtPos[p] - R;
        }

        cout << "Case #" << t << ": " << R << " " << T << endl;
    }

    return 0;
}