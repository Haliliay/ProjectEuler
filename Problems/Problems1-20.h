#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cassert>
#include <fstream>
#include "Utils.h"
#include "ap/ap.hpp"

class Problem0001  {
public:
    // SumOfMultiplesOf3Or5
    long long operator()(long long m) const;
    long long operator()() const;
};

class Problem0002  {
public:
    // SumEvenValuedFibonacci
    long long operator()(long long m) const;
    long long operator()() const;
};

class Problem0003  {
public:
    // BiggestPrimeFactorOf
    long long operator()(long long m) const;
    long long operator()() const;
};

class Problem0004  {
public:
    int IsMultipleOf3DigitNumber(int number) const;

    // PalindromeOf3DigitNumber
    long long operator()() const;
};

class Problem0005  {
public:
    // Smallest Multiple
    /*
    * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
    * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
    */
    long long operator()() const;
};

class Problem0006  {
public:
    // Sum Square Difference
    /*
    <p>The sum of the squares of the first ten natural numbers is,</p>
    $$1^2 + 2^2 + ... + 10^2 = 385.$$
    <p>The square of the sum of the first ten natural numbers is,</p>
    $$(1 + 2 + ... + 10)^2 = 55^2 = 3025.$$
    <p>Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is $3025 - 385 = 2640$.</p>
    <p>Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.</p>
    */
    long long operator()(long long n) const;

    long long operator()() const;
};

class Problem0007 {
public:
    // 10001st Prime
    /*
    <p>By listing the first six prime numbers: $2, 3, 5, 7, 11$, and $13$, we can see that the $6$th prime is $13$.</p>
    <p>What is the $10\,001$st prime number?</p>
    */
    long long operator()(long long n) const;

    long long operator()() const;
};

class Problem0008 {
public:
    // Largest Product in a Series
    /*
    <p>The four adjacent digits in the $1000$-digit number that have the greatest product are $9 \times 9 \times 8 \times 9 = 5832$.</p>
    <p class="monospace center">
    73167176531330624919225119674426574742355349194934<br>
    96983520312774506326239578318016984801869478851843<br>
    85861560789112949495459501737958331952853208805511<br>
    12540698747158523863050715693290963295227443043557<br>
    66896648950445244523161731856403098711121722383113<br>
    62229893423380308135336276614282806444486645238749<br>
    30358907296290491560440772390713810515859307960866<br>
    70172427121883998797908792274921901699720888093776<br>
    65727333001053367881220235421809751254540594752243<br>
    52584907711670556013604839586446706324415722155397<br>
    53697817977846174064955149290862569321978468622482<br>
    83972241375657056057490261407972968652414535100474<br>
    82166370484403199890008895243450658541227588666881<br>
    16427171479924442928230863465674813919123162824586<br>
    17866458359124566529476545682848912883142607690042<br>
    24219022671055626321111109370544217506941658960408<br>
    07198403850962455444362981230987879927244284909188<br>
    84580156166097919133875499200524063689912560717606<br>
    05886116467109405077541002256983155200055935729725<br>
    71636269561882670428252483600823257530420752963450<br></p>
    <p>Find the thirteen adjacent digits in the $1000$-digit number that have the greatest product. What is the value of this product?</p>
    */
    std::string largeDigitNumber{ "73167176531330624919225119674426574742355349194934"
        "96983520312774506326239578318016984801869478851843"
        "85861560789112949495459501737958331952853208805511"
        "12540698747158523863050715693290963295227443043557"
        "66896648950445244523161731856403098711121722383113"
        "62229893423380308135336276614282806444486645238749"
        "30358907296290491560440772390713810515859307960866"
        "70172427121883998797908792274921901699720888093776"
        "65727333001053367881220235421809751254540594752243"
        "52584907711670556013604839586446706324415722155397"
        "53697817977846174064955149290862569321978468622482"
        "83972241375657056057490261407972968652414535100474"
        "82166370484403199890008895243450658541227588666881"
        "16427171479924442928230863465674813919123162824586"
        "17866458359124566529476545682848912883142607690042"
        "24219022671055626321111109370544217506941658960408"
        "07198403850962455444362981230987879927244284909188"
        "84580156166097919133875499200524063689912560717606"
        "05886116467109405077541002256983155200055935729725"
        "71636269561882670428252483600823257530420752963450" };

    long long operator()(long long n) const;

    long long operator()() const;
};

class Problem0009 {
public:
    // Special Pythagorean Triplet
    /*
    <p>A Pythagorean triplet is a set of three natural numbers, $a \lt b \lt c$, for which,
    $$a^2 + b^2 = c^2.$$</p>
    <p>For example, $3^2 + 4^2 = 9 + 16 = 25 = 5^2$.</p>
    <p>There exists exactly one Pythagorean triplet for which $a + b + c = 1000$.<br>Find the product $abc$.</p>
    */
    long long operator()() const;
};

class Problem0010 {
public:
    // Summation of Primes
    /*
    <p>The sum of the primes below $10$ is $2 + 3 + 5 + 7 = 17$.</p>
    <p>Find the sum of all the primes below two million.</p>
    */
    long long operator()(long long n) const;

    long long operator()() const;
};


class Problem0011 {
public:
    // Largest Product in a Grid
    /*
    <p>In the $20 \times 20$ grid below, four numbers along a diagonal line have been marked in red.</p>
    <p class="monospace center">
    08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08<br>
    49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00<br>
    81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65<br>
    52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91<br>
    22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80<br>
    24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50<br>
    32 98 81 28 64 23 67 10 <span class="red"><b>26</b></span> 38 40 67 59 54 70 66 18 38 64 70<br>
    67 26 20 68 02 62 12 20 95 <span class="red"><b>63</b></span> 94 39 63 08 40 91 66 49 94 21<br>
    24 55 58 05 66 73 99 26 97 17 <span class="red"><b>78</b></span> 78 96 83 14 88 34 89 63 72<br>
    21 36 23 09 75 00 76 44 20 45 35 <span class="red"><b>14</b></span> 00 61 33 97 34 31 33 95<br>
    78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92<br>
    16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57<br>
    86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58<br>
    19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40<br>
    04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66<br>
    88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69<br>
    04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36<br>
    20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16<br>
    20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54<br>
    01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48<br></p>
    <p>The product of these numbers is $26 \times 63 \times 78 \times 14 = 1788696$.</p>
    <p>What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the $20 \times 20$ grid?</p>
    */
  int grid[20][20]{{8, 2, 22, 97, 38, 15, 0, 40, 0, 75, 4, 5, 7, 78, 52, 12, 50, 77, 91, 8},
                   {49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 4, 56, 62, 0},
                   {81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 3, 49, 13, 36, 65},
                   {52, 70, 95, 23, 4, 60, 11, 42, 69, 24, 68, 56, 1, 32, 56, 71, 37, 2, 36, 91},
                   {22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80},
                   {24, 47, 32, 60, 99, 3, 45, 2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50},
                   {32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70},
                   {67, 26, 20, 68, 2, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21},
                   {24, 55, 58, 5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72},
                   {21, 36, 23, 9, 75, 0, 76, 44, 20, 45, 35, 14, 0, 61, 33, 97, 34, 31, 33, 95},
                   {78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 3, 80, 4, 62, 16, 14, 9, 53, 56, 92},
                   {16, 39, 5, 42, 96, 35, 31, 47, 55, 58, 88, 24, 0, 17, 54, 24, 36, 29, 85, 57},
                   {86, 56, 0, 48, 35, 71, 89, 7, 5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58},
                   {19, 80, 81, 68, 5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 4, 89, 55, 40},
                   {4, 52, 8, 83, 97, 35, 99, 16, 7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66},
                   {88, 36, 68, 87, 57, 62, 20, 72, 3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69},
                   {4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36},
                   {20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 4, 36, 16},
                   {20, 73, 35, 29, 78, 31, 90, 1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 5, 54},
                   {1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 1, 89, 19, 67, 48}};

  long long operator()(long long n) const;

  long long operator()() const;
};

class Problem0012 {
public:
    // Highly Divisible Triangular Number
    /*
    <p>The sequence of triangle numbers is generated by adding the natural numbers. So the $7$<sup>th</sup> triangle number would be $1 + 2 + 3 + 4 + 5 + 6 + 7 = 28$. The first ten terms would be:
    $$1, 3, 6, 10, 15, 21, 28, 36, 45, 55, \dots$$</p>
    <p>Let us list the factors of the first seven triangle numbers:</p>
    \begin{align}
    \mathbf 1 &amp;\colon 1\\
    \mathbf 3 &amp;\colon 1,3\\
    \mathbf 6 &amp;\colon 1,2,3,6\\
    \mathbf{10} &amp;\colon 1,2,5,10\\
    \mathbf{15} &amp;\colon 1,3,5,15\\
    \mathbf{21} &amp;\colon 1,3,7,21\\
    \mathbf{28} &amp;\colon 1,2,4,7,14,28
    \end{align}
    <p>We can see that $28$ is the first triangle number to have over five divisors.</p>
    <p>What is the value of the first triangle number to have over five hundred divisors?</p>
    */
    long long operator()(long long divisor_count) const;
    long long operator()() const;
};

class Problem0013 {
public:
    // Large Sum
    /*
    Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
    */
    std::vector<std::string> fifty_digit_numbers;

    long long operator()() const;
};

class Problem0014 {
public:
    // Longest Collatz Sequence
    /*
    <p>The following iterative sequence is defined for the set of positive integers:</p>
    <ul style="list-style-type:none;">
    <li>$n \to n/2$ ($n$ is even)</li>
    <li>$n \to 3n + 1$ ($n$ is odd)</li></ul>
    <p>Using the rule above and starting with $13$, we generate the following sequence:
    $$13 \to 40 \to 20 \to 10 \to 5 \to 16 \to 8 \to 4 \to 2 \to 1.$$</p>
    <p>It can be seen that this sequence (starting at $13$ and finishing at $1$) contains $10$ terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at $1$.</p>
    <p>Which starting number, under one million, produces the longest chain?</p>
    <p class="note"><b>NOTE:</b> Once the chain starts the terms are allowed to go above one million.</p>
    */

    long long operator()(long n) const;
    long long operator()() const;
};

class Problem0015 {
public:
    // Lattice Paths
    /*
    <p>Starting in the top left corner of a $2 \times 2$ grid, and only being able to move to the right and down, there are exactly $6$ routes to the bottom right corner.</p>
    <div class="center">
    <img src="resources/images/0015.png?1678992052" class="dark_img" alt=""></div>
    <p>How many such routes are there through a $20 \times 20$ grid?</p>
    */

    long long operator()(long x, long y) const;
    long long operator()() const;
};

class Problem0016 {
public:
    // Power Digit Sum
    /*
    <p>$2^{15} = 32768$ and the sum of its digits is $3 + 2 + 7 + 6 + 8 = 26$.</p>
    <p>What is the sum of the digits of the number $2^{1000}$?</p>
    */

    long long operator()(long n) const;
    long long operator()() const;
};

class Problem0017 {
private:
    std::vector<std::string> digits { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    std::vector<std::string> tenToNineteen { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    std::vector<std::string> tens { "zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
    std::vector<std::string> specialNames { "hundred", "thousand", "million", "billion" };

    long long lettersInNumber(long long n);

public:
    // Number Letter Counts
    /*
    <p>If the numbers $1$ to $5$ are written out in words: one, two, three, four, five, then there are $3 + 3 + 5 + 4 + 4 = 19$ letters used in total.</p>
    <p>If all the numbers from $1$ to $1000$ (one thousand) inclusive were written out in words, how many letters would be used? </p>
    <br><p class="note"><b>NOTE:</b> Do not count spaces or hyphens. 
    For example, $342$ (three hundred and forty-two) contains $23$ letters and $115$ (one hundred and fifteen) contains $20$ letters. 
    The use of "and" when writing out numbers is in compliance with British usage.</p>
    */

    long long operator()(long n);
    long long operator()();
};

class Problem0018 {
public:
    // Maximum Path Sum I
    /*
    <p>By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.</p>
    <p class="monospace center"><span class="red"><b>3</b></span><br><span class="red"><b>7</b></span> 4<br>
    2 <span class="red"><b>4</b></span> 6<br>
    8 5 <span class="red"><b>9</b></span> 3</p>
    <p>That is, 3 + 7 + 4 + 9 = 23.</p>
    <p>Find the maximum total from top to bottom of the triangle below:</p>
    <p class="monospace center">75<br>
    95 64<br>
    17 47 82<br>
    18 35 87 10<br>
    20 04 82 47 65<br>
    19 01 23 75 03 34<br>
    88 02 77 73 07 63 67<br>
    99 65 04 28 06 16 70 92<br>
    41 41 26 56 83 40 80 70 33<br>
    41 48 72 33 47 32 37 16 94 29<br>
    53 71 44 65 25 43 91 52 97 51 14<br>
    70 11 33 28 77 73 17 78 39 68 17 57<br>
    91 71 52 38 17 14 91 43 58 50 27 29 48<br>
    63 66 04 68 89 53 67 30 73 16 69 87 40 31<br>
    04 62 98 27 23 09 70 98 73 93 38 53 60 04 23</p>
    <p class="note"><b>NOTE:</b> As there are only 16384 routes, it is possible to solve this problem by trying every route. 
    However, <a href="problem=67">Problem 67</a>, is the same challenge with a triangle containing one-hundred rows; 
    it cannot be solved by brute force, and requires a clever method! ;o)</p>
    */

    long long operator()(std::string filename);
};

class Problem0019 {
public:
    // Counting Sundays
    /*
    <p>You are given the following information, but you may prefer to do some research for yourself.</p>
    <ul><li>1 Jan 1900 was a Monday.</li>
    <li>Thirty days has September,<br />
    April, June and November.<br />
    All the rest have thirty-one,<br />
    Saving February alone,<br />
    Which has twenty-eight, rain or shine.<br />
    And on leap years, twenty-nine.</li>
    <li>A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.</li>
    </ul><p>How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?</p>
    */

    int addMonth(int month, int year);

    /// <summary>
    /// 
    /// </summary>
    /// <param name="startDay">1-31</param>
    /// <param name="startMonth">1-12</param>
    /// <param name="startYear">1900-any</param>
    /// <param name="endDay"></param>
    /// <param name="endMonth"></param>
    /// <param name="endYear"></param>
    /// <returns></returns>
    long long operator()(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear);
    long long operator()();
};