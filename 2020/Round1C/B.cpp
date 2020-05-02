#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void parse(const string& M, const string& R, string& D)
{
	if (M == "-1" || R.size() != M.size())
		return;

	if (D.empty())
		D = " ";

	const char q = M.front();
	uint8_t d = q - '0';

	if (d == D.size()) {
		const char r = R.front();

		if (D.find(r) == string::npos)
			D.push_back(r);
	}
}

template<class T>
void find_zero(const T& input, string& D)
{
	for (const auto& l : input) {
		if (D.find(l) == string::npos) {
			D[0] = l;
			return;
		}
	}
}

int main()
{
    size_t T;
    cin >> T;

    for (size_t t = 0; t < T; t++)
    {
    	uint8_t U;
    	cin >> U;

		string D;

		unordered_map<char, size_t> leading_char_count;
		unordered_set<char> non_leading_chars;

		for (uint16_t i = 0; i < 10000; i++)
		{
			string Q, R;
			cin >> Q >> R;

			leading_char_count[R.front()]++;
			if (R.size() > 1)
				non_leading_chars.insert(++R.begin(), R.end());

			parse(Q, R, D);
		}

		find_zero(non_leading_chars, D);

		multimap<size_t, char> D_s;
		for (const auto& kv : leading_char_count) {
			D_s.emplace(kv.second, kv.first);
		}

		if (D.size() == 9) {
			char c = D_s.rbegin()->second;
			if (D.find(c) == string::npos)
				D.push_back(c);
		}

		if (D.size() < 10) {
			D = " ";
			for (auto it = D_s.rbegin(); it!=D_s.rend(); it++) {
				D.push_back(it->second);
			}
			find_zero(non_leading_chars, D);
		}

        cout << "Case #" << (t+1) << ": " << D << endl;
    }

    return 0;
}
