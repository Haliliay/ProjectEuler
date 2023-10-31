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
