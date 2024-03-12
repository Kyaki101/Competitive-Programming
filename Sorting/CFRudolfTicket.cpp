/*
https://codeforces.com/contest/1941/problem/A
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<ll> vec;
using namespace std;


int finder(ll val, int test, vec & c){
    for(int i = 0; i < c.size(); i++){
        if(c[i] + test > val){
            return i;
        }
    }
    return c.size();
}

void sol(){
    ll n, m, k;
    cin >> n >> m >> k;
    vec b(n);
    vec c(m);
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < m; i++){
        cin >> c[i];
    }
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    ll res = 0;
    for(int i = 0; i < n; i++){
        if(b[i] < k){
            res += finder(k, b[i], c);
        }
    }
    cout << res << '\n';
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