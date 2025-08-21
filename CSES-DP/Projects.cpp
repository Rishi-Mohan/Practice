/*
	State
	======
    dp[i] = maximum money that we can have at the end of the ith end date

	Transition
	==========
    dp[i] = dp[i-1]              // not take
    dp[i] = dp[ind] + v[i].money // take the current index 
                                 // aisa 'ind' find karenge jo ki current index ka starting point sa pehla end hota ho
	dp[i] = max of take and not take
    
    Points
	==========
    => Weighted Interval Scheduling variation
    => -1 we are doing because we can't start from the same index from where the interval is ending
    => 1 based indexing prefered here

	Problems
	===============
    1. https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/
    2. https://leetcode.com/problems/maximum-earnings-from-taxi/description/
    3. https://leetcode.com/problems/two-best-non-overlapping-events/description/
    4. https://leetcode.com/problems/maximum-score-of-non-overlapping-intervals/description/
    5. https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/description/
    6. https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/description/
    
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
const int M = 1e9 + 7;
const int INF = 1e9 + 7;
 
struct ds {
    int s, e, w;
};
 
int main() {
    int n;
    cin >> n;
 
    vector<ds> v(n+1);
    for(int i=1; i<=n; i++){
        cin >> v[i].s >> v[i].e >> v[i].w;
    }
 
    // sorting based on the end time of the interval
    sort(v.begin(), v.end(), [&](const ds &a, const ds &b){
        return a.e < b.e;
    });
 
    // storing separtely the end time so that we can apply lower bound in the endtime
    vector<int> times(n + 1);
    for(int i=1; i<=n; i++)
        times[i] = v[i].e;
 
    vector<ll> dp(n + 1, 0);
 
    for(int i = 1; i <= n; i++){
        // Find last project that ends before current project's start
        int ind = lower_bound(times.begin(), times.end(), v[i].s) - times.begin() - 1;
 
        dp[i] = max(dp[i-1], dp[ind] + v[i].w); // either not take or take the current element 
    }   
 
    cout << dp[n] << endl;
}