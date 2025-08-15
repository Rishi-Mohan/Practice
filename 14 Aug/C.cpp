/*
    author: Rishi Mohan Jha
    created_at: 15-08-2025  05:42 PM

    Topic : Greedy
    Idea : Permutation form a cycle so we need to try only min(n, k) times
    		What is the value if we stay in the current element for the rest of the moves left ?
    	
    		total sum  = stay in the current element for the rest + sum that we acheived from the previous moves
			
			we need to try out for the all possible moves.

			initial : stay in the current element for the all k moves
					  curr element(move to next) + stay in the next moves for the (k-1)moves
					  curr element(move to next of next) + stay in the next of next for (k-2) moves

					 .
					 .
					 .
			max of all states will be the answer
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

ll get(vector<int> &p, vector<int> &a, int k, int ind) {
	ll sum = 0, ans = 0;
	for (int i = 0; i < min(sz(p), k); i++) {
		ans = max(ans, 1LL * (k - i) * a[ind] + sum); // if stay at current index for rest of the moves + previous moves result
		sum += a[ind];
		ind = p[ind];
	}
	return ans;
}


void Solve() {
	int n, k, pb, ps;
	cin >> n >> k >> pb >> ps;
	pb--;
	ps--;

	vector<int> p(n);
	for (int i = 0; i < n; i++){
		cin >> p[i];
		p[i] -= 1;
	}

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	ll Pb = get(p, a, k, pb);
	ll Ps = get(p, a, k, ps);

	if (Pb > Ps) {
		cout << "Bodya" << endl;
		return;
	}
	if (Pb < Ps) {
		cout << "Sasha" << endl;
		return;
	}
	cout << "Draw" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  int T = 1;
	cin >> T;
	while (T--) Solve();
}
