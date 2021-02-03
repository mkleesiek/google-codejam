#include <fstream>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

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
        int S;
        cin >> S;

        vector<int> D(S), A(S), B(S);
        for (int s = 0; s < S; ++s) {
            cin >> D[s] >> A[s] >> B[s];
        }

        unordered_map<int, set<int>> valid_M, valid_N;

        for (int s = 0; s < S; ++s) {
            int M = D[s] + A[s];
            int N = D[s] - B[s];
            valid_M[M].insert(s);
            valid_N[N].insert(s);
        }


        int longest_range = 0;
        set<int> ranges;

        for (auto vM : valid_M) {
            for (auto vN : valid_N) {
                set<int> signs = vM.second;
                signs.insert(vN.second.begin(), vN.second.end());
                int n = 0;
                int last_s = -1;
                for (int s : signs) {
                    if (last_s == -1 || s - last_s > 1) {
                        n = 1;
                        last_s = s;
                    }
                    else {
                        ++n;
                        last_s = s;
                    }
                    if (longest_range < n) {
                        longest_range = n;
                        ranges.clear();
                        ranges.insert(s);
                    }
                    else if (longest_range == n) {
                        ranges.insert(s);
                    }
                }
            }
        }


        cout << "Case #" << (t+1) << ": " << longest_range << ", " << ranges.size() << endl;
    }

    return 0;
}
