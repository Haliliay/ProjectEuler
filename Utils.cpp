#include "Utils.h"

namespace hu {
    int GetNumOfDigits(int number) {
        std::string num_string = std::to_string(number);
        return num_string.size();
    }

    int GetNthDigit(int number, int n) {
        return (int)((number / pow(10, n - 1))) % 10;
    }

    bool PalindromeCheck(int number) {
        /* My cute palindrome check
        int digits = GetNumOfDigits(number);
        for (int i = 1; i <= digits / 2; i++) {
            if (GetNthDigit(number, i) != GetNthDigit(number, digits + 1 - i)) {
                return false;
            }
        }
        return true;
        */
        std::string num_string = std::to_string(number);
        std::string rev = num_string;
        std::reverse(rev.begin(), rev.end());
        return (num_string == rev);
    }

    std::vector<long long> genNPrimes(long long n)
    {
        std::vector<long long> primes = { 2, 3 };
        primes.reserve(sizeof(long long) * n);

        while (primes.size() < n) {
            long long p_test = primes.back();
            // While not prime
            while (
                [&]() {
                    for (auto& p : primes) {
                        if (p_test % p == 0)
                            return true;    // is not prime
                    }
                    return false;   // is prime
                }()) {
                p_test += 2;
            }
            primes.push_back(p_test);/*
            if (primes.size() % 1000 == 0)
            {
                std::cout << "\rProgress: " << primes.size() << "/" << n;
                std::cout.flush();
            }*/
        }
        return primes;
    }

    std::vector<long long> genPrimesBelowN(long long n)
    {
        using namespace std;
        auto oldMethod = [=]() {
            if (n < 3)
                return vector<long long>{};
            if (n == 3)
                return vector<long long>{2};
            std::vector<long long> primes = { 2, 3 };

            long long p_test = primes.back();
            while (p_test < n) {
                p_test = primes.back();
                // While not prime
                while (
                    [&]() {
                        for (auto& p : primes) {
                            if (p_test % p == 0)
                                return true;    // is not prime
                        }
                        return false;   // is prime
                    }()) {
                    p_test += 2;
                    if (p_test >= n)
                        break;
                }
                if (p_test >= n)
                    break;
                primes.push_back(p_test);

                //if (primes.size() % 100 == 0)
                //{
                //    std::cout << "\rLast Prime: " << primes.back() << "/" << n;
                //    std::cout.flush();
                //}

            }
            return primes;
        };
        
        auto sieveMethod = [=]() {
            // Leave out 1 and n, so -2
            vector<long long> sieve(n-2);
            vector<bool> marks(n-2, true);
            long long primesSize = n - 2;
            std::iota(sieve.begin(), sieve.end(), 2);

            long long p = 2;
            long long i = 0;
            while (i < (n-2)) {
                if (marks[i])
                {
                    p = sieve[i];
                    // Mark multiples of p as non prime
                    long long j = 2;
                    while ((j * p - 2) < (n-2)) {
                        if(marks[(j * p - 2)])
                        {
                            marks[(j * p - 2)] = false;
                            primesSize--;
                        }
                        j++;
                    }
                }
                i++;
            }

            vector<long long> primes(primesSize);
            for (size_t i = 0, j = 0; i < primesSize; i++) {
                while (!marks[j] && j < n-2)
                    j++;
                primes[i] = sieve[j];
                j++;
            }

            return primes;
        };
        
        return sieveMethod();
    }

    std::vector<long long> divisorsOf(long long n)
    {
        using namespace std;
        vector<long long> divisors{1};
        if (n == 1)
            return divisors;
        else
            divisors.push_back(n);

        // Sieve method
        vector<long long> sieve(n - 1);
        vector<bool> marks(n - 1, true);
        std::iota(sieve.begin(), sieve.end(), 2);

        long long c_d = 2;
        long long i = 0;
        // divisor m of divisor pair (m, k) is always <= sqrt(n)
        while (sieve[i] * sieve[i] <= n) {
            if (marks[i])
            {
                // Marked as divisor, so check if it is true
                c_d = sieve[i];
                if (n % c_d != 0) {
                    // Mark c_d and multiples of c_d as non divisors
                    long long j = 1;
                    while ((j * c_d - 2) < (n - 1)) {
                        if (marks[(j * c_d - 2)])
                        {
                            marks[(j * c_d - 2)] = false;
                        }
                        j++;
                    }
                }
                else {
                    divisors.push_back(c_d);
                    long long divisorPartner = n / c_d;
                    if (divisorPartner != c_d)
                        divisors.push_back(divisorPartner);
                }
            }
            i++;
        }

        return divisors;
    }

    std::vector<std::pair<long long, int>> primeFactorsOf(long long n) {
        std::vector<std::pair<long long, int>> factors;
        auto primes = genPrimesBelowN(ceill(sqrtl(n)));
        for (long long i = 0; i < primes.size(); i++) {
            int count = 0;
            while ((n % primes[i]) == 0) {
                count++;
                n = n / primes[i];
            }
            if (count > 0) {
                factors.push_back(std::make_pair(primes[i], count));
            }
        }
        if (n > 1) {
            factors.push_back(std::make_pair(n, 1));
        }
        return factors;
    }
}
