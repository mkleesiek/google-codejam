/**
 * @file superset.cpp
 *
 * @date 22.10.2016
 * @author marco@kleesiek.com
 */

#include <iostream>
#include <vector>
#include <typeinfo>
#include <cstdint>

using namespace std;

template<class RandomAccessIteratorT>
int printPowerset(RandomAccessIteratorT first, RandomAccessIteratorT last)
{
    int inputLength = distance(first, last);

    if (inputLength == -1)
        return -1;

    uint64_t setSize = 1ull << inputLength;

    cout << "Superset size: " << setSize << endl;

    for (uint64_t setIndex = 0; setIndex < setSize; setIndex++) {
        cout << "[";
        int printedItems = 0;
        for (int listIndex = inputLength-1; listIndex >= 0; listIndex--) {
             if (setIndex & (1 << listIndex)) {
                if (printedItems++ > 0)
                    cout << " ,";
                cout << " " << *next(first, listIndex);
            }
        }
        cout << " ]" << endl;
    }
    return setSize;
}

int main( int argc, char* argv[] )
{
    cout << "Enter N: ";
    int N; cin >> N;

    vector<int> myList(N, 0);
    for (size_t i = 0; i < N; ++i)
        myList[i] = i+1;

    printPowerset(myList.begin(), myList.end());

    return 0;
}
