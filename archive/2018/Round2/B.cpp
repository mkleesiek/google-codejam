#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int solve(int R, int B)
{
    int N = 0;

    const int C = R+B;

    for (int c = 1; c <= C; ++c)
    {
        for (int r = c/2+1; r <= c; ++r) {
            int b = c - r;
            if (r > R || b > B)
                continue;

            R -= r;
            B -= b;
            N++;
        }

        for (int r = c/2; r >= 0; --r) {
            int b = c - r;
            if (r > R || b > B)
                continue;

            R -= r;
            B -= b;
            N++;
        }


        if (R+B < c)
            break;
    }

    return N;
}

int main(int argc, char* argv[])
{
    ifstream in;
    if(argc == 3)
    {
        const string inFile = argv[2];
        in =  ifstream(inFile);
        cin.rdbuf(in.rdbuf());
    }

//int main()
//{
    int T = 0;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        int R, B;
        cin >> R >> B;

        cout << "Case #" << (t+1) << ": " << solve(R, B) << endl;
    }

    return 0;
}
