/*
https://codeforces.com/contest/1941/problem/B
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<ll> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    vec a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n - 2; i++){
        if(a[i] < 0) break;
        int tmp = a[i];
        a[i] -= tmp;
        a[i + 2] -= tmp;
        a[i + 1] -= tmp * 2;
    }
    for(int i = 0; i < n; i++){
        if(a[i] != 0){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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