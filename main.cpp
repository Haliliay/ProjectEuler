#include <iostream>
#include "Problems1-20.h"

int main()
{
    using namespace std;
    long long answer = Problem0012()(80);
    long long n = 1;
    long long lastSum = 1;
    while (lastSum < answer) {
        n++;
        lastSum = n * (n + 1) / 2;
    }
    std::cout << "\nThe answer is: " << answer << "  SumTo: " << n << "\n";
}