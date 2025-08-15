/*
    author: Rishi Mohan Jha
    created_at: 15-08-2025  11:15 PM
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
	int n, q;
	cin >> n >> q;

	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<ll> x(q);
	for (int i = 0; i < q; i++) {
		cin >> x[i];
	}

	vector<int> f(31, INT_MAX); // storing min index 
	for(int i=0; i<q; i++){
		f[x[i]] = min(i, f[x[i]]);
	}

	vector<pair<int,int>> t;
	for(int i=0; i<31; i++){
		if(f[i] != INT_MAX){
			t.pb({f[i], i});
		}
	}

	sort(all(t));

	// debug(f);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < sz(t); j++) {
			if (a[i] % (1LL << t[j].ss) == 0) {
				a[i] += (1LL << (t[j].ss - 1));
			} 
		}
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  int T = 1;
	cin >> T;
	while (T--) Solve();
}
