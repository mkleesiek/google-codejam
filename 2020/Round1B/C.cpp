#include <iostream>
#include <string>
#include <list>
#include <utility>

using namespace std;

list<pair<uint32_t, uint32_t>> solve(uint32_t r, uint32_t s)
{
	list<pair<uint32_t, uint32_t>> solution;

	if (r == 1 || s == 1)
		return solution;

	for (uint32_t i = 0; i < s - 1; i++)
	{
		solution.push_back( { (r*s)-(r-1)-(i+1), (r-1) } );
	}

	if (solution.size() > 0) {
		solution.splice(solution.end(), solve(r-1, s));
	}

	return solution;
}

int main()
{
    size_t T;
    cin >> T;

    for (size_t t = 0; t < T; t++)
    {
    	uint32_t r, s;
    	cin >> r >> s;
		auto solution = solve(r,s);

        cout << "Case #" << (t+1) << ": " << solution.size() << endl;
        for (auto p : solution)
        	cout << p.first << " " << p.second << endl;
    }

    return 0;
}
