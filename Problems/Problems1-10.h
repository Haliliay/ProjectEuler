#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <iostream>
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