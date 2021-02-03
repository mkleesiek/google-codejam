#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

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

        cout << "Case #" << (t+1) << ": " << endl;
    }

    return 0;
}
