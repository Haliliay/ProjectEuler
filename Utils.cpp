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
}
