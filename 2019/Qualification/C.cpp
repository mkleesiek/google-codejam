#include "C.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
    ifstream in;
    if (argc == 2)
    {
        const string inFile = argv[1];
        in =  ifstream(inFile);
        cin.rdbuf(in.rdbuf());
    }

    int T = 0;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        int N;
        int L;
        cin >> N >> L;

        vector<int> C(L);

        for (int i = 0; i < L; i++)
        {
            cin >> C[i];
        }

        cout << "Case #" << (t+1) << ": ";

        int D = __gcd(C[0], C[1]);
        vector<int> P(L+1, 0);
        P[0] = C[0] / D;
        P[1] = D;
        
        for (size_t j = 2; j < P.size(); j++)
        {
            P[j] = C[j-1] / P[j-1];
        }

        set<int> primes(P.begin(), P.end());
        unordered_map<int, char> pmap;

        char c = 'A';
        for (auto p : primes)
        {
            pmap[p] = c++;
        }

        for (auto p : P)
            cout << pmap[p];

        cout << endl;
    }

    return 0;
}
