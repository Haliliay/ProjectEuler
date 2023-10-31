#include "Utils.h"

namespace hu {
    long long GetNumOfDigits(long long number) {
        std::string num_string = std::to_string(number);
        return num_string.size();
    }

    long long GetNthDigit(long long number, long long n) {
        return (long long)((number / pow(10, n - 1))) % 10;
    }

    bool PalindromeCheck(long long number) {
        /* My cute palindrome check
        long long digits = GetNumOfDigits(number);
        for (long long i = 1; i <= digits / 2; i++) {
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

        // Memoize state
        static vector<long long> sieve = {};
        static vector<bool> marks = {};
        static vector<long long> primes = {};

        // Leave out 1 and n, so the sieve size is n-2
        int sieveSize = n - 2;

        if (sieve.size() < sieveSize && sieveSize > 0) {
            // Extend sieves
            int offset = sieve.size();
            sieve.resize(sieveSize, 0);
            std::iota(sieve.begin() + offset, sieve.end(), 2 + offset);
            marks.resize(sieveSize, true);

            // Search for non-memoized primes below n
            long long p = 2;
            long long i = 0;    // Always start by 0 to sieve already found primes out of the added space
            while (i < sieveSize) {
                if (marks[i])
                {
                    p = sieve[i];
                    long long multiplier = 2;
                    // Skip already sieved multiples
                    if (offset >= p)
                        multiplier += offset / p;

                    // Mark multiples of p as non prime
                    while ((multiplier * p - 2) < sieveSize) {
                        if (marks[(multiplier * p - 2)])
                        {
                            marks[(multiplier * p - 2)] = false;
                        }
                        multiplier++;
                    }
                }
                i++;
            }
        }

        // Return primes
        vector<long long> subsetPrimes = {};
        for (int j = 0; j < sieveSize; j++) {
            // Skip non-primes
            while (j < sieveSize && !marks[j])
                j++;

            if (j == sieveSize)
                break;

            long long prime = sieve[j];
            if (prime >= n)
                break;

            subsetPrimes.push_back(prime);
        }
        return subsetPrimes;
    }

    std::vector<long long> divisorsOf(long long n)
    {
        auto d = divisorsProperOf(n);
        d.push_back(n);
        return d;
    }

    std::vector<long long> divisorsProperOf(long long n)
    {
        using namespace std;
        vector<long long> divisors = {1};
        vector<long long> primeFactorList = {};
        auto primeFactors = primeFactorsOf(n);
        for (auto& pF : primeFactors) {
            for (long long i = 0; i < pF.second; i++) {
                primeFactorList.push_back(pF.first);
            }
        }
        for (int i = 1; i <= primeFactorList.size(); i++) {
            auto combinations = comb(primeFactorList, i);
            for (auto& c : combinations) {
                long long divisor = 1;
                for (int j = 0; j < i; j++) {
                    divisor *= c[j];
                }
                divisors.push_back(divisor);
            }
        }
        
        if(divisors.size() > 0)
            divisors.resize(divisors.size() - 1);
        return divisors;
    }

    std::vector<std::pair<long long, long long>> primeFactorsOf(long long n) {
        std::vector<std::pair<long long, long long>> factors;
        auto primes = genPrimesBelowN(ceill(sqrtl(n)));
        for (long long i = 0; i < primes.size(); i++) {
            long long count = 0;
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

    template <typename Out>
    void split(const std::string& s, char delim, Out result) {
        std::istringstream iss(s);
        std::string item;
        while (std::getline(iss, item, delim)) {
            *result++ = item;
        }
    }


    std::vector<std::string> split(const std::string& s, char delim) {
        std::vector<std::string> elems;
        split(s, delim, std::back_inserter(elems));
        return elems;
    }

    std::vector<std::vector<int>> readIntsInto2dArray(const std::string& filename, char delim)
    {
        using namespace std;
        vector<vector<int>> array{ {} };
        // Read the 50 digit numbers as strings
        ifstream file;
        string line;
        file.open(filename);
        if (file.is_open()) {
            int i = 0;
            while (getline(file, line)) {
                if (i > 0) {
                    array.push_back(vector<int>());
                }
                vector<string> numbers = split(line, delim);
                for (auto& s : numbers) {
                    array[i].push_back(stoi(s));
                }
                i++;
            }
            file.close();
        }
        return array;
    }

    bool isLeapYear(long long year)
    {
        bool isBy400 = (year % 400) == 0;
        bool isBy100 = (year % 100) == 0;
        bool isBy4 = (year % 4) == 0;
        return isBy4 && (isBy400 || !isBy100);
    }

    int ctoi(const char c)
    {
        assert(c >= '0' && c <= '9');
        return c - '0';
    }

    void printProgress(long long a, long long n)
    {
        static long double percentage = 0;
        long double newPercentage = ((long double)a * 100.) / n;
        if ((newPercentage - percentage) >= 1) {
            percentage = newPercentage;
            std::cout << "\rProgress: " << a << "/" << n << "  (" << percentage << "%)\t\t";
            std::cout.flush();
        }
    }

    std::set<std::vector<long long>> comb(const std::vector<long long>& list, int K)
    {
        using namespace std;
        int N = list.size();
        assert(N >= K);
        std::set<std::vector<long long>> result;
        string bitmask(K, 1); // K leading 1's
        bitmask.resize(N, 0); // N-K trailing 0's

        // print integers and permute bitmask
        do {
            vector<long long> combination = {};
            for (int i = 0; i < N; ++i) // [0..N-1] integers
            {
                if (bitmask[i]) combination.push_back(list[i]);
            }
            result.emplace(combination);
        } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
        return result;
    }
}
