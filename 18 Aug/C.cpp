/*
    author: Rishi Mohan Jha
    created_at: 18-08-2025  09:55 PM
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
	int n;
	cin >> n;

	vector<int> v(n);
	set<int> st;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		st.insert(v[i]);
	}
	// find the mex
	int mex = 0;
	for (int i = 0; i <= 2e5; i++) {
		if (st.find(i) == st.end()) {
			mex = i;
			break;
		}
	}

	if (mex == 0) {
		cout << "Yes" << endl;
		return;
	}
	st.clear();
	for (int i = 0; i < n; i++) {
		st.insert(v[i] - 1);
	}

	for(int i=0; i<=mex; i++){
		if(st.find(i) == st.end()){
			cout << "No" << endl;
			return;
		}
	}

	cout << "Yes" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  int T = 1;
	cin >> T;
	while (T--) Solve();
}
