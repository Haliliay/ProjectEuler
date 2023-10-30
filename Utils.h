#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <numeric>
#include <fstream>
#include <sstream>
#include <iterator>
#include <cassert>
#include <functional>

namespace hu {
    long long GetNumOfDigits(long long number);

    long long GetNthDigit(long long number, long long n);

    bool PalindromeCheck(long long number);

    std::vector<long long> genNPrimes(long long n);

    std::vector<long long> genPrimesBelowN(long long n);

    std::vector<long long> divisorsOf(long long n);

    std::vector<std::pair<long long, long long>> primeFactorsOf(long long n);

    template <typename Out>
    void split(const std::string& s, char delim, Out result);

    std::vector<std::string> split(const std::string& s, char delim);

    std::vector<std::vector<int>> readIntsInto2dArray(std::string filename);

    bool isLeapYear(long long year);

    int ctoi(const char c);

    /// <summary>
    /// Print the percentage of a of n, if it has a difference of at least 1% compared to the last printed percentage.
    /// </summary>
    /// <param name="a"></param>
    /// <param name="n"></param>
    void printProgress(long long a, long long n);

    /// <summary>
    /// Sorts a list with elements that are comparable by <=.
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <param name="list"></param>
    /// <param name="start"></param>
    /// <param name="end"></param>
    template<typename T>
    void quickSort(std::vector<T>& list, long long start, long long end, std::function<int(const T&, const T&)> compar)
    {
        static int stackCount = 0;
        stackCount++;
        static auto quickSortPartition = [&](std::vector<T>& list, long long start, long long end) {
            T pivot = list[start];
            long long offset = 0;
            for (long long i = start + 1; i <= end; i++) {
                if (compar(list[i], pivot) <= 0)
                    offset++;
            }
            // Put pivot in its correct place
            list[start] = list[start + offset];
            list[start + offset] = pivot;
            return offset;
        };

        if (start >= end)
            return;

        // Partition list into two (hopefully equal) halves
        long long pOffset = quickSortPartition(list, start, end);
        if((pOffset - 1) < pOffset)
            quickSort(list, start, pOffset - 1, compar);
        if((pOffset + 1) > pOffset)
            quickSort(list, pOffset + 1, end, compar);
        stackCount--;
    }

    template<typename T>
    void quickSort(std::vector<T>& list, int start, int end, std::function<int(const T&, const T&)> compar)
    {
        static int stackCount = 0;
        stackCount++;
        static auto quickSortPartition = [&](std::vector<T>& list, int start, int end) {
            T pivot = list[start];
            int offset = 0;
            for (int i = start + 1; i <= end; i++) {
                if (compar(list[i], pivot) <= 0)
                    offset++;
            }
            // Put pivot in its correct place
            int pi = start + offset;
            std::swap(list[start], list[pi]);

            // Put lower values on the left and higher values on the right
            int i = start, j = end;
            while (i < pi && j > pi) {
                while (list[i] < pivot)
                    i++;
                while (list[j] > pivot)
                    j--;
                if (i < pi && j > pi)
                    std::swap(list[i++], list[j--]);
            }

            return pi;
        };

        if (start >= end)
            return;

        // Partition list into two (hopefully equal) halves
        int pi = quickSortPartition(list, start, end);
        if((pi - 1) < pi)
            quickSort(list, start, pi - 1, compar);
        if((pi + 1) > pi)
            quickSort(list, pi + 1, end, compar);
        stackCount--;
    }
}
