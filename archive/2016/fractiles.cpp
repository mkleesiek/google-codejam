/**
 * @file fractiles.cpp
 *
 * @date 18.10.2016
 * @author marco@kleesiek.com
 */

#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {

        int K, C, S;
        cin >> K >> C >> S;

        cout << "Case #" << t << ":";
        if (S*C < K) {
            cout << " IMPOSSIBLE";
        }
        else {
            for (int64_t i = 0; i < K; i+= C) {
                int64_t p = 0;
                for (int64_t j = 0; j < C; ++j ) {
                  p = p * K + min<int64_t>(i + j, K-1);
                }
                cout << " " << (p+1);
            }
        }
        cout << endl;
    }

    return 0;
}

// LLL > LLL LLL LLL > LLL LLL LLL LLL LLL LLL LLL LLL LLL
// LLG > LLG LLG GGG > LLG LLG GGG LLG LLG GGG GGG GGG GGG
// LGL > LGL GGG LGL > LGL GGG LGL GGG GGG GGG LGL GGG LGL
// LGG > LGG GGG GGG > LGL GGG GGG GGG GGG GGG GGG GGG GGG
// GLL > GGG GLL GLL > GGG GGG GGG GGG GLL GLL GGG GLL GLL
// GLG > GGG GLG GGG > GGG GGG GGG GGG GLG GGG GGG GGG GGG
// GGL > GGG GGG GGL > GGG GGG GGG GGG GGG GGG GGG GGG GGL
// GGG >

// LLLL > LLLL LLLL LLLL LLLL
// LLLG > LLLG LLLG LLLG GGGG
// LLGL > LLGL LLGL GGGG LLGL
// LLGG > LLGG LLGG GGGG GGGG
// LGLL > LGLL GGGG LGLL LGLL
// LGLG >



