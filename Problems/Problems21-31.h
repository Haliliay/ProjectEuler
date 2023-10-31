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