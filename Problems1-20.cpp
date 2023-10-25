#include "Problems1-20.h"

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


long long Problem0011::operator()(long long n) const
{
    long long max = 0;
    auto rowTest = [=](size_t row, size_t col) -> bool { return (col + n) <= 20; };
    auto rowProduct = [&](size_t row, size_t col) {
        long long product = 1;
        assert(rowTest(row, col));
        for (size_t i = 0; i < n; i++) {
            product *= grid[row][col + i];
        };
        return product;
    };

    auto colTest = [=](size_t row, size_t col) -> bool { return (row + n) <= 20; };
    auto colProduct = [&](size_t row, size_t col) {
        long long product = 1;
        assert(colTest(row, col));
        for (size_t i = 0; i < n; i++) {
            product *= grid[row + i][col];
        };
        return product;
    };
    
    auto diagRightTest = [=](size_t row, size_t col) -> bool { return (row + n) <= 20 && (col + n) <= 20; };
    auto diagRightProduct = [&](size_t row, size_t col) {
        long long product = 1;
        assert(diagRightTest(row, col));
        for (size_t i = 0; i < n; i++) {
            product *= grid[row + i][col + i];
        };
        return product;
    };
    
    auto diagLeftTest = [=](size_t row, size_t col) -> bool { return (row + n) <= 20 && col >= (n - 1); };
    auto diagLeftProduct = [&](size_t row, size_t col) {
        long long product = 1;
        assert(diagLeftTest(row, col));
        for (size_t i = 0; i < n; i++) {
            product *= grid[row + i][col - i];
        };
        return product;
    };
    
    auto replaceMax = [&max](long long product)
    {
        if (max < product)
            max = product;
    };
    
    for (size_t i = 0; i < 20; i++) {
        for (size_t j = 0; j < 20; j++) {
            long long product = 1;
            if (rowTest(i, j)) {
                replaceMax(rowProduct(i, j));
            }
            if (colTest(i, j)) {
                replaceMax(colProduct(i, j));
            }
            if (diagRightTest(i, j)) {
                replaceMax(diagRightProduct(i, j));
            }
            if (diagLeftTest(i, j)) {
                replaceMax(diagLeftProduct(i, j));
            }
        }
    }
    return max;
}

long long Problem0011::operator()() const
{
    return operator()(4);
}


long long Problem0012::operator()(long long divisor_count) const
{
    long long curTriangleNumber = 1;
    long long curNumber = 1;

    if (divisor_count == 1)
        return 1;
    while (true) {
        curNumber++;
        curTriangleNumber += curNumber;
        auto divisors = hu::divisorsOf(curTriangleNumber);
        if (divisors.size() >= divisor_count)
            return curTriangleNumber;
        else {
            cout << "\rTriNumber: " << curTriangleNumber << "    Divisors: " << divisors.size();
            cout.flush();
        }
    }

    return curTriangleNumber;
}

long long Problem0012::operator()() const
{
    return operator()(500);
}