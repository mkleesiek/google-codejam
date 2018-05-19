#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

bool shift(vector<int>& G, const vector<pair<int,int>>& R, int m = 0, int c = 0)
{
    if (R[m].first == 0 || R[m].second == 0)
        return false;

    int M = G.size();

    if (c > M)
        return false;

    if ((R[m].first != R[m].second && G[R[m].first] > 0 && G[R[m].second] > 0) || (R[m].first == R[m].second && G[R[m].first] > 1))
    {
        G[m]++;
        G[R[m].first]--;
        G[R[m].second]--;
        return true;
    }

    if (G[R[m].first] < G[R[m].second])
        return shift(G, R, R[m].first, c+1);
    else
        return shift(G, R, R[m].second, c+1);
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
        int M;
        cin >> M;

        vector<int> G(M, 0);
        vector<pair<int, int>> R(M, {0, 0 });

        for (int m = 0; m < M; ++m) {
            cin >> R[m].first >> R[m].second;
            R[m].first--;
            R[m].second--;
        }

        for (int m = 0; m < M; ++m) {
            cin >> G[m];
        }


        while (shift(G, R)) { };


        cout << "Case #" << (t+1) << ": " << G[0] << endl;
    }

    return 0;
}
