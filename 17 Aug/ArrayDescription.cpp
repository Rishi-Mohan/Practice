/*
	Base Case
	=========

	dp[i][v[0]] = 1  # if first value is fixed value
	dp[i][x] = 1 # for all x from [1,m] if first value is 0

	State
	======
	dp[i][x] = number of ways to fill [0...i] such that a[i] = x;

	Transition
	==========
	dp[i][x] = dp[i-1][x] + dp[i-1][x-1] + dp[i-1][x+1] # check range for x <= m

	Points
	==========
	=> we can optimize space also, because only last index array matters

	Internalization
	===============
*/

#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int INF = 1e9 + 7;

int add(int a, int b) {
	a += b;
	if (a >= M)
		a -= M;
	return a;
}


int main() {
	int n, m;
	cin >> n >> m;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	vector<vector<int>> dp(n, vector<int> (m + 1));

	// Base case
	if (v[0] == 0) {
		for (int i = 1; i <= m; i++) {
			dp[0][i] = 1;
		}
	} else {
		dp[0][v[0]] = 1;
	}

	// pull dp
	for (int i = 1; i < n; i++) {
		if (v[i] == 0) {
			for (int x = 1; x <= m; x++) {
				dp[i][x] = add(dp[i][x], dp[i - 1][x]);
				if (x - 1 >= 1) dp[i][x] = add(dp[i][x] , dp[i - 1][x - 1]);
				if (x + 1 <= m) dp[i][x] = add(dp[i][x] , dp[i - 1][x + 1]);
			}
		} else {
			dp[i][v[i]] = add(dp[i][v[i]], dp[i - 1][v[i]]);
			if (v[i] - 1 >= 1) dp[i][v[i]] = add(dp[i][v[i]], dp[i - 1][v[i] - 1]);
			if (v[i] + 1 <= m) dp[i][v[i]] = add(dp[i][v[i]], dp[i - 1][v[i] + 1]);
		}
	}


	int ans = 0;
	for (int x = 1; x <= m; x++) {
		ans = add(ans, dp[n - 1][x]);
	}

	cout << ans << endl;
}