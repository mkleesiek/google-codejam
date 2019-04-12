
template <typename T>
bool isPrime(T number)
{
    if (((!(number % 2 == 1)) && number != 2) || (number < 2) || (number % 3 == 0 && number != 3))
        return (false);

    for (T k = 1; 36 * k * k - 12 * k < number; ++k)
        if ((number % (6 * k + 1) == 0) || (number % (6 * k - 1) == 0))
            return (false);

    return true;
}
