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
    long long last_divisor = 0;
    while (true) {
        curNumber++;
        curTriangleNumber += curNumber;
        auto factors = hu::primeFactorsOf(curTriangleNumber);
        long long divisors = [&]() {
            long long result = 1;
            for (auto& pair : factors) {
                result *= pair.second + 1;
            }
            return result;
        }();

        if (divisors >= divisor_count)
        {
            return curTriangleNumber;
        }
        else if (divisors >= last_divisor) {
            cout << "\rTriNumber: " << curTriangleNumber << "    Divisors: " << divisors;
            last_divisor = divisors;
            cout.flush();
        }
    }

    return curTriangleNumber;
}

long long Problem0012::operator()() const
{
    return operator()(500);
}


long long Problem0013::operator()() const {
    using namespace std;
    vector<string> fifty_digit_numbers(100);

    // Read the 50 digit numbers as strings
    ifstream file;
    string line;
    file.open("p0013.txt");
    if (file.is_open()) {
        int i = 0;
        while (getline(file, line)) {
            fifty_digit_numbers[i] = line;
            i++;
        }
        file.close();
    }

    unsigned long long sum = 0;
    for (auto& s : fifty_digit_numbers) {
        // We only need the first 13 digits for an accurate first 10 digit sum
        // because the remaining digits can at most carry 99 over and if digits
        // 11, 12, 13 are below 901, then the first 10 digits are accurate, else
        // they might be off by 1.
        unsigned long long num = stoull(s.substr(0, 16));
        sum += num;
    }
    line = to_string(sum);
    return stoll(line.substr(0,10));
}


long long Problem0014::operator()(long n) const {
    using namespace std;
    vector<long> sequence_lengths(n); // for memoization
    sequence_lengths[1] = 1;

    for (long i = 1; i < sequence_lengths.size(); i++) {
        long long c_num = i; // 1 to n-1
        vector<long long> sequence{c_num};
        while (c_num >= sequence_lengths.size() || sequence_lengths[c_num] == 0) {
            if (c_num == 1)
                break;
            else {
                if (c_num % 2 == 0){
                    c_num /= 2;
                }
                else {
                    c_num = 3 * c_num + 1;
                }
                sequence.push_back(c_num);
            }
        }
        int seq_end = sequence.size() - 1;
        for (int j = 0; j < seq_end; j++) {
            // memoize all calculated subsequences
            long long c_num = sequence[j];
            if(c_num < sequence_lengths.size() && sequence[seq_end] < sequence_lengths.size())
                sequence_lengths[c_num] = sequence.size() - j - 1 + sequence_lengths[sequence[seq_end]];
        }
        if (i % 1000 == 0)
        {
            cout << "\ri: " << i << " / " << sequence_lengths.size();
            cout.flush();
        }
    }

    long max_index = 1;
    long max_length = 1;
    for (long i = 0; i < sequence_lengths.size(); i++) {
        if(sequence_lengths[i] > max_length) {
            max_length = sequence_lengths[i];
            max_index = i;
        }
    }

    return max_index;
}

long long Problem0014::operator()() const {
    return operator()(1e6);
}


long long Problem0015::operator()(long x, long y) const {
    using namespace std;
    static vector<vector<long long>> pathOptions = { {1} }; 
    while (pathOptions.size() <= y) {
        pathOptions.push_back(vector<long long>{-1});
    }
    for (int i = 0; i <= y; i++) {
        while (pathOptions[i].size() <= x) {
            pathOptions[i].push_back(-1);
        }
    }

    if (x == 0 || y == 0) {
        pathOptions[y][x] = 1;
    }
    else if (pathOptions[y][x] >= 0) {
        return pathOptions[y][x];
    }
    else {
        pathOptions[y][x] = operator()(x - 1, y) + operator()(x, y - 1);
    }

    return pathOptions[y][x];
}

long long Problem0015::operator()() const {
    return operator()(20, 20);
}