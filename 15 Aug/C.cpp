/*
	h[i] % h[i+1] == 0
	h[i+1] % h[i+2] == 0

	12 6 3
*/

/*
    author: Rishi Mohan Jha
    created_at: 15-08-2025  10:53 PM
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

int n, k;
vector<int> a(200005), h(200005);

int solve(int x, int y){
	int ans = 0, sum = 0, l = x;
	for(int r = x; r <= y; r++){
		sum += a[r];
		while(sum > k){
			sum -= a[l++];
		}
		ans = max(ans, r - l + 1);
	}
	return ans;
}

void Solve() {
	cin >> n >> k;


	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	vector<pair<int,int>> p;

	int ans = 0, l = 0, sum = h[0];

	for (int r = 1; r < n; r++) {
		if (h[r - 1] % h[r] != 0) {
			p.pb({l,r-1});
			l = r;			
		}
	}
	p.pb({l, n-1});

	for(auto i : p){
		ans = max(ans, solve(i.first, i.second));
	}

	cout << ans << endl;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  int T = 1;
	cin >> T;
	while (T--) Solve();
}
