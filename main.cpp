#include <iostream>
#include <algorithm>
#include <vector>
#include "Utils.h"

using namespace std;

class Problem0001 {
public:
    // SumOfMultiplesOf3Or5
    int operator()(int m) const {
        int sum = 0;
        for (int i = 1; i < m; i++) {
            if (i % 3 == 0 || i % 5 == 0)
                sum += i;
        }
        return sum;
    }

    int operator()() const {
        return this->operator()(1000);
    }
};

class Problem0002 {
public:
    // SumEvenValuedFibonacci
    int operator()(int m) const {
        int sum = 0;
        int fib1 = 1;
        int fib2 = 2;
        while (fib2 <= m) {
            if (fib2 % 2 == 0) {
                sum += fib2;
            }
            int help = fib1;
            fib1 = fib2;
            fib2 += help;
        }
        return sum;
    }

    int operator()() const {
        return this->operator()(4e6);
    }
};

class Problem0003 {
public:
    // BiggestPrimeFactorOf
    int operator()(long long m) const {
        long long biggest_factor = -1;
        long long prime = 2;
        if (m == 1)
            return biggest_factor;
        while (prime * prime <= m) {
            if (m % prime == 0) {
                biggest_factor = prime;
                m /= prime;
            }
            else {
                prime++;
            }
        }
        biggest_factor = m;
        return biggest_factor;
    }

    int operator()() const {
        return this->operator()(600851475143);
    }
};

class Problem0004 {
public:
    int IsMultipleOf3DigitNumber(int number) const {
        for (int multiple = 999; multiple >= 100; multiple--) {
            if (number % multiple == 0) {
                return multiple;
            }
        }
        return 0;
    }

    // PalindromeOf3DigitNumber
    long operator()() const {
        int palindrome = -1;

        for (int digit1 = 0; digit1 <= 9; digit1++) {
            int temp_palindrome = 999999 - 100001 * digit1;
            for (int digit2 = 0; digit2 <= 9; digit2++) {
                int temp_palindrome2 = temp_palindrome - 10010 * digit2;
                for (int digit3 = 2; digit3 <= 9; digit3++) {
                    palindrome = temp_palindrome2 - 1100 * digit3;
                    int first_multiple = IsMultipleOf3DigitNumber(palindrome);
                    if (first_multiple > 0) {
                        int second_multiple = palindrome / first_multiple;
                        if (second_multiple >= 100 && second_multiple <= 999) {
                            return palindrome;
                        }
                    }
                }
            }
        }

        return palindrome;
    }
};

class Problem0005 {
public:
    // Smallest Multiple
    /* 
    * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
    * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
    */
    long long operator()() const {
        long long result = 10 // Includes division by 10, 5, 2, 1
            * 9 // Includes division by 9, 3 and with previous: 6, 18, 15, ...
            * 4 // Includes 4 and with p: 8, 20, 12 
            * 7; // Includes 7 and with p: 14
        // This is 2520 and has 1 to 10
        // Expand to 1 to 20
        result = result
            * 11 // Includes 11
            * 13 // Includes 13
            * 2  // With p: 16 (2*4*2)
            * 17 // Includes 17
            * 19 // Includes 19
            ;
        return result;
    }
};

class Problem0006 {
public:
    // Sum Square Difference
    /*
    <p>The sum of the squares of the first ten natural numbers is,</p>
    $$1^2 + 2^2 + ... + 10^2 = 385.$$
    <p>The square of the sum of the first ten natural numbers is,</p>
    $$(1 + 2 + ... + 10)^2 = 55^2 = 3025.$$
    <p>Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is $3025 - 385 = 2640$.</p>
    <p>Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.</p>
    */
    long long operator()(long long n) const {
        long long sumSquares = 0;
        for (long long i = 1; i <= n; i++) {
            sumSquares += i * i;
        }
        long long squareSum = (n*(n+1))/2;
        squareSum = squareSum * squareSum;
        return squareSum - sumSquares;
    }

    long long operator()() const {
        long long result = operator()(100);
        return result;
    }
};

class Problem0007 {
public:
    // 10001st Prime
    /*
    <p>By listing the first six prime numbers: $2, 3, 5, 7, 11$, and $13$, we can see that the $6$th prime is $13$.</p>
    <p>What is the $10\,001$st prime number?</p>
    */
    long long operator()(long long n) const {
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
            primes.push_back(p_test);
            if (primes.size() % 100 == 0) {
                std::cout << "\rProgress: " << primes.size() << "\t/ " << n;
                std::cout.flush();
            }
        }
        return primes.back();
    }

    long long operator()() const {
        long long result = operator()(10001);
        return result;
    }
};

int main()
{
    using namespace std;
    std::cout << "The answer is: " << Problem0007()() << "\n";
}