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
#include <algorithm>
#include <tuple>
#include <set>
#include <iterator>
#include "ap/ap.hpp"

namespace hu {
    long long GetNumOfDigits(long long number);

    long long GetNthDigit(long long number, long long n);

    bool PalindromeCheck(long long number);

    std::vector<long long> genNPrimes(long long n);

    std::vector<long long> genPrimesBelowN(long long n);

    /// <summary>
    /// Returns all divisors of positive integer n, including 1 and n.
    /// </summary>
    /// <param name="n"></param>
    /// <returns></returns>
    std::vector<long long> divisorsOf(long long n);

    /// <summary>
    /// Returns all proper divisors of positive integer n, including 1.
    /// </summary>
    /// <param name="n"></param>
    /// <returns></returns>
    std::vector<long long> divisorsProperOf(long long n);

    std::vector<std::pair<long long, long long>> primeFactorsOf(long long n);

    template <typename Out>
    void split(const std::string& s, char delim, Out result);

    /// <summary>
    /// Splits s into strings seperated by delim.
    /// </summary>
    /// <param name="s"></param>
    /// <param name="delim"></param>
    /// <returns></returns>
    std::vector<std::string> split(const std::string& s, char delim);

    /// <summary>
    /// Reads ints from a file, seperated by delim, into a 2d array where each line is a row.
    /// </summary>
    /// <param name="filename"></param>
    /// <param name="delim"></param>
    /// <returns></returns>
    std::vector<std::vector<int>> readIntsInto2dArray(const std::string& filename, char delim);

    std::vector<int> readIntsFromFile(const std::string& filename, char delim);

    void writeIntsToFile(const std::vector<int>& list, const std::string& filename, char delim);

    bool isLeapYear(long long year);

    /// <summary>
    /// Char to int. Converts '3' to 3 etc.
    /// </summary>
    /// <param name="c"></param>
    /// <returns></returns>
    int ctoi(const char c);

    /// <summary>
    /// Print the percentage of a of n, if it has a difference of at least 1% compared to the last printed percentage.
    /// </summary>
    /// <param name="a"></param>
    /// <param name="n"></param>
    void printProgress(long long a, long long n);

    /// <summary>
    /// Sorts a list with elements that are comparable, e.g. a smaller b.
    /// Given an index range of the list.
    /// </summary>
    /// <typeparam name="T">Element type.</typeparam>
    /// <param name="list">List of elements.</param>
    /// <param name="start">Starting index of the list (included, usually 0).</param>
    /// <param name="end">Ending index of the list (included).</param>
    /// <param name="compar">Compare function returning a negative, 0 or positive value.</param>
    template<typename T>
    void quickSort(std::vector<T>& list, int start, int end, std::function<int(const T&, const T&)> compar)
    {
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
    }

    /// <summary>
    /// Sorts a list with elements that are comparable, e.g. a smaller b.
    /// </summary>
    /// <typeparam name="T">Element type.</typeparam>
    /// <param name="list">List of elements.</param>
    /// <param name="compar">Compare function returning a negative, 0 or positive value.</param>
    template<typename T>
    void quickSort(std::vector<T>& list, std::function<int(const T&, const T&)> compar)
    {
        quickSort(list, 0, list.size() - 1, compar);
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

    /// <summary>
    /// Returns the selectedIndex'th permutation of the given list in lexicographic order.
    /// Assumes all elements of the list are digits and the initial configuration is the starting order.
    /// </summary>
    /// <param name="list">digits to be used in lexicographic order</param>
    /// <param name="selectedIndex"></param>
    /// <returns></returns>
    std::vector<int> permSelect(const std::vector<int>& list, int selectedIndex);

    /// <summary>
    /// Returns the selectedIndex'th permutation of the given list in lexicographic order.
    /// Assumes all elements of the list are letters and the initial configuration is the starting order.
    /// </summary>
    /// <param name="list">letters to be used in lexicographic order</param>
    /// <param name="selectedIndex"></param>
    /// <returns></returns>
    std::string permSelect(const std::string& list, int selectedIndex);

    /// <summary>
    /// Returns all combinations of the elements of list.
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <param name="list"></param>
    /// <param name="K">Amount of selected elements in the combination</param>
    /// <returns></returns>
    template<typename T>
    std::set<std::vector<T>> comb(const std::vector<T>& list, int K = INT16_MAX)
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
