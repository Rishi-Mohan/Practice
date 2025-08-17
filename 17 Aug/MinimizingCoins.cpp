/*
	State
	-------
	dp[s] = min number of coins to get the sum 's'

	Transition
	-----------
	for all coins available and for each 's'
	dp[s] = if(s - coin[i] >= 0) min(dp[s - coin[i]] + 1, dp[s]);

	Points
	------------
	=> in the minimization problem, default value will be INF

	Internalization
	---------------
*/

#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
	int n, x;
	cin >> n >> x;

	vector<int> c(n);
	for (int i = 0; i < n; i++)
		cin >> c[i];

	vector<int> dp(x + 1, INF);
	dp[0] = 0; // no coins is needed

	for (int s = 1; s <= x; s++) {
		for (int i = 0; i < n; i++) {
			if (s - c[i] >= 0)
				dp[s] = min(dp[s - c[i]] + 1, dp[s]);
		}
	}
	if(dp[x] == INF) cout << "-1" << endl;
	else cout << dp[x] << endl;
}