#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
uint32_t calc_single(const T& p, size_t L, size_t R)
{
    auto it_max = max_element(p.begin() + L, p.end() - R);

    uint32_t result = 0;
    uint32_t last = 0;
    for (auto it = p.begin() + L; it != it_max; it++) {
        if (*it < last) {
            result += last - *it;
            result %= 1'000'000'007;
        }
        else {
            last = *it;
        }
    }
    last = 0;
    for (auto it = p.end() - R - 1; it != it_max; it--) {
        if (*it < last) {
            result += last - *it;
            result %= 1'000'000'007;
        }
        else {
            last = *it;
        }
    }
    return result;
}

template<class T>
uint32_t calc_sum(const T& p)
{
    uint32_t result = 0;
    for (size_t L = 0; L <= p.size() - 3; L++) {
        for (size_t R = 0; R + L + 3 <= p.size(); R++) {
            result += calc_single(p, L, R);
            result %= 1'000'000'007;
        }
    }
    return result;
}

int main()
{

    int T = 0;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        size_t S;
        cin >> S;

        vector<uint32_t> pancakes(S, 0);

        for (uint32_t i = 0; i < S; i++)
            cin >> pancakes[i];

        uint32_t result = calc_sum(pancakes);

        cout << "Case #" << (t+1) << ": ";
        cout << result;
        cout << endl;
    }

    return 0;
}
