/**
 * => x > 0 and y > 0 so x^y < x and x^y < y
 * => if d < n and d is divisor then d <= (n / 2)
 * 
 * FACT 
 * ==========================
 * => two number x and y
 *      if y >= 2x then (x^y) will never be the divisor of x or y.
 */
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin >> t;
    while(t--){
        ll x, m;
        cin >> x >> m;

        int cnt = 0;
        for(ll y = 1; y <=  m; y++){
            if(((x ^ y) % x == 0) || ((x ^ y) % y == 0)){
                cnt += 1;
            }
        }
        cout << cnt << endl;
    }
}