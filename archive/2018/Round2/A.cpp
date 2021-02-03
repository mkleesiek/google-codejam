#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(string& result, vector<int>& B)
{
    int C = B.size();

    if (C < 2 || B[0] == 0 || B[C-1] == 0) {
        return 0;
    }

    string newline(C, '.');

    if (result.empty()) {
        result = newline;
        return solve(result, B);
    }

    int nResultRows = std::count(result.begin(), result.end(), '\n') + 1;
    if (nResultRows > C*2)
        return -1;

    if (count(B.begin(), B.end(), 1) == C)
        return nResultRows;


    for (int i = 0; i < C - 1; ++i) {
        if (B[i] > 1 && B[i + 1] < B[i] && newline[i + 1] == '.' && newline[i] != '\\') {
            newline[i + 1] = '/';
            B[i]--;
            B[i + 1]++;
        }
    }

    for (int i = C - 1; i > 1; --i) {
        if (B[i] > 1 && B[i - 1] < B[i] && newline[i - 1] == '.' && newline[i] != '/') {
            newline[i - 1] = '\\';
            B[i]--;
            B[i - 1]++;
        }
    }

    result = newline + "\n" + result;

    return solve(result, B);
}

//int main(int argc, char* argv[])
//{
//    ifstream in;
//    if(argc == 3)
//    {
//        const string inFile = argv[2];
//        in =  ifstream(inFile);
//        cin.rdbuf(in.rdbuf());
//    }

int main()
{
    int T = 0;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        int C;
        cin >> C;

        vector<int> B(C);

        for (int i = 0; i < C; ++i)
            cin >> B[i];


        string result;

        int N = solve(result, B);

        if (N < 1) {
            cout << "Case #" << (t+1) << ": " << "IMPOSSIBLE" << endl;
        } else {
            cout << "Case #" << (t+1) << ": " << N << endl << result << endl;
        }

    }

    return 0;
}
