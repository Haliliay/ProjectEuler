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
