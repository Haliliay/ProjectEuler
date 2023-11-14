#include "Problems61-70.h"


std::string Problem0061::operator()()
{
	using namespace std;
	// Calculate all 4-digit figurate numbers as strings.
	map<int, vector<string>> figurates;
	for (int i = 3; i <= 8; i++) {
		figurates.emplace(i, genFigurates(i, 4));
	}

	// Find cyclic patterns
	// Since all types of figurates must be included:
	// Search from Octogonal to Triangle to eliminate tries faster
	// The pair consists of used IDs and the resulting set
	vector<pair<string, vector<string>>> orderedSets(figurates[8].size());
	for (int i = 0; i < figurates[8].size(); i++) {
		orderedSets[i] = make_pair("8", vector<string>{ figurates[8][i] });
	}

	// Append a fitting figurate until all IDs were considered
	for (int i = 0; i < 5; i++) {
		// temporary copy of orderedSets for multiple reuse
		vector<pair<string, vector<string>>> tempSets = {};
		tempSets.swap(orderedSets);

		// Cannot know which figurate ID was already used so:
		// Try for all possible figurates and filter
		for (int j = 7; j >= 3; j--) {
			auto extendedSets = genSetsFromNextCyclic(tempSets, figurates[j], hu::idtocd(j));
			// Move elements to orderedSets
			orderedSets.insert(
				orderedSets.end(),
				std::make_move_iterator(extendedSets.begin()),
				std::make_move_iterator(extendedSets.end())
			);
		}
	}
	
	// Find the only one where ending matches the beginning
	string result = "";
	for (auto& pair : orderedSets) {
		auto& set = pair.second;
		
		if (hu::isLast2eqFirst2(set.back(), *set.begin(), 2)) {
			long sum = 0;
			result += set[0];
			sum += stoi(set[0]);
			for (int i = 1; i < set.size(); i++) {
				result += ", " + set[i];
				sum += stoi(set[i]);
			}
			result += "\nSum: " + to_string(sum);
			break;
		}
	}
	return result;
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

std::vector<std::pair<std::string, std::vector<std::string>>> Problem0061::genSetsFromNextCyclic(
	const std::vector<std::pair<std::string, std::vector<std::string>>>& orderedSets, 
	const std::vector<std::string>& figurates,
	char fID)
{
	using namespace std;
	vector<pair<string, vector<string>>> result = {};

	for (auto& pair : orderedSets) {
		auto& ids = pair.first;
		auto& set = pair.second;

		// if the figurate pack is not already integrated into the set
		if (find(ids.begin(), ids.end(), fID) == ids.end()) {
			// Look for cyclic continuation
			for (int i = 0; i < figurates.size(); i++) {
				// If ending matches beginning and the figurate is not already part of the set
				if (hu::stri::isLast2eqFirst2(set.back(), figurates[i], 2) 
					&& find(set.begin(), set.end(), figurates[i]) == set.end()) {
					// Add set with extended IDs and next figurate
					result.push_back(make_pair(ids, set));
					result.back().first += fID;
					result.back().second.push_back(figurates[i]);
				}
			}
		}
	}

	return result;
}


std::string Problem0062::operator()(int n)
{
	using namespace std;
	// Map ordered digits of cube numbers to their cube number
	map<string, vector<string>> cubeMap = {};
	string smallestCube = "";

	// Generate cubes
	long long i = 1;
	string lastID = "1";
	while (true) {
		long long cube = pow(i, 3);
		string cubeS = to_string(cube);

		// When a new key with more digits than before is generated
		// it is guaranteed that all possible permutations of the
		// cubes with less digits, that are themselves cubes,
		// have already been found.
		// So check if there is a cube where the amount of permutations is equal to n.
		if (cubeS.size() > lastID.size()) {
			// Look for list with fitting permutations
			vector<vector<string>> cubePerms;
			for (auto& cubePerm : cubeMap) {
				if (cubePerm.second.size() == n) {
					cubePerms.push_back(cubePerm.second);
				}
			}

			// Solutions found
			if (cubePerms.size() > 0) {
				// Find smallest cube
				smallestCube = cubePerms[0][0];
				for (int i = 0; i < cubePerms.size(); i++) {
					string smallestCubeCur = *min_element(cubePerms[i].begin(), cubePerms[i].end());
					smallestCube = min(smallestCube, smallestCubeCur);
				}

				break;
			}

			// Clear map, because all next cubes will have more digits
			// so the previous cubes won't get more permutations.
			// This avoids searching the same cubes again.
			cubeMap.clear();
		}
		// Put the cube in a map according to its ordered digits
		string cubeID = cubeS;
		sort(cubeID.begin(), cubeID.end());
		cubeMap[cubeID].push_back(cubeS);
		lastID = cubeID;
		i++;
		// Status update
		cout << "\ri: " << i;
		cout.flush();
	}
	return smallestCube;
}

std::string Problem0062::operator()()
{
	return operator()(5);
}


std::string Problem0064::operator()(int n)
{
	using namespace std;
	/*
	string result = hu::sqrtContinuedFractionExpansionFormatted(n);
	result += " " + to_string(hu::sqrtContinuedFractionExpansionPeriod(n));
	*/
	int odds = 0;
	for (int i = 0; i <= n; i++) {
		if (hu::sqrtContinuedFractionExpansionPeriod(i) % 2 == 1)
			odds++;
		hu::printProgress(i, n);
	}
	string result = to_string(odds);

	return result;
}

std::string Problem0064::operator()()
{
	return operator()(10'000);
}


long long Problem0067::operator()(std::string filename) const
{
	return Problem0018()(filename);
}

