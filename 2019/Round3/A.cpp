#include <iostream>
#include <map>
#include <random>
#include <algorithm>

using namespace std;

static auto gen = mt19937_64(random_device()());

class Zillionim
{
public:
    Zillionim(uint64_t total = 1'000'000'000'000, uint64_t per_move = 10'000'000'000) :
            m_coins_total(total),
            m_coins_per_move(per_move)
    {
        m_playable_intervals.emplace(1, m_coins_total - m_coins_per_move + 1);
    }

    bool Turn(uint64_t index)
    {
        if (m_playable_intervals.empty())
            return false;

        auto it = m_playable_intervals.upper_bound(index);
        it--;

        if (it == m_playable_intervals.end() || index < it->first || index > it->second)
            return false;

        auto ci = *it;

        m_playable_intervals.erase(it);

        if (ci.first + m_coins_per_move - 1 < index)
            m_playable_intervals.emplace(ci.first, index - m_coins_per_move);

        if (index + m_coins_per_move - 1 < ci.second)
            m_playable_intervals.emplace(index + m_coins_per_move, ci.second);

        m_cnt_turns++;

        return true;
    }

    uint64_t ChooseNext() const
    {
        if (!IsPlayable())
            return 0;

        if (MovesLeft() % 2 == 0)
        {
            auto it = FindLargestInterval();
            return min(it->first + m_coins_per_move - 1, it->second);
        }
        else
        {
            // uniform_int_distribution<uint64_t> randomIndex(it->first, it->second - m_coins_per_move + 1);
            // return randomIndex(gen);
            auto it = FindSmallestInterval();
            return it->first;
        }
    }

    bool IsPlayable() const
    {
        return !m_playable_intervals.empty();
    }

    uint64_t MovesLeft() const
    {
        uint64_t result = 0;
        for (const auto& ci : m_playable_intervals)
            result += (ci.second - ci.first) / m_coins_per_move + 1;
        return result;
    }

    bool CheckCoin(uint64_t index) const
    {
        if (m_playable_intervals.empty())
            return false;

        auto it = m_playable_intervals.upper_bound(index);
        it--;

        return !(it == m_playable_intervals.end() || index < it->first || index > it->second + m_coins_per_move - 1);
    }

private:
    map<uint64_t, uint64_t>::const_iterator FindSmallestInterval() const
    {
        auto result = m_playable_intervals.end();
        uint64_t minRange = 0;

        for (auto it = m_playable_intervals.begin(); it != m_playable_intervals.end(); it++)
        {
            uint64_t range = it->second - it->first + 1;
            if (result == m_playable_intervals.end() || range < minRange)
            {
                minRange = range;
                result = it;
            }
        }

        return result;
    }

    map<uint64_t, uint64_t>::const_iterator FindLargestInterval() const
    {
        auto result = m_playable_intervals.end();
        uint64_t maxRange = 0;

        for (auto it = m_playable_intervals.begin(); it != m_playable_intervals.end(); it++)
        {
            uint64_t range = it->second - it->first + 1;
            if (result == m_playable_intervals.end() || range > maxRange)
            {
                maxRange = range;
                result = it;
            }
        }

        return result;
    }

private:
    uint64_t m_coins_total;
    uint64_t m_coins_per_move;

    map<uint64_t, uint64_t> m_playable_intervals;
    uint64_t m_cnt_turns = 0;
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

            if (!z.Turn((uint64_t) P))
                return -1;
            
            const uint64_t M = z.ChooseNext();
            if (M > 0)
            {
                cout << M << endl;
                cout.flush();
                z.Turn(M);
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
