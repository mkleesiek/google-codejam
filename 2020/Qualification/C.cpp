#include <iostream>
#include <string>
#include <list>
#include <set>

using namespace std;

struct Activity
{
	size_t index;
	uint16_t start;
	uint16_t end;
};

bool operator<(const Activity& a1, const Activity& a2)
{
	if (a1.start == a2.start) {
		if (a1.end == a2.end) {
			return a1.index < a2.index;
		} else {
			return a1.end < a2.end;
		}
	} else {
		return a1.start < a2.start;
	}
}

string solve(const set<Activity>& activities)
{
    string result(activities.size(), '0');

    const Activity* c = nullptr;
    const Activity* j = nullptr;

    for (const Activity& a : activities)
	{
    	if (c != nullptr && c->end <= a.start)
    		c = nullptr;
    	if (j != nullptr && j->end <= a.start)
    		j = nullptr;

    	if (c == nullptr) {
    		c = &a;
    		result[a.index] = 'C';
    	}
    	else if (j == nullptr) {
    		j = &a;
    		result[a.index] = 'J';
    	}
    	else {
    		return "IMPOSSIBLE";
    	}
	}

    return result;
}

int main()
{
    size_t T = 0;
    cin >> T;

    for (size_t t = 0; t < T; t++)
    {
        size_t N;
        cin >> N;

        set<Activity> activities;

        for (size_t i = 0; i < N; i++)
		{
        	Activity a{i, 0, 0};
        	cin >> a.start >> a.end;
        	activities.insert(move(a));
		}

        string result = solve(activities);

        cout << "Case #" << (t+1) << ": " << result << endl;
    }

    return 0;
}
