#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int count(const vector<vector<int>>& A, int row, int col, int val)
{
    int result = 0;

    if (row < 0) {
        for (int i = 0; i < A.size(); ++i)
            if (A[i][col] == val)
                result++;
    }
    else {
        for (int j = 0; j < A.size(); ++j)
            if (A[row][j] == val)
                result++;
    }

    return result;
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

        int N;
        cin >> N;

        vector<vector<int>> A(N, vector<int>(N));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                cin >> A[i][j];


        vector<vector<pair<int, int>>> counts(N, vector<pair<int,int>>(N, {0, 0}));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {

                counts[i][j] = { count(A, i, -1, A[i][j]), count(A, -1, j, A[i][j]) };
            }
        }

        int C = 0;

        while (true)
        {
            int maxCount = 1;
            pair<int, int> maxIndices = {-1, -1};

            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {

                    int mc = counts[i][j].first + counts[i][j].second;
                    if (mc > maxCount) {
                        maxCount = mc;
                        maxIndices = {i, j};
                    }
                }
            }

            if (maxCount <= 2)
                break;

            for (int a = -N; a < N+1; ++a) {
                if (a == 0)
                    continue;

                if (count(A, maxIndices.first, -1, a) == 0 && count(A, -1, maxIndices.second, a) == 0) {
                    A[maxIndices.first][maxIndices.second] = a;

                    for (int i = 0; i < N; ++i)
                        counts[i][maxIndices.second].second = count(A, -1, maxIndices.second, A[i][maxIndices.second]);

                    for (int j = 0; j < N; ++j)
                        counts[maxIndices.first][j].first = count(A, maxIndices.first, -1, A[maxIndices.first][j]);


                    C++;
                    break;
                }
            }
        }


        cout << "Case #" << (t+1) << ": " << C << endl;
    }

    return 0;
}
