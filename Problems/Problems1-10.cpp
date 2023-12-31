#include "Problems1-10.h"

using namespace std;

long long Problem0001::operator()(long long m) const {
    int sum = 0;
    for (int i = 1; i < m; i++) {
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    }
    return sum;
}

long long Problem0001::operator()() const {
    return this->operator()(1000);
}


long long Problem0002::operator()(long long m) const {
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

long long Problem0002::operator()() const {
    return this->operator()(4e6);
}


long long Problem0003::operator()(long long m) const {
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

long long Problem0003::operator()() const {
    return this->operator()(600851475143);
}


int Problem0004::IsMultipleOf3DigitNumber(int number) const {
    for (int multiple = 999; multiple >= 100; multiple--) {
        if (number % multiple == 0) {
            return multiple;
        }
    }
    return 0;
}

long long Problem0004::operator()() const {
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


long long Problem0005::operator()() const {
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


long long Problem0006::operator()(long long n) const {
    long long sumSquares = 0;
    for (long long i = 1; i <= n; i++) {
        sumSquares += i * i;
    }
    long long squareSum = (n * (n + 1)) / 2;
    squareSum = squareSum * squareSum;
    return squareSum - sumSquares;
}

long long Problem0006::operator()() const {
    long long result = operator()(100);
    return result;
}


long long Problem0007::operator()(long long n) const {
    return hu::genNPrimes(n).back();
}

long long Problem0007::operator()() const {
    long long result = operator()(10001);
    return result;
}


long long Problem0008::operator()(long long n) const {
    auto getDigit = [&](size_t pos) -> long long { return largeDigitNumber[pos] - '0'; };
    long long cachedWindowProduct = 1;
    auto cacheProduct = [&](size_t begin) {
        cachedWindowProduct = 1;
        for (size_t i = begin; i < begin+n; i++) {
            cachedWindowProduct *= getDigit(i);
        }; 
    };
    cacheProduct(0);

    long long max = cachedWindowProduct;
    for (size_t i = n; i < largeDigitNumber.size(); i++) {
        if (getDigit(i) == 0) {
            size_t digitsSinceZero = 0;
            while (digitsSinceZero < n && (i+1) < largeDigitNumber.size()) {
                i++; // Skip until n digits are non zero
                digitsSinceZero++;
                if (getDigit(i) == 0) {
                    digitsSinceZero = 0;
                }
            }
            // Now we have n non zero digits from (i - n + 1) to i
            cacheProduct(i - n + 1);
        }
        else {
            cachedWindowProduct = cachedWindowProduct / getDigit(i - n) * getDigit(i);
        }
        if (cachedWindowProduct > max)
            max = cachedWindowProduct;
    }
    return max;
}

long long Problem0008::operator()() const {
    long long result = operator()(13);
    return result;
}


long long Problem0009::operator()() const {
    long long result = -1;

    int a = 1, b = 2, c = 1000 - a - b;
    auto isPytTriplet = [&]() -> bool { return a * a + b * b == c * c; };

    while (a < 500) {
        b = a + 1;
        while (b < 500) {
            c = 1000 - a - b;
            if (c <= b) {
                break;
            }
            else if (isPytTriplet()) {
                return a * b * c;
            }
            b++;
        }
        a++;
    }

    return result;
}


long long Problem0010::operator()(long long n) const
{
    long long sum = 0;
    for (auto p : hu::genPrimesBelowN(n)) {
        sum += p;
    }
    return sum;
}

long long Problem0010::operator()() const
{
    return this->operator()(2e6);
}