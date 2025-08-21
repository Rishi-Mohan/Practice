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

int N = 200100;

void Solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];

    vector<vector<ll>> dp(n, vector<ll>(n,0));    
    
    for(int len = 1; len <=n; len++){
        for(int l = 0; l + len - 1 <n; l++){
            int r = l + len - 1;
            ll res = 0;
            // interval [l, r]
            for(int i = l; i<=r; i++){
                ll coins = abs(v[i]);
                if(v[i] < 0){
                    // remove suffix from [i,r]
                    if(i-1>=l)
                        coins += dp[l][i-1];
                }else{
                    // remove prefix from[l, i]
                    if(i + 1 <= r)
                        coins += dp[i+1][r];
                }
                res = max(res, coins);
            }
            dp[l][r] = res;
        }
    }
    cout << dp[0][n-1] << endl;
}

int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);  int T = 1;
      cin >> T;
      while (T--) Solve();
}

I am having a working experience of 1.7 years as a frontend engineer at ford, where my day to day work revolve around the official ford website for the 7 market. My Project name was Re-imagine where i worked on the components newly designed and later shipped to the production. Technology that i used is React Js,  javascript HTML and CSS.

Yes, I am comfortable with this type of job because i am having a industry experience to answer the questions and i understand the technology better. And with my experience i exactly know what user wants as a answer for a particular questions and i think it will help me when i will provide the feedback.

Yes, i am comfortable with coding challenges because i have a experience of solving more than 2000+ algorithmic challenges, and also i had participated in more than 300+ contests organised by Google, Meta, Codeforces, Codechef, Leetcode, etc. 

I have a 2 years of experience in JavaScript and 6 month experience in TS.
For JavaScript, i will rate myself 3/5 and for Typescript 2/5.

English - Advanced
English - Intermediate