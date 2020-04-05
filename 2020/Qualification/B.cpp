#include <iostream>
#include <string>

using namespace std;

string solve(const string& input)
{
    string result;

    int8_t depth = 0;

    for (auto c : input) {
    	int8_t diff = static_cast<int8_t>(c - '0') - depth;

    	if (diff > 0)
			result.append(diff, '(');
		else if (diff < 0)
			result.append(-diff, ')');

		result.push_back(c);
		depth += diff;
    }

    result.append(depth, ')');

    return result;
}

int main()
{
    size_t T;
    cin >> T;

    for (size_t t = 0; t < T; t++)
    {
        string input;
        cin >> input;

        cout << "Case #" << (t+1) << ": " << solve(input) << endl;
    }

    return 0;
}
