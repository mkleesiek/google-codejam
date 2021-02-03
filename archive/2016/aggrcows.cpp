/**
 * @file aggrcows.cpp
 *
 * @date 28.10.2016
 * @author marco@kleesiek.com
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool TestDistance(const vector<int>& positions, int C, int d)
{
    int last_stall_pos = positions[0];
    --C;

    for (size_t i = 1; i < positions.size(); ++i) {
        if (positions[i] - last_stall_pos >= d) {
            --C;
            last_stall_pos = positions[i];
        }
        if (C <= 0)
            return true;
    }

    return false;
}

int main()
{
    int nTestCases = 0;
    cin >> nTestCases;

    for (int i = 1; i <= nTestCases; i++) {
        int N = 0;
        cin >> N;

        int C = 0;
        cin >> C;

        vector<int> positions(N, 0);
        for (size_t p = 0; p < N; ++p)
            cin >> positions[p];

        sort(positions.begin(), positions.end());

        int max_distance = ( positions.back() - positions.front() ) / (C-1);
        int min_distance = 0;

        if ( C > 2 ) {


            while( max_distance > min_distance) {
                int test_distance = (max_distance + min_distance) / 2;
                if ( TestDistance(positions, C, test_distance) ) {
                    min_distance = test_distance;
                }
                else {
                    max_distance = test_distance;
                }

            }
        }

        cout << min_distance << endl;

    }

    return 0;
}

