#include <iostream>
#include <fstream>
#include <string>

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
        int N;
        cin >> N;

        cout << "Case #" << (t+1) << ": ";

        char c;
        cin.get(c);

        while (cin.get(c))
        {
            if (c == '\n')
                break;
            
            cout << (c == 'E' ? 'S' : 'E');
        }

        cout << endl;
    }

    return 0;
}
