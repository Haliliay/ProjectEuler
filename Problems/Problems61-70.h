#pragma once
#include <string>
#include <vector>
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
};

class Problem0067  {
    /*
    * Maximum Path Sum II
    * https://projecteuler.net/problem=67
    */

public:
    long long operator()(std::string filename) const;
};