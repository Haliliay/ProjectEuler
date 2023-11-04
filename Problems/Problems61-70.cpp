#include "Problems61-70.h"


std::string Problem0061::operator()()
{
	// Calculate all 4-digit figurate numbers as strings
	// Store as map of lists to make it easier to iterate remaining
	// lists
	using namespace std;
	map<int, vector<string>> figurates;
	for (int i = 3; i <= 8; i++) {
		figurates.emplace(i, genFigurates(i, 4));
	}



	return "0";
}

std::vector<std::string> Problem0061::genFigurates(int id, int digits)
{
	using namespace std;
	vector<string> figurates;
	string curNumber = "1";
	long i = 1;
	while (curNumber.size() <= digits) {
		long number = i;
		switch (id) {
		case 3:
			number *= (i + 1);
			number /= 2;
			break;
		case 4:
			number *= i;
			break;
		case 5:
			number *= (3 * i - 1);
			number /= 2;
			break;
		case 6:
			number *= (2 * i - 1);
			break;
		case 7:
			number *= (5 * i - 3);
			number /= 2;
			break;
		case 8:
			number *= (3 * i - 2);
			break;
		default:
			// Return empty list for non-supported figurates
			return figurates;
			break;
		}

		curNumber = to_string(number);
		if (curNumber.size() == digits) {
			figurates.push_back(curNumber);
		}
		i++;
	}
	return figurates;
}


long long Problem0067::operator()(std::string filename) const
{
	return Problem0018()(filename);
}
