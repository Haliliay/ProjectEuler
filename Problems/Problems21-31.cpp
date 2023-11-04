#include "Problems21-31.h"

long long Problem0021::operator()(long long n)
{
	long long amicableSum = 0;
	std::vector<bool> isEvaluated(n, false);
	for (long long a = 2; a < n; a++) {
		// Skip amicable pairs
		if (isEvaluated[a])
			continue;

		isEvaluated[a] = true;
		auto divisorsA = hu::divisorsProperOf(a);
		auto b = std::accumulate(divisorsA.begin(), divisorsA.end(), 0);
		auto divisorsB = hu::divisorsProperOf(b);
		auto sumB = std::accumulate(divisorsB.begin(), divisorsB.end(), 0);

		if (a == sumB && a != b) {
			amicableSum += a;

			// Add amicable pair only if it is below n.
			if (b < n) {
				isEvaluated[b] = true;
				amicableSum += b;
			}
		}
		hu::printProgress(a, n);
	}
	return amicableSum;
}

long long Problem0021::operator()()
{
	return operator()(10000);
}


long long Problem0022::operator()(std::string filename)
{
	using namespace std;

	vector<string> names{};
	ifstream File (filename);
	string line;
	// We know that the file has all names in a single line so we don't need a loop.
	// No other error handling needed than the if check.
	if (getline(File, line)) {
		names = hu::split(line, ',');
	}
	File.close();

	// Remove double quotes from the names
	for (auto& name : names) {
		name = name.substr(1, name.size() - 2);
	}

	// Sort the names
	auto compar = [](string a, string b) -> int { return a.compare(b); };
	hu::quickSort<string>(names, compar);

	// Calculate name score and sum them up.
	long long scoreSum = 0;
	for (int i = 1; i <= names.size(); i++) {
		scoreSum += alphabeticalScore(names[i - 1]) * i;
	}

	return scoreSum;
}

long long Problem0022::operator()()
{
	return operator()("data/p0022.txt");
}

int Problem0022::alphabeticalScore(char ch) const
{
	return toupper(ch) - 'A' + 1;
}

int Problem0022::alphabeticalScore(const std::string& word)
{
	int sum = 0;
	for (char c : word)
		sum += alphabeticalScore(c);
	return sum;
}


long long Problem0023::operator()() {
	using namespace std;
	int abundantUpperLimit = 28124;
	// Find all abundant numbers below abundantUpperLimit - 12
	string abundantsPath = "data/p0023_abundants.txt";
	auto abundants = hu::readIntsFromFile(abundantsPath, ' ');
	if (abundants.size() == 0) {
		// Calculate and save to file for later
		abundants = abundantNumsBelowN(abundantUpperLimit - 12);
		hu::writeIntsToFile(abundants, abundantsPath, ' ');
		cout << endl;
	}

	// Use look-up list to trade minimal space for maximum efficiency
	vector<bool> isAbundant(abundantUpperLimit);
	for (int a : abundants)
		isAbundant[a] = true;

	// Mark all non-abundant pair-sums below abundantUpperLimit
	vector<int> nonAbundantPairSums = {};
	for (int i = abundantUpperLimit; i > 0; i--) {
		// Check if i is sum of 2 abundant numbers
		int j = 0;
		bool isAbundantPair = false;
		// Don't consider impossible pairs
		while (j < abundants.size() && (abundants[j] * 2) <= i) {
			int counterpart = i - abundants[j];
			if (isAbundant[counterpart]) {
				// Found at least 1 pair
				isAbundantPair = true;
				break;
			}
			j++;
		}
		if(!isAbundantPair)
			nonAbundantPairSums.push_back(i);
		hu::printProgress(abundantUpperLimit - i, abundantUpperLimit);
	}

	// Sum the remaining non-abundant integers.
	long long sum = 0;
	for (int i = 0; i < nonAbundantPairSums.size(); i++) {
		sum += nonAbundantPairSums[i];
	}

	return sum;
}

std::vector<int> Problem0023::abundantNumsBelowN(int n)
{
	using namespace std;
	// Save if a number is abundant this way,
	// so it can be checked if n was already tested for.
	static vector<bool> abundantMarks = {false};

	// Check and add missing abundant numbers
	for (int i = abundantMarks.size(); i < n; i++) {
		auto divisors = hu::divisorsProperOf(i);
		long long divSum = accumulate(divisors.begin(), divisors.end(), 0);
		if (divSum > i) {
			abundantMarks.push_back(true);
		}
		else {
			abundantMarks.push_back(false);
		}
		hu::printProgress(i, n);
	}

	// Pick abundant cases
	vector<int> abundants = {};
	for (int i = 0; i < n; i++) {
		if (abundantMarks[i])
			abundants.push_back(i);
	}
	return abundants;
}


std::string Problem0024::operator()() {
	using namespace std;
	vector<int> digits(10);
	iota(digits.begin(), digits.end(), 0);
	auto combination = hu::permSelect(digits, (int)1e6);
	
	return hu::listToString(combination);
}


long long Problem0025::operator()(int digits) {
	using namespace std;
	digits = clamp(digits, 2, 1000);
	ap_uint<4000> fib1 = 1;
	ap_uint<4000> fib2 = 1;
	ap_uint<4000> temp = 1;
	long long counter = 2;
	while (string(fib2).size() < digits) {
		temp = fib2;
		fib2 += fib1;
		fib1 = temp;
		counter++;
		hu::printProgress(string(fib2).size(), digits);
	}
	return counter;
}

long long Problem0025::operator()() {
	return operator()(1000);
}


std::string Problem0026::operator()(long long n)
{
	using namespace std;
	// Keep track of longest cycle
	long long maxCycLen = 0;
	int fractionIndex = 0;
	// ap.hpp only has integers so use integer division for fractional part
	// by setting the numerator to 1e4800
	ap_uint<16384> numer = 1;
	for (int j = 0; j < 15 * 32; j++)
		numer *= (long long)1e10;

	// Loop n fractions
	for (long long i = 2; i < n; i++) {
		// Find cycle in decimal fraction part
		ap_uint<16384> denom = i;
		ap_uint<16384> frac = numer / denom;
		string sFrac = (string)frac;
		string cycle = findNumCycle(sFrac);

		// Compare cycle lengths
		if (cycle.size() > maxCycLen) {
			maxCycLen = cycle.size();
			fractionIndex = i;
		}
		hu::printProgress(i, n);
	}
	// Return longest cycle
	return "Fraction(1/" + to_string(fractionIndex) + ") has a cycle of length " + to_string(maxCycLen) + ".";
}

std::string Problem0026::operator()()
{
	return operator()(1000);
}

std::string Problem0026::findNumCycle(const std::string& s) {
	using namespace std;
	string cycle = "";
	vector<int> digits(10);
	iota(digits.begin(), digits.end(), 0);
	// Loop through digits in search of a repetition
	while (digits.size() > 0) {
		// Find digit
		char c = digits[0] + '0';
		int count = std::count(s.begin(), s.end(), c);

		// Arbitrary minimum repetition amount to avoid != s.end() checks
		if (count > 1) {
			// Take this occurance to the next as a potential cycle
			auto iter = std::find(s.begin(), s.end(), c);
			auto nextIter = find(iter + 1, s.end(), c);
			int offset = iter - s.begin();
			int potCycLen = nextIter - iter;
			string potCyc = s.substr(offset, potCycLen);
			int successesInARow = -1;
			int successLimit = 2;
			// If this isn't a cycle, try to 
			// extend the cycle up to the next occurance of the digit
			while (nextIter != s.end() && potCyc != s.substr(offset + potCycLen, potCycLen)) {
				nextIter = find(nextIter + 1, s.end(), c);
				potCycLen = nextIter - iter;
				potCyc = s.substr(offset, potCycLen);
			}
			// Only try cycles that can be tested for successLimit amount of times
			if (potCycLen < (s.size() / successLimit)) {
				// Count successes in a row
				while (successesInARow < successLimit && potCyc == s.substr(offset, potCycLen)) {
					offset += potCycLen;
					successesInARow++;
				}
				// The cycle repeated enough times.
				// Assume it to be a true cycle and remove the used digits from the pool.
				if (successesInARow == successLimit && cycle.size() < potCycLen) {
					cycle = potCyc;
					auto it = digits.begin();
					while (it != digits.end()) {
						c = *it + '0';
						if (find(cycle.begin(), cycle.end(), c) != cycle.end()) {
							it = digits.erase(it);
						}
						else {
							it++;
						}
					}
					// We already erased digits so skip to the end
					continue;
				}
			}
		}
		if (digits.size() > 0) {
			// Remove this digit that isn't included in any cycles
			digits.erase(digits.begin());
		}
	}
	return cycle;
}


std::string Problem0027::operator()(int aMax, int bMax)
{
	using namespace std;
	// Generate primes
	hu::sievePrimesBelowN(1e6);

	// Test all a and b combinations
	aMax = abs(aMax);
	bMax = abs(bMax);
	long long maxN = 0;
	long long ab = 0, resA = 0, resB = 0;
	
	// Starting at n == 0 all b < 2 are non-prime, no need to evaluate
	for (long long b = 2; b < bMax; b++) {
		// At n == 1 we need a > -b or else the expression is negative, so non-prime
		for (long long a = -b + 1; a < aMax; a++) {
			long long n = 0;
			int sequenceLen = 0;
			auto quadraticExpression = [&](int n)
			{
				return n * n + a * n + b;
			};

			// Only test if sequence is potentially longer
			if (hu::isPrime(quadraticExpression(maxN))) {
				while (hu::isPrime(quadraticExpression(n))) {
					sequenceLen++;
					n++;
				}
			}
			if (n > maxN) {
				maxN = n;
				resA = a;
				resB = b;
			}
		}
		hu::printProgress(b, bMax);
	}

	return "a: " + to_string(resA) + "\nb: " + to_string(resB) + "\na * b = " + to_string(resA * resB);
}

std::string Problem0027::operator()()
{
	return operator()(1000, 1000);
}


std::string Problem0028::operator()(long long spiralDimension)
{
	// Wrong input: Handling
	spiralDimension = std::max(std::abs(spiralDimension), 1LL);

	long long sum = 1;
	long long next = 1;
	for (long long i = 2; i <= spiralDimension; i += 2) {
		// Use the fact that each spiral adds 4 corners with the same 2n gap between numbers
		for (int j = 0; j < 4; j++) {
			next += i;
			sum += next;
		}
	}
	return std::to_string(sum);
}

std::string Problem0028::operator()()
{
	return operator()(1001);
}


std::string Problem0029::operator()(int a, int b)
{
	using namespace std;
	// Sorting is mentioned, but no sorting is needed for the solution
	set<string> powers = {};
	for (int i = 2; i <= a; i++) {
		for (int j = 2; j <= b; j++) {
			// Need at most 201 digits for pow(100, 100)
			ap_uint<1024> aPowB = i;
			// Pow function
			for (int k = 1; k < j; k++) {
				aPowB *= i;
			}
			powers.emplace((string)aPowB);
		}
	}

	return to_string(powers.size());
}

std::string Problem0029::operator()()
{
	return operator()(100, 100);
}


std::string Problem0030::operator()()
{
	using namespace std;
	long long sum = 0;
	// Naively test all 6 digit numbers
	for(int i = 3; i < 9; i++){
		auto numbers = nDigitCombinationPowers(i);
		sum = accumulate(numbers.begin(), numbers.end(), sum);
	}
	return to_string(sum);
}

std::vector<long> Problem0030::nDigitCombinationPowers(int index)
{
	std::vector<long> powers = {};
	std::vector<int> digits(index, 0);

	// Starting loop
	for (digits[index - 1] = 0; digits[index - 1] <= 9; digits[index - 1]++) {
		// Nested loops
		nDigitCombinationPowers(index - 2, digits, powers);
	}
	return powers;
}

void Problem0030::nDigitCombinationPowers(int index, std::vector<int>& digits, std::vector<long>& powers)
{
	using namespace std;
	for (digits[index] = digits[index + 1]; digits[index] <= 9; digits[index]++) {
		if (index == 0) {
			// Arrived at last nested loop, execute code
			long number = 0;
			string sDigits = "";
			for (int i = 0; i < digits.size(); i++) {
				number += std::pow(digits[i], 5);
				sDigits += to_string(digits[i]);
			}
			if (hu::isAnagram(to_string(number), sDigits))
				powers.push_back(number);
		}
		else {
			// Start another nested digit loop
			nDigitCombinationPowers(index - 1, digits, powers);
		}
	}
}


std::string Problem0031::operator()(int n)
{
	using namespace std;
	const static vector<int> coins = { 1, 2, 5, 10, 20, 50, 100, 200 };
	static vector<long long> waysToMakeCoinSum = { 1 };		// base: There is 1 way to make 0 pence.
	if (waysToMakeCoinSum.size() < n + 1)
		waysToMakeCoinSum.resize(n + 1, 0);
	
	// Accumulate ways to make a sum with only the smallest coin
	// then with the smallest two coins etc.
	for (int i = 0; i < coins.size(); i++) {
		// Start at sum index of coin value 
		for (int tempSum = coins[i]; tempSum <= n; tempSum++) {
			// Add amount of ways it is possible to make this tempSum
			// using the i-th coin, by adding the ways it is possible
			// to get to the tempSum without this coin.
			waysToMakeCoinSum[tempSum] += waysToMakeCoinSum[tempSum - coins[i]];
		}
	}

	return to_string(waysToMakeCoinSum[n]);
}

std::string Problem0031::operator()()
{
	return operator()(200);
}