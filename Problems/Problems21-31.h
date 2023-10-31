#pragma once
#include <numeric>
#include <fstream>
#include "Utils.h"

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