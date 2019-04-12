#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

template<typename T>
string decrypt(const vector<T>& C)
{  
    size_t k = 0;
    T D = 0;
    for (; k < C.size()-1; k++)
    {
        if (C[k] == C[k+1])
            continue;

        D = __gcd(C[k], C[k+1]);
        break;
    }

    vector<T> P(C.size()+1, 0);

    P[k+1] = D;

    for (size_t j = k+1; j-- > 0;)
        P[j] = C[j] / P[j+1];

    for (size_t j = k+2; j < P.size(); j++)
        P[j] = C[j-1] / P[j-1];
    
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

int main()
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

        string solution = decrypt(C);

        cout << solution << endl;
    }

    return 0;
}
