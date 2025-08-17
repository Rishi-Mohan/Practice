/*
	Base Case
	=========
	dp[0][0] = 1;
	dp[0][1] = 1;

	State
	======
	dp[i][0] => number of ways for the same such that ith position consist of 2 tiles of width 1 each.
	dp[i][1] => number of ways for the same such that ith position consist of 1 tile of width 2.

	Transition
	==========
	dp[i][1] = 2*dp[i-1][1] + dp[i-1][0]
	dp[i][0]=  dp[i-1][1] + 4*dp[i-1][0]

	Answer = dp[n-1][0] + dp[n-1][1]

	Points
	==========


	Internalization
	===============
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int M = 1e9 + 7;
const int INF = 1e9 + 7;

ll add(ll a, ll b) {
	a += b;
	if (a >= M)
		a -= M;
	return a;
}


int main() {
	int t;
	cin >> t;

	// preprocessing
	int N = 1e6 + 5;
	vector<vector<ll>> dp(N + 1, vector<ll>(2, 0LL));
	dp[0][0] = 1;
	dp[0][1] = 1;

	for (int i = 1; i < N; i++) {
		dp[i][0] = add(2LL * dp[i - 1][0], dp[i - 1][1]); dp[i][0] %= M;
		dp[i][1] = add(dp[i - 1][0], 4LL * dp[i - 1][1]); dp[i][1] %= M;
	}

	while (t--) {
		int n;
		cin >> n;

		cout << add(dp[n - 1][0] , dp[n - 1][1]) % M << endl;
	}
}