#include "Problems11-20.h"
using namespace std;

long long Problem0011::operator()(long long n) const
{
    long long max = 0;
    // Test if next method will be in the grid bounds
    auto rowTest = [=](size_t row, size_t col) -> bool { return (col + n) <= 20; };
    // Calculate product sum of length n from grid position (row, col)
    // in a row from left to right
    auto rowProduct = [&](size_t row, size_t col) {
        long long product = 1;
        assert(rowTest(row, col));
        for (size_t i = 0; i < n; i++) {
            product *= grid[row][col + i];
        };
        return product;
    };

    // Test if next method will be in the grid bounds
    auto colTest = [=](size_t row, size_t col) -> bool { return (row + n) <= 20; };
    // Calculate product sum of length n from grid position (row, col)
    // in a col from top to bottom
    auto colProduct = [&](size_t row, size_t col) {
        long long product = 1;
        assert(colTest(row, col));
        for (size_t i = 0; i < n; i++) {
            product *= grid[row + i][col];
        };
        return product;
    };

    // Test if next method will be in the grid bounds
    auto diagRightTest = [=](size_t row, size_t col) -> bool { return (row + n) <= 20 && (col + n) <= 20; };
    // Calculate product sum of length n from grid position (row, col)
    // in a diagonal line from top left to bottom right
    auto diagRightProduct = [&](size_t row, size_t col) {
        long long product = 1;
        assert(diagRightTest(row, col));
        for (size_t i = 0; i < n; i++) {
            product *= grid[row + i][col + i];
        };
        return product;
    };

    // Test if next method will be in the grid bounds
    auto diagLeftTest = [=](size_t row, size_t col) -> bool { return (row + n) <= 20 && col >= (n - 1); };
    // Calculate product sum of length n from grid position (row, col)
    // in a diagonal line from top right to bottom left
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

    // Search for highest product sum
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
    file.open("data/p0013.txt");
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
    return stoll(line.substr(0, 10));
}


long long Problem0014::operator()(long n) const {
    using namespace std;
    vector<long> sequence_lengths(n); // for memoization
    sequence_lengths[1] = 1;

    for (long i = 1; i < sequence_lengths.size(); i++) {
        long long c_num = i; // 1 to n-1
        vector<long long> sequence{ c_num };
        while (c_num >= sequence_lengths.size() || sequence_lengths[c_num] == 0) {
            if (c_num == 1)
                break;
            else {
                if (c_num % 2 == 0) {
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
            if (c_num < sequence_lengths.size() && sequence[seq_end] < sequence_lengths.size())
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
        if (sequence_lengths[i] > max_length) {
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
    // static grid for memoization
    static vector<vector<long long>> pathOptions = { {1} };

    // resize the grid if it is not big enough
    while (pathOptions.size() <= y) {
        pathOptions.push_back(vector<long long>{-1});
    }
    for (int i = 0; i <= y; i++) {
        while (pathOptions[i].size() <= x) {
            pathOptions[i].push_back(-1);
        }
    }


    if (x == 0 || y == 0) {
        // base case
        pathOptions[y][x] = 1;
    }
    else if (pathOptions[y][x] >= 0) {
        // memoized case
        return pathOptions[y][x];
    }
    else {
        // recursive case
        pathOptions[y][x] = operator()(x - 1, y) + operator()(x, y - 1);
    }
    return pathOptions[y][x];
}

long long Problem0015::operator()() const {
    return operator()(20, 20);
}


long long Problem0016::operator()(long n) const {
    ap_uint<10000> pow2by1000 = 1;
    pow2by1000 <<= n;
    string s = (string)pow2by1000;
    long long sum = 0;
    for (int i = 0; i < s.size(); i++) {
        sum += s[i] - '0';
    }
    return sum;
}

long long Problem0016::operator()() const {
    return operator()(1000);
}


long long Problem0017::lettersInNumber(long long n) {
    using namespace std;
    static map<long long, long long> lettersInNumber;
    long long origN = n;

    auto it = lettersInNumber.find(n);
    if (it != lettersInNumber.end()) {
        return it->second;
    }
    else {
        long long letterCount = 0;
        int iterSpecialName = 0;
        while (n > 0) {
            // Look at lowest three digits at a time
            int tempN = n % 1000;
            if (tempN > 0) {
                // Add special name suffix like "thousand".
                // Happens only after first loop.
                if (iterSpecialName > 0 && iterSpecialName < specialNames.size()) {
                    // add conjunction "and" only if the lower part of the number is non zero
                    if (letterCount > 0) {
                        letterCount += 3;
                    }
                    letterCount += specialNames[iterSpecialName].size();
                }

                // add third digit
                if (tempN >= 100) {
                    letterCount += digits[hu::getNthDigit(tempN, 3)].size() + specialNames[0].size();
                    tempN %= 100;

                    // add conjunction "and" only if the lower part of the number is non zero
                    if (tempN > 0) {
                        letterCount += 3;
                    }
                }

                // add last two digits
                if (tempN >= 20) {
                    letterCount += tens[hu::getNthDigit(tempN, 2)].size();
                    tempN %= 10;
                    if (tempN > 0)
                        letterCount += digits[tempN].size();
                }
                else if (tempN >= 10) {
                    letterCount += tenToNineteen[tempN % 10].size();
                }
                else if (tempN > 0) {
                    letterCount += digits[tempN].size();
                }
            }
            // Handled up to 3 bundled digits, now loop if there are more
            n /= 1000;
            iterSpecialName++;
        }
        lettersInNumber.emplace(origN, letterCount);
        return letterCount;
    }
}

long long Problem0017::operator()(long n) {
    long long lettersOneToN = 0;
    for (int i = 1; i <= n; i++) {
        lettersOneToN += lettersInNumber(i);
    }
    return lettersOneToN;
}

long long Problem0017::operator()() {
    return operator()(1000);
}


long long Problem0018::operator()(std::string filename) {
    auto triangle = hu::readIntsInto2dArray(filename, ' ');

    // Iterate from bottom up and add the bigger leaf to the parent
    for (int y = triangle.size() - 2; y >= 0; y--) {
        for (int x = 0; x < triangle[y].size(); x++) {
            triangle[y][x] += max(triangle[y + 1][x], triangle[y + 1][x + 1]);
        }
    }

    return triangle[0][0];
}

long long Problem0018::operator()() {
    return operator()("data/p0018.txt");
}


int Problem0019::addMonth(int month, int year)
{
    assert(month >= 1 && month <= 12);
    if (month == 2) {
        return hu::isLeapYear(year) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
    return 0;
}

long long Problem0019::operator()(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear)
{
    int sumSundays = 0;
    int curDay = 0;
    for (int i = 1900; i < startYear; i++) {
        if (hu::isLeapYear(i)) {
            curDay += 366;
        }
        else {
            curDay += 365;
        }
    }
    for (int i = 1; i < startMonth; i++) {
        curDay += addMonth(i, startYear);
    }
    curDay = curDay % 7;

    for (int i = startYear; i <= endYear; i++) {
        int j = 1, jEnd = 12;
        if (i == startYear)
            j = startMonth;
        if (i == endYear)
            jEnd = endMonth;

        for (; j <= jEnd; j++) {
            curDay %= 7;
            if (curDay == 6)
                sumSundays++;
            curDay += addMonth(j, i);
        }
    }

    return sumSundays;
}

long long Problem0019::operator()()
{
    return operator()(1, 2, 1901, 31, 12, 2000);
}


long long Problem0020::operator()(int factorial)
{
    ap_uint<2000> fac = 1;
    for (int i = 2; i <= factorial; i++) {
        auto oldFac = fac;
        fac *= i;
        assert(fac > oldFac);
    }
    std::string facString = std::string(fac);
    long long facSum = 0;
    for (int i = 0; i < facString.size(); i++) {
        facSum += hu::cdtoid(facString[i]);
    }
    return facSum;
}

long long Problem0020::operator()()
{
    return operator()(100);
}