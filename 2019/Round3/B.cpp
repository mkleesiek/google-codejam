#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator() (const pair<T1, T2>& p) const
    { 
        return hash<T1>{}(p.first) ^ hash<T2>{}(p.second); 
    } 
};

static unordered_map<pair<uint32_t, uint32_t>, uint32_t, hash_pair> cache_left;
static unordered_map<pair<uint32_t, uint32_t>, uint32_t, hash_pair> cache_right;

constexpr uint32_t MOD = 1'000'000'007;

template<class T>
void precalc(const T& p)
{
    cache_left.clear();
    cache_right.clear();

    for (size_t i = 0; i < p.size(); i++) {
        uint32_t sum = 0;
        for (size_t j = i-1; j > size_t(-1); j--) {
            if (p[j] > p[i])
                break;
            if (p[j] > p[j+1]) {
                sum = (sum + p[j] - p[j+1]) % MOD;
            }
            cache_left.emplace(make_pair(i,j), sum);
        }
        for (size_t j = i+1; j < p.size(); j++) {
            if (p[j] > p[i])
                break;
            if (p[j] > p[j-1]) {
                sum = (sum + p[j] - p[j-1]) % MOD;
            }
            cache_right.emplace(make_pair(i,j), sum);
        }
    }
}

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

//        precalc(pancakes);

        uint32_t result = calc_sum(pancakes);

        cout << "Case #" << (t+1) << ": ";
        cout << result;
        cout << endl;
    }

    return 0;
}
