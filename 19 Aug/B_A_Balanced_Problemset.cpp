#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
    int x, n;
    cin >> x >> n;

    int ans = 0;
    for(int i=1; i * i <= x; i++){
        if(x % i == 0){
            if((x / i) >= n){
                ans = max(ans, i);
            }

            if(i != (x/i)){
                if(x / (x / i) >= n){
                    ans = max(ans, x/i);
                }
            }
        }
    }
    cout << ans << endl;
    }
}