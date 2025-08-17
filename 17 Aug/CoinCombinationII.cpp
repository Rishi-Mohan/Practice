/*
	State
	======
	dp[s] = number of ways to create sum 's' using the given coins

	Transition
	==========
	For each coin c and for each sum s from 1 to x:
	If s - c ≥ 0, then dp[s] += dp[s - c]

	Points
	==========
	=> 2D solution is also possible
		dp(x, j) : number of distinct seq having sum 'x' using first 'j' coins
		
		dp(x, j) = dp(x - c[j], j) + dp(x, j - 1)

	Internalization
	===============
*/

#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int INF = 1e9 + 7;


int main() {
	int n, x;n
	cin >> n >> x;

	vector<int> coins(n);
	for (int i = 0; i < n; i++)
		cin >> coins[i];

	vector<int> dp(x + 1);
	dp[0] = 1;

	for (auto c : coins) {
		for (int s = 1; s <= x; s++) {
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