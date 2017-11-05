#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int T = 0;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int N, P;
        cin >> N >> P;

        vector<int> G(N, 0);
        for (int i = 0; i < N; ++i)
            cin >> G[i];

        vector<int> R(P, 0);
        for (int i = 0; i < N; ++i)
            R[ G[i]%P ]++;

        int result = R[0];
        R[0] = 0;

        for (int j = 1; j < P; ++j) {

            int k = P-j;

            while ((k == j && R[j] >= 2) || (k != j && R[j] > 0 && R[k] > 0)) {
                R[j]--;
                R[k]--;
                ++result;
            }
        }

        int cLeftOver = 0;

        for (int j : {2, 3, 1})
        {
            if (j >= P)
                continue;

            while (R[j] > 0) {
                if (cLeftOver == 0)
                    ++result;
                --R[j];
                cLeftOver = (cLeftOver + P - j) % P;
            }
        }

        if (result > N)
            return 1;

        cout << "Case #" << t << ": " << result << endl;
    }

    return 0;
}
