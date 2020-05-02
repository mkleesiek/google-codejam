#include <iostream>
#include <string>

using namespace std;

int16_t solve (int16_t X, int16_t Y, const string& M)
{
	for (uint16_t t = 0; t <= M.size(); t++) {
		if (abs(X) + abs (Y) <= t) {
			return t;
		}
		else if (t == M.size()) {
			break;
		}

		switch (M[t]) {
		case 'N' :
			Y++; break;
		case 'E':
			X++; break;
		case 'S':
			Y--; break;
		case 'W':
			X--; break;
		default:
			break;
		}
	}

	return -1;
}

int main()
{
    size_t T;
    cin >> T;

    for (size_t t = 0; t < T; t++)
    {
    	int16_t X, Y;
    	cin >> X >> Y;

    	string M;
		cin >> M;

		const int16_t solution = solve(X, Y, M);

        cout << "Case #" << (t+1) << ": ";
        if (solution < 0)
		{
        	cout << "IMPOSSIBLE";
		}
		else
		{
			cout << solution;
		}
		cout << endl;
    }

    return 0;
}
