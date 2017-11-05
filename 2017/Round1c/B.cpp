/**
 * @file B.cpp
 *
 * @date 30.04.2017
 * @author NoSheep (marco@kleesiek.com)
 */

#include <iostream>
#include <iomanip>
#include <set>
#include <list>
#include <algorithm>

using namespace std;

int loopTime(int diff) { return (diff + 1440) % 1440; }

struct Interval
{
    enum Type {
        Cameron,
        Jamie
    };

    Type fType;

    int fStart = 0;
    int fEnd = 0;

    int Duration() const { return loopTime(fEnd - fStart); }
};

bool operator< (const Interval& i1, const Interval& i2)
{
    if (i1.fStart == i2.fStart)
        return i1.fEnd < i2.fEnd;
    else
        return i1.fStart < i2.fStart;
}

int main()
{
    int T = 0;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int Ac, Aj;
        cin >> Ac >> Aj;

        set<Interval> activities;
        array<int, 2> parentingTimes = { 0, 0 };

        for (int i = 0; i < Ac; ++i) {
            int Ci, Di;
            cin >> Ci >> Di;
            activities.insert( {Interval::Cameron, Ci, Di} );
            parentingTimes[Interval::Cameron] += loopTime(Di - Ci);
        }

        for (int i = 0; i < Aj; ++i) {
            int Ji, Ki;
            cin >> Ji >> Ki;
            activities.insert( {Interval::Jamie, Ji, Ki} );
            parentingTimes[Interval::Jamie] += loopTime(Ki - Ji);
        }

        int n = 0;

        list<Interval> sameIntervals;

        for (auto it = activities.begin(); it != activities.end(); ++it)
        {
            auto prevIt = (it == activities.begin()) ? prev(activities.end()) : prev(it);

//            if (prevIt == it) {
//                n = 2;
//                break;
//            }

            if ( loopTime(it->fStart - prevIt->fEnd) > 0 && it->fType == prevIt->fType) {
                sameIntervals.push_back( {it->fType , prevIt->fEnd, it->fStart} );
            }

            else if (prevIt->fType != it->fType) {
                ++n;
            }
        }

        sameIntervals.sort( [] (const Interval& lhs, const Interval& rhs) {
            return lhs.Duration() < rhs.Duration();
        });

        for (auto sInterval : sameIntervals) {
            parentingTimes[sInterval.fType] += sInterval.Duration();
            if (parentingTimes[sInterval.fType] > 720)
                n += 2;
//            cerr << sInterval.fStart << " - " << sInterval.fEnd << ": " << sInterval.fType << endl;
        }

        cout << "Case #" << t << ": " << n << endl;
    }

    return 0;
}
