#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Moves
{
    R = 1,
    P = 2,
    S = 4
};

string solve(vector<string>& C)
{
    size_t maxLength = 0;
    for (size_t j = 0; j < C.size(); ++j)
        maxLength = max(C[j].size(), maxLength);

    string result;

    for (size_t i = 0; i < maxLength; ++i)
    {
        int possibleMoves = R | P | S;

        int cR = 0;
        int cP = 0;
        int cS = 0;

        for (size_t j = 0; j < C.size(); j++)
        {
            if (C[j].empty())
                continue;

            const char& adMove = C[j][i % C[j].size()];
            if (adMove == 'R')
            {
                possibleMoves &= ~S;
                cP++;
                cR = cS = 0;
            }
            else if (adMove == 'S')
            {
                possibleMoves &= ~P;
                cR++;
                cP = cS = 0;
            }
            else if (adMove == 'P')
            {
                possibleMoves &= ~R;
                cS++;
                cR = cP = 0;
            }
        }

        if (possibleMoves == 0)
            return "IMPOSSIBLE";

        if (cR != 0)
        {
            result += 'R';
            for (size_t j = 0; j < C.size(); j++)
            {
                if (C[j].empty())
                    continue;
                const char& adMove = C[j][i % C[j].size()];
                if (adMove == 'S')
                    C[j].clear();
            }
        }
        else if (cP != 0)
        {
            result += 'P';
            for (size_t j = 0; j < C.size(); j++)
            {
                if (C[j].empty())
                    continue;
                const char& adMove = C[j][i % C[j].size()];
                if (adMove == 'R')
                    C[j].clear();
            }
        }
        else if (cS != 0)
        {
            result += 'S';
            for (size_t j = 0; j < C.size(); j++)
            {
                if (C[j].empty())
                    continue;
                const char& adMove = C[j][i % C[j].size()];
                if (adMove == 'P')
                    C[j].clear();
            }
        }
        else if ((possibleMoves & R) != 0)
            result += 'R';
        else if ((possibleMoves & P) != 0)
            result += 'P';
        else if ((possibleMoves & S) != 0)
            result += 'S';

        maxLength = 0;
        for (size_t j = 0; j < C.size(); ++j)
            maxLength = max(C[j].size(), maxLength);
    }

    return result;
}

int main()
{

    int T = 0;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        int A = 0;
        cin >> A;

        vector<string> C(A);

        for (int j = 0; j < A; j++)
            cin >> C[j];

        string solution = solve(C);

        cout << "Case #" << (t+1) << ": " << solution << endl;
    }

    return 0;
}
