#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string solve(string& N)
{
    string result;

    for (size_t i = 0; i < N.length(); i++)
    {
        if (N[i] == '4')
        {
            if (result.empty())
                result.resize(N.length()-i, '0');
            
            N[i] = '3';
            result[result.length() - N.length() + i] = '1';
        }
        else if (!result.empty())
        {
            result[result.length() - N.length() + i] = '0';
        }
    }

    if (result.empty())
        result = '0';

    return result;
}

int main()
{
    int T = 0;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        string A;
        cin >> A;

        cout << "Case #" << (t+1) << ": ";

        string B = solve(A);

        cout << A << " " << B << endl;
    }

    return 0;
}
