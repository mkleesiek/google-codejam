#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

//#include <fstream>
//int main(int argc, char* argv[])
//{
//    ifstream in;
//    if(argc == 3)
//    {
//        const string inFile = argv[2];
//        in =  ifstream(inFile);
//        cin.rdbuf(in.rdbuf());
//    }

int main()
{
    constexpr double L = 1.0;

    double alpha = 0.0;
    double beta = 0.0;

    int T = 0;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        double A;
        cin >> A;

        double B = 0.0;
        if (A > 1.414213)
        {
            B = A;
            A = 1.414213;
        }

        alpha = asin(A/sqrt(2.0)) - M_PI_4;
        beta = (B > 0.0) ? asin(B/A/sqrt(2.0)) - M_PI_4 : 0.0;

        cout << "Case #" << (t+1) << ":" << endl;
        cout << setprecision(12);

        cout << cos(alpha) * L/2.0 << ' ' << sin(alpha) * L/2.0 * cos(beta) << ' ' << sin(beta) * L/2.0 << endl;
        cout << -sin(alpha) * L/2.0 << ' ' << cos(alpha) * L/2.0 << ' ' << 0.0 << endl;
        cout << 0.0 << ' ' << -sin(beta) * L/2.0 << ' ' << cos(beta) * L/2.0 << endl;

        cout << endl;
    }

    return 0;
}
