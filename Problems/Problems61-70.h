#pragma once
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include "Problems11-20.h"   // Problem67 uses Problem18
#include "Utils.h"
#include "ap/ap.hpp"

class Problem0061 {
    /*
    * Cyclical Figurate Numbers
    * https://projecteuler.net/problem=61
    */

public:
    /// <summary>
    /// Returns the sum of the only ordered set of six cyclic 4-digit numbers 
    /// for which each polygonal type : triangle, square, pentagonal, hexagonal, 
    /// heptagonal, and octagonal, is represented by a different number in the set.
    /// </summary>
    /// <returns></returns>
    std::string operator()();

    /// <summary>
    /// Generates all figurate numbers according to the 'id'-th formula with 'digits' digits.
    /// Only supports formulae 3 to 8.
    /// </summary>
    /// <param name="id"></param>
    /// <param name="digits"></param>
    /// <returns></returns>
    std::vector<std::string> genFigurates(int id, int digits);

    /// <summary>
    /// For each ordered set, adds all possible cyclic continuations from the figurates, into a new list of ordered sets.
    /// Ignores sets that already have an element from the fID-figurates.
    /// Appends the fID to the IDs of the set (first part of pair).
    /// </summary>
    /// <param name="orderedSets"></param>
    /// <param name="figurates"></param>
    /// <returns></returns>
    std::vector<std::pair<std::string, std::vector<std::string>>> genSetsFromNextCyclic(
        const std::vector<std::pair<std::string, std::vector<std::string>>>& orderedSets, 
        const std::vector<std::string>& figurates,
        char fID);
};

class Problem0062 {
    /*
    * Cubic Permutations
    * https://projecteuler.net/problem=62
    */

public:
    /// <summary>
    /// Returns the smallest cube for which exactly n permutations of its digits are cube.
    /// </summary>
    /// <param name="n"></param>
    /// <returns></returns>
    std::string operator()(int n);

    /// <summary>
    /// Returns the smallest cube for which exactly five permutations of its digits are cube.
    /// </summary>
    /// <returns></returns>
    std::string operator()();
};

class Problem0067  {
    /*
    * Maximum Path Sum II
    * https://projecteuler.net/problem=67
    */

public:
    long long operator()(std::string filename) const;
};