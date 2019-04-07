#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    ifstream in;
    if (argc == 2)
    {
        const string inFile = argv[1];
        in =  ifstream(inFile);
        cin.rdbuf(in.rdbuf());
    }

    int T = 0;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        cout << "Case #" << (t+1) << ":" << endl;

    }

    return 0;
}
