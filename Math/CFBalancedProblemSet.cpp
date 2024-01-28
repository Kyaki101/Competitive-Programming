//https://codeforces.com/problemset/problem/1925/B

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    ll x, n;
    cin >> x >> n;
    ll ans = 1;
    for(ll i = 1; i*i <= x; i++){
        if(x % i == 0){
            if(n * i <= x){
                ans = max(ans, i);
            }
            if(n <= i){
                ans = max(ans, x / i);
            }

        }
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
              
    int t;
    cin >> t;
    while(t--){
        sol();
    }


    return 0;
}