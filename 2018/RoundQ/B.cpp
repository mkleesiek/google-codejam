#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

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
    int T = 0;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        int N;
        cin >> N;
        vector<int> V(N);
        unordered_map<int, int> even, odd;

        for (int i = 0; i < N; ++i) {
            cin >> V[i];
            if (i % 2 == 0)
                even[V[i]]++;
            else
                odd[V[i]]++;
        }

        sort(V.begin(), V.end());

        int broken_index = -1;

        for (int i = 0; i < N; ++i) {
            if (
                (i % 2 == 0 && even[V[i]]-- == 0) ||
                (i % 2 == 1 && odd[V[i]]-- == 0)
            )
            {
                broken_index = i;
                break;
            }
        }


        cout << "Case #" << (t+1) << ": ";

        if (broken_index > -1)
            cout << broken_index;
        else
            cout << "OK";

        cout << endl;
    }

    return 0;
}
