#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <numeric>

namespace hu {
    long long GetNumOfDigits(long long number);

    long long GetNthDigit(long long number, long long n);

    bool PalindromeCheck(long long number);

    std::vector<long long> genNPrimes(long long n);

    std::vector<long long> genPrimesBelowN(long long n);

    std::vector<long long> divisorsOf(long long n);

    std::vector<std::pair<long long, long long>> primeFactorsOf(long long n);
}
