/*
	State :
	dp[s] = number of ways to get sum 's' using coins given in vector;

	Transition :
	dp[s] = dp[s - coin[0]] + dp[s - coin[1]] + dp[s-coin[2]] + ...  # check validation also

	Points :
	=> dp[a] = (dp[a] + dp[b]) % M  is slower instead prefer

		dp[a] += dp[b];
		if(dp[a] >= M)
			dp[a] -= M;

	Internalization :
	 => same as Dice Combination but with a random values instead of fixed values
*/

#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int main() {
	int n, x;
	cin >> n >> x;

	vector<int> coin(n);
	for (int i = 0; i < n; i++)
		cin >> coin[i];

	vector<int> dp(x + 1);

	dp[0] = 1; // ways to get sum = 0

	for (int s = 1; s <= x; s++) {
		for (auto c : coin) {
			if (s - c >= 0) {
				dp[s] += dp[s - c];
				if (dp[s] >= M) {
					dp[s] -= M;
				}
			}
		}
	}
	cout << dp[x] << endl;

}
