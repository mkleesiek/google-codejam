#include "testing.h"
#include "utilities.h"

#include "C.cpp"

#include <random>
#include <stdexcept>

using namespace std;

static mt19937 mt;

template<typename T>
vector<T> encrypt(const string& text)
{
    if (text.size() < 2)
        throw new invalid_argument("Input text is too short.");

    uniform_int_distribution<int> dist(1, 20);

    vector<T> primeNumbers(26, 0);

    T primeNumber = 1;
    for (size_t i = 0; i < 26; i++)
    {
        int J = dist(mt);
        for (int j = 0; j < J; j++)
        {
            do
            {
                primeNumber += 2;
            }
            while (!isPrime(primeNumber));
        }

        primeNumbers[i] = primeNumber;
    }

    vector<T> cipher(text.size()-1, 0);

    for (size_t i = 0; i < text.size()-1; i++)
    {
        size_t index1 = text[i] - 'A';
        size_t index2 = text[i+1] - 'A';

        if (index1 > 25 || index2 > 25)
            throw new invalid_argument("Input text contains invalid chars.");
        
        cipher[i] = primeNumbers[index1] * primeNumbers[index2];
    }

    return cipher;
}

string randomString(size_t length)
{
    string result(length, 0);
    
    const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    uniform_int_distribution<size_t> dist(0, alphabet.size()-1);

    for (size_t i = 0; i < length; i++)
        result[i] = alphabet[dist(mt)];

    return result;
}

TEST( GreatestCommonDivisor, Basic )
{
    ASSERT_EQ( __gcd(12, 8), 4 );
    ASSERT_EQ( __gcd(8, 12), 4 );
    ASSERT_EQ( __gcd(8, 8), 8 );
}

TEST( Decrypt, Basic )
{
    ASSERT_EQ(
        decrypt<int>({217, 1891, 4819, 2291, 2987, 3811, 1739, 2491, 4717, 445, 65, 1079, 8383, 5353, 901, 187, 649, 1003, 697, 3239, 7663, 291, 123, 779, 1007, 3551, 1943, 2117, 1679, 989, 3053}),
        "CJQUIZKNOWBEVYOFDPFLUXALGORITHMS"
    );
}

TEST( Decrypt, Hard )
{
    string input = "ABABC";
    auto cipher = encrypt<int>(input);
    ASSERT_EQ(decrypt(cipher), input);
}

TEST( Decrypt, Generated )
{
    for (int i = 0; i < 1000; i++)
    {
        uniform_int_distribution<size_t> dist(0, 75);
        string input = randomString(dist(mt));

        string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        while(!alphabet.empty())
        {
            uniform_int_distribution<size_t> dist(0, alphabet.size()-1);
            uniform_int_distribution<size_t> dist2(0, input.size());
            size_t ia = dist(mt);
            input.insert(dist2(mt), &alphabet[ia]);
            alphabet.erase(ia, 1);
        }

        auto cipher = encrypt<int>(input);
        ASSERT_EQ(decrypt(cipher), input);
    }
}

TEST( Main, Basic )
{
    string input = R"(
2
103 31
217 1891 4819 2291 2987 3811 1739 2491 4717 445 65 1079 8383 5353 901 187 649 1003 697 3239 7663 291 123 779 1007 3551 1943 2117 1679 989 3053
10000 25
3292937 175597 18779 50429 375469 1651121 2102 3722 2376497 611683 489059 2328901 3150061 829981 421301 76409 38477 291931 730241 959821 1664197 3057407 4267589 4729181 5335543
)";

    string expectation = R"(Case #1: CJQUIZKNOWBEVYOFDPFLUXALGORITHMS
Case #2: SUBDERMATOGLYPHICFJKNQVWXZ
)";

    ASSERT_MAIN_RETURNS(input, 0);
    ASSERT_OUTPUT_EQ(expectation);
}
