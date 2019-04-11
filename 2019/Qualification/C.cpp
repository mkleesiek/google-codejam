#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

template<typename T>
string solve(const vector<T>& C)
{
    T D = __gcd(C[0], C[1]);
    vector<T> P(C.size()+1, 0);
    P[0] = C[0] / D;
    P[1] = D;
    
    for (size_t j = 2; j < P.size(); j++)
    {
        P[j] = C[j-1] / P[j-1];
    }

    set<T> primes(P.begin(), P.end());
    unordered_map<T, char> pmap;

    char c = 'A';
    for (auto p : primes)
    {
        pmap[p] = c++;
    }

    string result(P.size(), ' ');
    for (size_t i = 0; i < P.size(); i++)
        result[i] = pmap[P[i]];

    return result;
}

#ifndef GTEST
int main(int /*argc*/, char* /*argv*/[])
#else
int test()
#endif // GTEST
{

    int T = 0;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        int N;
        int L;
        cin >> N >> L;

        vector<int> C(L);

        for (int i = 0; i < L; i++)
            cin >> C[i];

        cout << "Case #" << (t+1) << ": ";

        string solution = solve(C);

        cout << solution << endl;
    }

    return 0;
}
