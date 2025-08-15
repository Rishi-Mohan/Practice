//1 2 3 4 5 6 7 8
/*
	1 2 3 4 5 6 
	1 2 3 4 5 6 7

	1 2 => -1
	1 2 3 => -1
	1 2 3 4 => 2 4 3 1
	1 2 3 4 5 => 2 4 5 3 1
	1 2 3 4 5 6 => 2 4 6 5 3 1
*/

/*
    author: Rishi Mohan Jha
    created_at: 15-08-2025  10:31 PM
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

bool isPrime(int n){
	for(int i=2; i*i<=n; i++){
		if(n % i == 0)
			return 0;
	}
	return 1;
}

void Solve() {
	int n;
	cin >> n;

	vector<int> odd, even;

	for(int i=1; i<=n; i++){
		if(i & 1) odd.pb(i);
		else even.pb(i);
	}

	int ind = -1;
	for(int i=0; i<sz(odd); i++){
		if(!isPrime(odd[i] + even.back())){
			ind = i;
			break;
		}
	}
	if(ind == -1) {
		cout << "-1" << endl;
		return;
	}

	for(int i=0; i<sz(even); i++)
		cout << even[i] << ' ';
	cout << odd[ind] << ' ';
	for(int i=0; i<sz(odd); i+=1){
		if(i != ind)
			cout << odd[i] << ' ';
	}
	cout << endl;
}

int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);  int T = 1;
      cin >> T;
      while (T--) Solve();
}
