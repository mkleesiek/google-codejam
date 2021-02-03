/**
 * @file pancake.cpp
 *
 * @date 18.10.2016
 * @author marco@kleesiek.com
 */

#include <iostream>

using namespace std;

int solve(const string& stack)
{
    int nFlips = 0;

    int i = stack.length()-1;

    while (i >= 0 && stack[i] == '+')
        i--;

    if (i < 0)
        return nFlips;

    if (stack[i] == '-') {
        nFlips++;
        i--;
    }

    for (; i >= 0; i--) {
        if (stack[i+1] != stack[i])
            nFlips++;
    }
    return nFlips;
}

int main()
{
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {

        string stack;
        cin >> stack;

        int result = solve(stack);

        cout << "Case #" << i << ": " << result << endl;
    }

    return 0;
}
