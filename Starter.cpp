/*
    author: Rishi Mohan Jha
*/

#include<bits/stdc++.h>
using namespace std;

#define ll     long long
#define ff     first
#define ss     second
#define pb     push_back
#define sz(x)  ((int)(x).size())
#define all(a) (a).begin(),(a).end()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}


void Solve() {}

int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);  int T = 1;
      cin >> T;
      while (T--) Solve();
}
