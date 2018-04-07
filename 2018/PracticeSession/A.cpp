#include <iostream>
#include <vector>

using namespace std;

int guess_number(int A, int B) {
    return (B+A+1) / 2;
}

int main()
{
    int T = 0;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        int A, B, N;
        cin >> A >> B >> N;

        for (int n = 0; n < N; ++n) {
            int G = guess_number(A, B);
            cout << G << endl;
            cout.flush();

            string answer;
            cin >> answer;

            if (answer == "CORRECT") {
                break;
            } else if (answer == "TOO_BIG") {
                B = G - 1;
            } else if (answer == "TOO_SMALL") {
                A = G;
            } else {
                t = T;
                break;
            }

        }
    }

    return 0;
}
