/*
State :
	dp[s] = number of ways to get the sum 's' by throwing a dice

Transition:
	dp[s] = dp[s-1] + dp[s-2] + dp[s-3] + dp[s-4] + dp[s-5] + dp[s-6];  # make sure of validation

Points :
 => To get the sum 's' we can add 1 to s-1 and we get the number of ways. [ dp[s-1] + 1 = dp[s] from value 1]

Internalization :
 => instead of dice if vector is given instead of dice then also we can loop over. 
*/

#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int main() {
	int n;
	cin >> n;

	vector<int> dp(n + 1);

	dp[0] = 1; // for sum s = 0, 1 way possible

	for (int s = 1; s <= n; s++) {
		for (int i = 1; i <= 6; i++) {
			if (s - i >= 0)
				dp[s] = (dp[s] + dp[s - i]) % M;
		}
	}
	cout << dp[n] << endl;
}


/*
	State
	======


	Transition
	==========


	Points
	==========


	Internalization
	===============
*/

#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int INF = 1e9 + 7;


int main(){

}