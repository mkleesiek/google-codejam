/**
 * @file A.cpp
 *
 * @date 15.04.2017
 * @author NoSheep (marco@kleesiek.com)
 */

#include <iostream>
#include <string>

using namespace std;

string nLetters( char cake[50][50], int R1, int R2, int C1, int C2 )
{
    string result;
    for (int r = R1; r < R2; ++r) {
        for (int c = C1; c < C2; ++c) {
            if (cake[r][c]!='?')
                result += cake[r][c];
        }
    }
    return result;
}

void solve( char cake[50][50], int R1, int R2, int C1, int C2 )
{
    string letters = nLetters(cake, R1, R2, C1, C2);

    if (letters.empty()) {
        cerr << "Empty grid." << endl;
        return;
    }

    if (letters.size()==1) {
        for (int r = R1; r < R2; ++r) {
            for (int c = C1; c < C2; ++c) {
                cake[r][c] = letters[0];
            }
        }
        return;
    }

    for (int vCut = C1+1; vCut < C2; ++vCut) {
        string subLetters = nLetters(cake, R1, R2, C1, vCut);
        if (subLetters.size() > 0 && subLetters.size() < letters.size()) {
            solve(cake, R1, R2, C1, vCut);
            solve(cake, R1, R2, vCut, C2);
            return;
        }
    }

    for (int hCut = R1+1; hCut < R2; ++hCut) {
        string subLetters = nLetters(cake, R1, hCut, C1, C2);
        if (subLetters.size() > 0 && subLetters.size() < letters.size()) {
            solve(cake, R1, hCut, C1, C2);
            solve(cake, hCut, R2, C1, C2);
            return;
        }
    }
}

int main()
{
    int T = 0;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int R, C;
        cin >> R >> C;

        char cake[50][50] = { };
        for (int r = 0; r < R; ++r)
            for (int c = 0; c < C; ++c)
                cin >> cake[r][c];

        solve( cake, 0, R, 0, C );

        cout << "Case #" << t << ": " << endl;
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c)
                cout << cake[r][c];
            cout << endl;
        }

    }

    return 0;
}