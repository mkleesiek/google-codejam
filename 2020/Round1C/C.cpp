#include <iostream>
#include <string>
#include <map>

using namespace std;

uint16_t solve(const map<uint64_t, uint16_t>& slices, uint16_t D)
{

	uint16_t d_max = 0;
	for (const auto& kvpair : slices) {
		if (kvpair.second > d_max)
			d_max = kvpair.second;
	}

	if (d_max >= D)
		return 0;

	for (; d_max > 0; d_max--) {
		map<uint64_t, uint16_t> cslices;
		for (const auto& kvpair : slices) {
			cslices[kvpair.first * 3] = kvpair.second;
		}

		for (auto it = cslices.rbegin(); it != cslices.rend(); it++) {
			// TODO
		}

	}

	return 0;
}

int main()
{
    size_t T;
    cin >> T;

    for (size_t t = 0; t < T; t++)
    {
    	uint16_t N, D;
    	cin >> N >> D;

		map<uint64_t, uint16_t> slices;

		for (size_t i = 0; i < N; i++) {
			uint64_t A;
			cin >> A;
			slices[A]++;
		}

		uint16_t solution = solve(slices, D);

        cout << "Case #" << (t+1) << ": " << solution << endl;
    }

    return 0;
}
