/*
https://codeforces.com/problemset/problem/1475/A
*/
#include <bits/stdc++.h>


typedef unsigned long long int ll;
typedef std::vector<ll> vec;
using namespace std;

void sol(){
    ll n;
    cin >> n;
    if((n & (n - 1)) == 0){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
              
    ll t;
    cin >> t;
    while(t--){
        sol();
    }


    return 0;
}