#pragma once
#include <numeric>
#include <fstream>
#include "Utils.h"
#include "ap/ap.hpp"

class Problem0021 {
public:
    // Amicable Numbers
    /*
    <p>Let $d(n)$ be defined as the sum of proper divisors of $n$ (numbers less than $n$ which divide evenly into $n$).<br>
    If $d(a) = b$ and $d(b) = a$, where $a \ne b$, then $a$ and $b$ are an amicable pair and each of $a$ and $b$ are called amicable numbers.</p>
    <p>For example, the proper divisors of $220$ are $1, 2, 4, 5, 10, 11, 20, 22, 44, 55$ and $110$; therefore $d(220) = 284$. The proper divisors of $284$ are $1, 2, 4, 71$ and $142$; so $d(284) = 220$.</p>
    <p>Evaluate the sum of all the amicable numbers under $10000$.</p>
    */

    /// <summary>
    /// Evaluates the sum of all the amicable numbers under n.
    /// </summary>
    /// <param name="n"></param>
    /// <returns></returns>
    long long operator()(long long n);
    long long operator()();
};

class Problem0022 {
public:
    // Names Scores
    /*
    <p>Using <a href="resources/documents/0022_names.txt">names.txt</a> (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.</p>
    <p>For example, when the list is sorted into alphabetical order, COLIN, which is worth $3 + 15 + 12 + 9 + 14 = 53$, is the $938$th name in the list. So, COLIN would obtain a score of $938 \times 53 = 49714$.</p>
    <p>What is the total of all the name scores in the file?</p>
    */

    /// <summary>
    /// Evaluates the sum of all the name scores in the file.
    /// </summary>
    /// <param name="n"></param>
    /// <returns></returns>
    long long operator()(std::string filename);
    long long operator()();

    /// <summary>
    /// Gets the alphabetic score of a letter in the english alphabet. Case insensitive.
    /// E.g. A = 1, D = 4, Z = 26.
    /// </summary>
    /// <param name="ch"></param>
    /// <returns></returns>
    int alphabeticalScore(char ch) const;

    /// <summary>
    /// Gets the alphabetic score of a word according to the english alphabet. Case insensitive.
    /// </summary>
    /// <param name="word"></param>
    /// <returns></returns>
    int alphabeticalScore(const std::string& word);
};

class Problem0023 {
public:
    // Non-Abundant Sums
    /*
    <p>A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of $28$ would be $1 + 2 + 4 + 7 + 14 = 28$, which means that $28$ is a perfect number.</p>
    <p>A number $n$ is called deficient if the sum of its proper divisors is less than $n$ and it is called abundant if this sum exceeds $n$.</p>

    <p>As $12$ is the smallest abundant number, $1 + 2 + 3 + 4 + 6 = 16$, the smallest number that can be written as the sum of two abundant numbers is $24$. By mathematical analysis, it can be shown that all integers greater than $28123$ can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.</p>
    <p>Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.</p>
    */

    /// <summary>
    /// Finds the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
    /// </summary>
    /// <returns></returns>
    long long operator()();

    std::vector<int> abundantNumsBelowN(int n);
};

class Problem0024 {
public:
    // Lexicographic Permutations
    /*
    <p>A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:</p>
    <p class="center">012   021   102   120   201   210</p>
    <p>What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?</p>
    */

    /// <summary>
    /// Returns the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9.
    /// </summary>
    /// <returns></returns>
    std::string operator()();
};

class Problem0025 {
public:
    // 1000-digit Fibonacci Number
    /*
    */

    /// <summary>
    /// Returns the first Fibonacci number with "digits" digits.
    /// </summary>
    /// <returns></returns>
    long long operator()(int digits);

    /// <summary>
    /// Returns the first 1000-digit Fibonacci number.
    /// </summary>
    /// <returns></returns>
    long long operator()();
};

class Problem0026 {
public:
    // Reciprocal Cycles
    /*
    * <p>A unit fraction contains $1$ in the numerator. The decimal representation of the unit fractions with denominators $2$ to $10$ are given:</p>
    \begin{align}
    1/2 &amp;= 0.5\\
    1/3 &amp;=0.(3)\\
    1/4 &amp;=0.25\\
    1/5 &amp;= 0.2\\
    1/6 &amp;= 0.1(6)\\
    1/7 &amp;= 0.(142857)\\
    1/8 &amp;= 0.125\\
    1/9 &amp;= 0.(1)\\
    1/10 &amp;= 0.1
    \end{align}
    <p>Where $0.1(6)$ means $0.166666\cdots$, and has a $1$-digit recurring cycle. It can be seen that $1/7$ has a $6$-digit recurring cycle.</p>
    <p>Find the value of $d \lt 1000$ for which $1/d$ contains the longest recurring cycle in its decimal fraction part.</p>
    */

    /// <summary>
    /// Returns the value of d lessThan n for which 1/d contains the longest recurring cycle in its decimal fraction part.
    /// </summary>
    /// <returns></returns>
    std::string operator()(long long  n);

    /// <summary>
    /// Returns the value of d lessThan 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
    /// </summary>
    /// <returns></returns>
    std::string operator()();


    std::string findNumCycle(const std::string& s);
};

class Problem0027 {
public:
    /*
    * Quadratic Primes
    * <p>Euler discovered the remarkable quadratic formula:</p>
    <p class="center">$n^2 + n + 41$</p>
    <p>It turns out that the formula will produce $40$ primes for the consecutive integer values $0 \le n \le 39$. However, when $n = 40, 40^2 + 40 + 41 = 40(40 + 1) + 41$ is divisible by $41$, and certainly when $n = 41, 41^2 + 41 + 41$ is clearly divisible by $41$.</p>
    <p>The incredible formula $n^2 - 79n + 1601$ was discovered, which produces $80$ primes for the consecutive values $0 \le n \le 79$. The product of the coefficients, $-79$ and $1601$, is $-126479$.</p>
    <p>Considering quadratics of the form:</p>
    <blockquote>
    $n^2 + an + b$, where $|a| &lt; 1000$ and $|b| \le 1000$<br><br><div>where $|n|$ is the modulus/absolute value of $n$<br>e.g. $|11| = 11$ and $|-4| = 4$</div>
    </blockquote>
    <p>Find the product of the coefficients, $a$ and $b$, for the quadratic expression that produces the maximum number of primes for consecutive values of $n$, starting with $n = 0$.</p>
    */

    std::string operator()(int a, int b);

    std::string operator()();
};

class Problem0028 {
public:
    /*
    * Number Spiral Diagonals
    <p>Starting with the number $1$ and moving to the right in a clockwise direction a $5$ by $5$ spiral is formed as follows:</p>
    <p class="monospace center"><span class="red"><b>21</b></span> 22 23 24 <span class="red"><b>25</b></span><br>
    20  <span class="red"><b>7</b></span>  8  <span class="red"><b>9</b></span> 10<br>
    19  6  <span class="red"><b>1</b></span>  2 11<br>
    18  <span class="red"><b>5</b></span>  4  <span class="red"><b>3</b></span> 12<br><span class="red"><b>17</b></span> 16 15 14 <span class="red"><b>13</b></span></p>
    <p>It can be verified that the sum of the numbers on the diagonals is $101$.</p>
    <p>What is the sum of the numbers on the diagonals in a $1001$ by $1001$ spiral formed in the same way?</p>
    */

    /// <summary>
    /// Returns the sum of the diagonals of a rectangular spiral with uneven dimension, e.g. 5x5.
    /// </summary>
    /// <param name="spiralDimension"></param>
    /// <returns></returns>
    std::string operator()(long long spiralDimension);

    std::string operator()();
};