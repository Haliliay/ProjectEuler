#pragma once
#include "Utils.h"

class Problem0031 {
public:
    /*
    * Coin Sums
    <p>In the United Kingdom the currency is made up of pound (�) and pence (p). There are eight coins in general circulation:</p>
    <blockquote>1p, 2p, 5p, 10p, 20p, 50p, �1 (100p), and �2 (200p).</blockquote>
    <p>It is possible to make �2 in the following way:</p>
    <blockquote>1ף1 + 1�50p + 2�20p + 1�5p + 1�2p + 3�1p</blockquote>
    <p>How many different ways can �2 be made using any number of coins?</p>
    */

    /// <summary>
    /// Returns the amount of different ways that n pence can be made using any number of coins.
    /// </summary>
    /// <param name="pence"></param>
    /// <returns></returns>
    std::string operator()(int pence);

    /// <summary>
    /// Returns the amount of different ways that �2 can be made using any number of coins.
    /// </summary>
    /// <returns></returns>
    std::string operator()();
};