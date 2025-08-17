
/*
	State
	======
	dp[i][w] = max value that we can get using first ith elements such that the allowed capacity is 'w'

	Transition
	==========
	dp[i][w] = dp[i-1][w]               # not take
	dp[i][w] = dp[i-1][w-h[i]] + p[i]   # take
	
	take maximum of both

	Points
	==========
	=> standard Knapsack problem

	Internalization
	===============
*/

#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int INF = 1e9 + 7;


int main() {
	int n, x;
	cin >> n >> x;

	vector<int> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	vector<int> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	vector<vector<int>> dp(n + 1, vector<int> (x + 1, 0));

	for (int i = 1; i <= n; i++) {     // till index i
		for (int w = 0; w <= x; w++) { // allowed weight is w

			dp[i][w] = max(dp[i - 1][w], (w - h[i-1] >= 0 ? dp[i - 1][w - h[i-1]] + s[i-1] : 0));
			//              -----------                    -------------------------------
			//              not take                             take  
		}
	} 

	cout << dp[n][x] << endl;
}