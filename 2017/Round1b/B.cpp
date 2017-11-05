/**
 * @file B.cpp
 *
 * @date 22.04.2017
 * @author NoSheep (marco@kleesiek.com)
 */

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

unordered_map<char, char> sides = {
        {'O', 'B'},
        {'G', 'R'},
        {'V', 'Y'}
};

auto cmp = [](const pair<char, int>& p1, const pair<char, int>& p2) -> bool {
    return (p1.second == p2.second) ? p1.first < p2.first : p1.second > p2.second;
};

bool check(const string& str)
{
    const int N = str.size();
    for (int i = 0; i < N; ++i) {

        const string substr = (i < N-1) ? str.substr(0, i+2) : str + str.front();

        int ni = (i == N-1) ? 0 : i+1;

        switch(str[i]) {
            case 'O': if (str[ni] != 'B') return false; break;
            case 'G': if (str[ni] != 'R') return false; break;
            case 'V': if (str[ni] != 'Y') return false; break;
            case 'B': if (str[ni] == 'B') return false; break;
            case 'R': if (str[ni] == 'R') return false; break;
            case 'Y': if (str[ni] == 'Y') return false; break;
        }

        switch(str[ni]) {
            case 'O': if (str[i] != 'B') return false; break;
            case 'G': if (str[i] != 'R') return false; break;
            case 'V': if (str[i] != 'Y') return false; break;
        }

    }
    return true;
}

string solve(int N, int R, int O, int Y, int G, int B, int V)
{
    vector<pair<char, int>> singleCols = {
            { 'R', R },
            { 'Y', Y },
            { 'B', B }
    };

    vector<pair<char, int>> doubleCols = {
            { 'G', G },
            { 'V', V },
            { 'O', O }
    };

    for (auto &p2 : doubleCols) {
        for (auto& p : singleCols) {
            if (p.first == sides[p2.first] && p2.second > 0) {
                p.second -= p2.second;

                if (p.second == 0) {
                    if (N == 2*p2.second) {
                        string result;
                        for (int i = 0; i < p2.second; ++i) {
                            result.push_back(p2.first);
                            result.push_back(p.first);
                        }
                        return result;
                    }
                    else
                        return "";
                }
                if (p.second < 0)
                    return "";

                break;
            }
        }
    }

    stable_sort(singleCols.begin(), singleCols.end(), cmp);
    stable_sort(doubleCols.begin(), doubleCols.end(), cmp);

    int nSingles = accumulate(singleCols.begin(), singleCols.end(), 0,
         [] (int sum, const auto& p) { return sum + p.second; }
    );

    string result(nSingles, '_');

    for (int i = 0; i < nSingles; i+=2) {
        int ni = (i == N - 1) ? 0 : i + 1;

        for (auto& p : singleCols) {
            if (p.second == 0 || result[ni] == p.first)
                continue;

            result[i] = p.first;
            --p.second;
            break;
        }
    }

    for (int i = 1; i < nSingles; i+=2) {
        int pi = (i == 0) ? N - 1 : i - 1;
        int ni = (i == N - 1) ? 0 : i + 1;

        for (auto& p : singleCols) {
            if (p.second == 0 || result[pi] == p.first || result[ni] == p.first)
                continue;

            result[i] = p.first;
            --p.second;
            break;
        }
    }

    if (result.find('_') != string::npos)
        return "";

    for (auto& p2 : doubleCols) {
        if (p2.second > 0) {
            size_t sPos = result.find(sides[p2.first]);
            for (int i = 0; i < p2.second; ++i) {
                result.insert(sPos+1+2*i, 1, p2.first);
                result.insert(sPos+1+2*i+1, 1, sides[p2.first]);
            }
        }
    }

    return check(result) ? result : "";
}

int main()
{
    int T = 0;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int N, R, O, Y, G, B, V;
        cin >> N >> R >> O >> Y >> G >> B >> V;

        string result = solve(N, R, O, Y, G, B, V);

        if (!result.empty() && !check(result)) {
            cerr << "Strategy failed: " << result << endl;
            result = "";
        }

        cout << "Case #" << t << ": ";
        if (result.empty())
            cout << "IMPOSSIBLE";
        else
            cout << result;
        cout << endl;
    }

    return 0;
}