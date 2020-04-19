#include <iostream>
#include <string>

using namespace std;

uint8_t msb(int64_t a)
{
	a = abs(a);

	uint8_t r = 0;
	while (a >>= 1) {
		r++;
	}

	return r;
}

void solve(int64_t x, int64_t y, string& path, uint8_t last_msb = 255)
{
	if (x == 0 && y == 0) {
		if (last_msb > 0) {
			path = "IMPOSSIBLE";
		}
		return;
	}

	if (abs(x) == abs(y)) {
		path = "IMPOSSIBLE";
		return;
	}

	const uint8_t r = msb(abs(x)+abs(y));
	if (last_msb < 255 && last_msb != r + 1)
	{
		path = "IMPOSSIBLE";
		return;
	}

	if (abs(x) > abs(y))
	{
		if (x > 0) {
			path.insert(0, 1, 'E');
			x -= (1 << r);
		}
		else {
			path.insert(0, 1, 'W');
			x += (1 << r);
		}
	}
	else {
		if (y > 0) {
			path.insert(0, 1, 'N');
			y -= (1 << r);
		}
		else {
			path.insert(0, 1, 'S');
			y += (1 << r);
		}
	}

	solve(x, y, path, r);
}

int main()
{
    size_t T;
    cin >> T;

    for (size_t t = 0; t < T; t++)
    {
		int64_t a, b;
		cin >> a >> b;

		string path{};
		solve(a, b, path);

        cout << "Case #" << (t+1) << ": " << path << endl;
    }

    return 0;
}
