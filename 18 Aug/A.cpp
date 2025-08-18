/*
    author: Rishi Mohan Jha
    created_at: 18-08-2025  08:16 PM
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
	int n; char ch;
	cin >> n >> ch;

	string s;
	cin >> s;
	s += s;

	vector<int> ind;
	for(int i=0; i<2*n; i++){
		if(s[i] == 'g')
			ind.pb(i);
	}


	int ans = 0; int r = 0;
	while(r < 2*n){
		if(s[r] == ch){
			if(ch == 'g'){
				break;
			}
			int i = upper_bound(ind.begin(), ind.end() , r) - ind.begin();
			if(i == sz(ind)) break;
			ans = max(ans, ind[i] - r);
			r = ind[i];

		}
		r += 1;
	}
	cout << ans << endl;
}
int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);  int T = 1;
      cin >> T;
      while (T--) Solve();
}
