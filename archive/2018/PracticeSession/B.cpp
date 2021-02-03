#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int guess_number(int A, int B) {
    return (B+A+1) / 2;
}

string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
    int T = 0;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        int N;
        cin >> N;

        vector<int> P(N, 0);

        for (int i = 0; i < N; ++i)
            cin >> P[i];

        int S = accumulate(P.begin(), P.end(), 0);

        cout << "Case #" << (t+1) << ":";

        while (S > 0)
        {
            cout << " ";

            auto it = max_element(P.begin(), P.end());
            int i = distance(P.begin(), it);
            int c = count(P.begin(), P.end(), *it);
            cout << alpha[i];
            P[i]--;
            S--;

            if (c != 2)
                continue;

            if (S == 0)
                break;

            it = max_element(P.begin(), P.end());
            i = distance(P.begin(), it);
            cout << alpha[i];
            P[i]--;
            S--;
        }

        cout << endl;
    }

    return 0;
}
