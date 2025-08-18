/*
    author: Rishi Mohan Jha
    created_at: 18-08-2025  08:29 PM
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
	ll n, k;
	cin >> n >> k;

	vector<ll> v(n);
	vector<ll> pre(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(all(v));

	for(int i=0; i<n; i++){
		pre[i] = (i - 1 >= 0 ? pre[i - 1] : 0) +  v[i];
	}
	// debug(v);
	ll ans = 0;
	for (int i = 0; i <= k; i++) {
		int s = 2 * i;
		int e = n - (k - i + 1);

		ans = max(ans, pre[e] - ((s - 1) >= 0 ? pre[s - 1] : 0));
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  int T = 1;
	cin >> T;
	while (T--) Solve();
}
