#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

// 1 based indexing
// struct tree{
// 	int n;
// 	vector<int> bit;

// 	void init(vector<int> &v){
// 		n = v.size();
// 		bit.resize(n+1, 0);
// 	}

// 	void add(int i, int val){
// 		i += 1;
// 		while(i <= n){
// 			bit[i] += val;
// 			i += i & -i;
// 		}
// 	}

// 	int sum(int i){
// 		i += 1;
// 		int s = 0;
// 		while(i > 0){
// 			s += bit[i];
// 			i -= i & -i;
// 		}
// 		return s;
// 	}
// };

void Solve(){
	int n;
	cin >> n;

	vector<pair<int,int>> v(n);

	for(int i=0; i<n; i++){
		cin >> v[i].first >> v[i].second;
	}
	// coordinate compressing
	vector<int> c(n);
	iota(c.begin(), c.end(), 0);
	sort(c.begin(), c.end(),[&](int x, int y){
		return v[x].second < v[y].second;
	});
	for(int i=0; i<n; i++){
		v[c[i]].second = i;
	}

	sort(c.begin(), c.end(), [&](int i, int j){
		return v[i].first < v[j].first;
	});

	debug(v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  int T = 1;
	cin >> T;
	while (T--) Solve();
}
