/*
    author: Rishi Mohan Jha
    created_at: 14-08-2025  08:47 PM
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
	for (int i = 0; i < n; i++)
		cin >> v[i];


	if(v[0] < v[1]){
		cout << 2*v[0] << endl;
	}else{
		cout << v[0] + v[1] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  int T = 1;
	cin >> T;
	while (T--) Solve();
}
