/**
 * @file sheep.cpp
 *
 * @date 17.10.2016
 * @author marco@kleesiek.com
 */

#include <iostream>
#include <array>
#include <algorithm>

#include <boost/math/special_functions/prime.hpp>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::math;
using namespace boost::multiprecision;

bool mrt (const uint128_t n, const uint128_t a = 21)
{ // n ungerade, 1 < a < n-1
   const uint128_t n1 = n - 1;
   uint128_t d = n1 >> 1;
   int j = 1;
   while ((d & 1) == 0) d >>= 1, ++j;
   uint128_t t = a, p = a;
   while (d >>= 1) { //square and multiply: a^d mod n
      p = p*p % n;
      if (d & 1) t = t*p % n;
   }
   if (t == 1 || t == n1) return true; // n ist wahrscheinlich prim
   for (int k=1 ; k<j ; ++k) {
      t = t*t % n;
      if (t == n1) return true;
      if (t <= 1) break;
   }
   return false; // n ist nicht prim
}

uint128_t divisor(uint128_t n)
{
    for (size_t i = 1; i < max_prime; i++) {
        const uint128_t p = prime(i);
        if (p*p > n)
            return 0;
        if (n % p == 0)
            return p;
    }
//    for (uint128_t i = prime(max_prime-1); i*i <= n; i+=2) {
//        if (n % i == 0)
//            return i;
//    }
    return 0;
}

void generateJamCoins(uint16_t N, uint16_t J)
{
    if (N < 2 || J < 0)
        return;

    const uint64_t minBin = (1ull << (N-1)) + 1;
    const uint64_t maxBin = (1ull << N) - 1;

    uint16_t j = 0;

    for (uint64_t bin = minBin; bin <= maxBin; bin += 2) {

        string binString;

        array<uint128_t, 9> rep;
        fill_n(rep.begin(), 9, 0);
        rep[0] = bin;

        for (int16_t n = N-1; n >= 0; n--) {
            const int set = ((bin >> n) & 1);

            binString += set ? '1' : '0';

            for (uint8_t base = 3; base <= 10; base++) {
                rep[base-2] *= base;
                if (set)
                    rep[base-2] += 1;
            }
        }

        bool isPrime = false;
        for (uint8_t base = 2; base <= 10; base++) {
            if ( mrt(rep[base-2], 21) || mrt(rep[base-2], 37) ) {
                isPrime = true;
                break;
            }
        }
        if (isPrime)
            continue;

        array<uint128_t, 9> divs;
        fill_n(divs.begin(), 9, 0);

        for (uint8_t base = 2; base <= 10; base++) {
            divs[base-2] = divisor(rep[base-2]);
        }

        if ( count_if(divs.begin(), divs.end(), [](uint128_t n){ return n == 0; }) == 0 ) {
            cout << binString;
            for (uint8_t base = 2; base <= 10; base++)
                cout << " " << divs[base-2];

            cout << endl;
            cout.flush();
            j++;
        }

        if (j >= J)
            break;
    }
}

int main()
{
    int T; cin >> T;

    for (int t = 1; t <= T; t++) {
        int N; cin >> N;
        int J; cin >> J;

        cout << "Case #" << t << ":" << endl;
        generateJamCoins(N, J);
    }

    return 0;
}



