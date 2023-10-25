#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <numeric>

namespace hu {
    int GetNumOfDigits(int number);

    int GetNthDigit(int number, int n);

    bool PalindromeCheck(int number);

    std::vector<long long> genNPrimes(long long n);

    std::vector<long long> genPrimesBelowN(long long n);

    std::vector<long long> divisorsOf(long long n);

    std::vector<std::pair<long long, int>> primeFactorsOf(long long n);
}
