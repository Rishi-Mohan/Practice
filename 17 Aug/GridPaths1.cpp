
/*
	State
	======
	dp[i][j] = number of paths ends at (i, j) started from (0, 0)
	dp[0][0] = 1

	Transition
	==========
	dp[i][j] = (dp[i-1][j] + dp[i][j-1]) if possible to reach index

	Points
	==========
	=> starting (0,0) can be *

	=> create a boundary of * throughout the grid so that it will be helpfull for checking out of bound
	   1 based indexing need to be followed

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

	vector<vector<char>> grid(n + 1, vector<char>(n + 1, '*'));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> grid[i][j];
		}
	}


	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

	if (grid[1][1] == '.') dp[1][1] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (grid[i][j] == '.') {

				if (grid[i - 1][j] == '.')
					dp[i][j] += dp[i - 1][j];

				if (dp[i][j] >= M)
					dp[i][j] -= M;

				if (grid[i][j - 1] == '.')
					dp[i][j] += dp[i][j - 1];

				if (dp[i][j] >= M)
					dp[i][j] -= M;
			}
		}
	}


	cout << dp[n][n] << endl;
}