#include <iostream>
#include <map>
#include <random>
#include <algorithm>

using namespace std;

static mt19937 gen;

class Zillionim
{
public:
    Zillionim(uint64_t total = 1'000'000'000'000ull, uint64_t perMove = 10'000'000'000ull) :
        totalCoins(total),
        coinsPerMove(perMove)
    {
        playableIntervals.emplace(1, totalCoins);
    }

    bool turn(uint64_t index)
    {
        if (playableIntervals.empty())
            return false;

        auto it = playableIntervals.upper_bound(index);
        it--;

        if (it == playableIntervals.end() || index < it->first || index + coinsPerMove - 1 > it->second)
            return false;

        auto ci = *it;

        playableIntervals.erase(it);

        if (ci.first + coinsPerMove <= index)
            playableIntervals.emplace(ci.first, index - 1);

        if (index + coinsPerMove - 1 <= ci.second - coinsPerMove)
            playableIntervals.emplace(index + coinsPerMove, ci.second);

        executedTurns++;

        return true;        
    }

    uint64_t chooseNext() const
    {
        if (!IsPlayable())
            return 0;

        auto it = FindSmallestInterval();

        if (it->second - it->first + 1 <= 3*coinsPerMove - 2 || playableIntervals.size() > 1)
        {
            return min(it->first + coinsPerMove - 1, it->second - coinsPerMove + 1);
        }
        else
        {
            // uniform_int_distribution<uint64_t> randomIndex(it->first, it->second - coinsPerMove + 1);
            // return randomIndex(gen);
            return it->first;
        }
    }

    bool IsPlayable() const
    {
        return !playableIntervals.empty();
    }

    bool CheckCoin(uint64_t index) const
    {
        if (playableIntervals.empty())
            return false;

        auto it = playableIntervals.upper_bound(index);
        it--;

        return !(it == playableIntervals.end() || index < it->first || index > it->second);        
    }

private:
    map<uint64_t, uint64_t>::const_iterator FindSmallestInterval() const
    {
        auto result = playableIntervals.end();
        uint64_t minRange = 0;

        for (auto it = playableIntervals.begin(); it != playableIntervals.end(); it++)
        {
            uint64_t range = it->second - it->first + 1;
            if (result == playableIntervals.end() || range < minRange)
            {
                minRange = range;
                result = it;
            }
        }

        return result;
    }

private:
    uint64_t totalCoins;
    uint64_t coinsPerMove;

    map<uint64_t, uint64_t> playableIntervals;
    uint64_t executedTurns = 0;
};

int main()
{
    int T, W;
    cin >> T >> W;

    for (int t = 0; t < T; ++t)
    {
        int w = 0;
        Zillionim z;

        int64_t P;

        while (cin >> P)
        {
            if (P <= 0)
                break;

            if (!z.turn((uint64_t) P))
                return -1;
            
            const uint64_t M = z.chooseNext();
            if (M > 0)
            {
                cout << M << endl;
                cout.flush();
                z.turn(M);
            }
            else {
                return -1;
            }
        }

        if (P == -1)
            return -1;
        else if (P == -2)
            w++;
        
        if (w >= W)
           break;
    }

    return 0;
}
