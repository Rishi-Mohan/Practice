/*
    author: Rishi Mohan Jha
    created_at: 14-08-2025  09:29 PM
*/

/*
	Pattern : Greedy, Bruteforce
	Idea :  All max elements needs to be covered in the selected row and columns then answer is mx - 1
			else ans will be mx;

			to check that, use map to store cnt of max element in the particular row and colums

			then try each (r,c) combination possible, cnt of max_element is important
*/




#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

#define ll     long long
#define ff     first
#define ss     second
#define pb     push_back
#define sz(x)  ((int)(x).size())
#define all(a) (a).begin(),(a).end()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}


void Solve() {
	int n, m;
	cin >> n >> m;

	int mx = 0;
	vector<vector<int>> v(n, vector<int> (m, 0));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> v[i][j];
			mx = max(mx, v[i][j]);
		}
	}
	int cnt_mx = 0;
	map<int, int> row, col;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(v[i][j] == mx){
				row[i] += 1;
				col[j] += 1;
				cnt_mx += 1;
			}
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(row[i] + col[j] - (v[i][j] == mx) == cnt_mx){
				cout << mx - 1 << endl;
				return;
			}
		}
	}
	cout << mx << endl;
}

int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);  int T = 1;
      cin >> T;
      while (T--) Solve();
}
