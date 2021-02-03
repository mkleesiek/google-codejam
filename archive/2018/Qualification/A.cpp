#include <iostream>
#include <string>
#include <utility>

using namespace std;

int get_total_damage(const string& P) {
    int laser_power = 1;
    int damage = 0;
    for (auto c : P) {
        if (c == 'S')
            damage += laser_power;
        else if (c == 'C')
            laser_power *= 2;
    }
    return damage;
}

int main()
{
    int T = 0;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        int D;
        string P;
        cin >> D >> P;

        cout << "Case #" << (t+1) << ": ";

        int damage = get_total_damage(P);
        bool hacks_possible = true;
        int n_hacks = 0;

        while (damage > D && hacks_possible)
        {
            hacks_possible = false;
            for (int i = P.length()-1; i > 0; --i)
            {
                if (P[i] == 'S' && P[i-1] == 'C')
                {
                    hacks_possible = true;
                    swap(P[i], P[i-1]);
                    n_hacks++;
                    damage = get_total_damage(P);
                    break;
                }
            }
        }

        if (damage <= D)
            cout << n_hacks;
        else
            cout << "IMPOSSIBLE";

        cout << endl;
    }

    return 0;
}
