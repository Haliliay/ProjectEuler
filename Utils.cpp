#include "Utils.h"

namespace hu {
    namespace prime {
        std::vector<long long> sievePrimesBelowN(long long n)
        {
            using namespace std;

            // Let index align with number
            int sieveSize = n;

            // Only calculate more primes if needed
            if (sieve.size() < sieveSize && sieveSize > 0) {
                // Extend sieves
                int offset = sieve.size();
                sieve.resize(sieveSize, 0);
                std::iota(sieve.begin() + offset, sieve.end(), offset);
                marks.resize(sieveSize, true);

                // Search for non-memoized primes below n
                long long p = 2;
                long long i = 0;    // Always start by 2 to sieve already found primes out of the added space
                while (i < sieveSize) {
                    if (i < 2) {
                        // Special case for 0 and 1
                        marks[i] = false;
                    }
                    else if (marks[i]) {
                        p = sieve[i];
                        // Add prime if it is new
                        if (i >= offset)
                            primes.push_back(p);

                        long long multiplier = 2;
                        // Skip already sieved multiples
                        if (offset >= p)
                            multiplier += offset / p - 2;

                        // Mark multiples of p as non prime
                        while ((multiplier * p) < sieveSize) {
                            if (marks[(multiplier * p)])
                            {
                                marks[(multiplier * p)] = false;
                            }
                            multiplier++;
                        }
                    }
                    i++;
                }
            }

            return primes;
        }

        std::vector<long long> genNPrimes(long long n)
        {
            long long threshold = 2*n;
            while (primes.size() < n) {
                threshold += 2*n;
                sievePrimesBelowN(threshold);
            }

            // Return primes
            std::vector<long long> subsetPrimes(n);
            for (int i = 0; i < n; i++) {
                subsetPrimes.push_back(primes[i]);
            }
            return subsetPrimes;
        }

        std::vector<long long> genPrimesBelowN(long long n)
        {
            sievePrimesBelowN(n);

            // Return primes
            std::vector<long long> subsetPrimes = {};
            for (int i = 0; i < primes.size() && primes[i] < n; i++) {
                subsetPrimes.push_back(primes[i]);
            }
            return subsetPrimes;
        }

        bool isPrime(long long p)
        {
            if (p < 0)
                return false;
            else if (p >= marks.size())
                genPrimesBelowN(p + 1);
            return marks[p];
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
            vector<long long> divisors = { 1 };
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

            if (divisors.size() > 0)
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
    }

    namespace io {
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

        std::vector<int> readIntsFromFile(const std::string& filename, char delim)
        {
            using namespace std;
            vector<int> result;
            string line;
            ifstream file(filename);
            while (getline(file, line)) {
                vector<string> numbers = split(line, delim);
                for (auto& s : numbers) {
                    result.push_back(stoi(s));
                }
            }
            file.close();
            return result;
        }

        void writeIntsToFile(const std::vector<int>& list, const std::string& filename, char delim)
        {
            using namespace std;
            char delimArr[2] = { delim, '\0' };
            ofstream file(filename);
            ostream_iterator<int> output_iterator(file, delimArr);
            copy(begin(list), end(list), output_iterator);
            file.close();
        }
    }

    namespace stri {
        bool isPalindrome(std::string s) {
            std::string rev = s;
            std::reverse(rev.begin(), rev.end());
            return (s == rev);
        }

        bool isPalindrome(long long number) {
            /* My cute palindrome check
            long long digits = GetNumOfDigits(number);
            for (long long i = 1; i <= digits / 2; i++) {
                if (GetNthDigit(number, i) != GetNthDigit(number, digits + 1 - i)) {
                    return false;
                }
            }
            return true;
            */
            return isPalindrome(std::to_string(number));
        }

        bool isAnagram(std::string a, std::string b)
        {
            using namespace std;
            if (a.size() == b.size()) {
                sort(a.begin(), a.end());
                sort(b.begin(), b.end());
                return a == b;
            }
            return false;
        }

        template<typename T>
        std::string listToString(const std::vector<T>& list)
        {
            using namespace std;
            string result = "";
            for (auto& i : list) {
                result += to_string(i);
            }
            return result;
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
    }

    namespace numerics {
        std::vector<int> permSelect(const std::vector<int>& list, int selectedIndex)
        {
            using namespace std;
            int N = list.size();
            string permutation = listToString(list);
            int counter = 0;
            vector<int> result = {};

            // Evaluate permutation
            do {
                counter++;
                hu::printProgress(counter, selectedIndex);
            } while (counter != selectedIndex && std::next_permutation(permutation.begin(), permutation.end()));

            for (int i = 0; i < N; ++i)
            {
                result.push_back(ctoi(permutation[i]));
            }
            return result;
        }

        std::string permSelect(const std::string& list, int selectedIndex)
        {
            using namespace std;
            string permutation = list;
            int counter = 0;

            // Evaluate permutation
            do {
                counter++;
                hu::printProgress(counter, selectedIndex);
            } while (counter != selectedIndex && std::next_permutation(permutation.begin(), permutation.end()));

            return permutation;
        }
        
        /// <summary>
        /// Returns all combinations of the elements of list.
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="list"></param>
        /// <param name="K">Amount of selected elements in the combination</param>
        /// <returns></returns>
        template<typename T>
        std::set<std::vector<T>> comb(const std::vector<T>& list, int K)
        {
            using namespace std;
            int N = list.size();
            K = clamp(K, 1, N);
            std::set<std::vector<T>> result;
            string bitmask(K, 1); // K leading 1's
            bitmask.resize(N, 0); // N-K trailing 0's

            // Add combination and permute bitmask
            do {
                vector<T> combination = {};
                for (int i = 0; i < N; ++i) // [0..N-1] integers
                {
                    if (bitmask[i]) combination.push_back(list[i]);
                }
                result.emplace(combination);
            } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
            return result;
        }
    }


    long long GetNumOfDigits(long long number) {
        std::string num_string = std::to_string(number);
        return num_string.size();
    }

    long long GetNthDigit(long long number, long long n) {
        return (long long)((number / pow(10, n - 1))) % 10;
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
}
