/*
	State
	======
	dp[n] = min number of steps to get n

	Transition
	==========
	dp[x] = min(dp[x], dp[x-digit_of_x] + 1) for all digits of x

	_ _ _ _ _ _ _ _ _ _ _ _ _ 
	                x

	Points
	==========


	Internalization
	===============
*/

#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int INF = 1e9 + 7;


int main() {
	int n;
	cin >> n;

	vector<int> dp(n + 1, INF);

	dp[0] = 0;

	for (int i = 1; i <= n; i++) {
		for (char d : to_string(i)) {
			int digit = d - '0';
			dp[i] = min(dp[i], dp[i - digit] + 1);
		}
	}

	cout << dp[n] << endl;
}