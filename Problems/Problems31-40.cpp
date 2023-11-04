#include "Problems31-40.h"

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