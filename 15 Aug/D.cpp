/*
    author: Rishi Mohan Jha
    created_at: 16-08-2025  11:23 AM
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
    std::cin >> n >> m;
    
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }
    
    std::vector<int> pre(m + 1, n + 1), suf(m + 1, -1);
    pre[0] = 0;
    for (int i = 0, j = 0; i < m; i++) {
        while (j < n && a[j] < b[i]) {
            j++;
        }
        if (j == n) {
            break;
        }
        pre[i + 1] = ++j;
    }
    suf[m] = n;
    for (int i = m - 1, j = n - 1; i >= 0; i--) {
        while (j >= 0 && a[j] < b[i]) {
            j--;
        }
        if (j < 0) {
            break;
        }
        suf[i] = j--;
    }
    
    if (pre[m] <= n) {
        std::cout << 0 << "\n";
        return;
    }
    
    int ans = inf;
    for (int i = 0; i < m; i++) {
        if (pre[i] <= suf[i + 1]) {
            ans = std::min(ans, b[i]);
        }
    }
    if (ans == inf) {
        ans = -1;
    }
    std::cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  int T = 1;
	cin >> T;
	while (T--) Solve();
}

