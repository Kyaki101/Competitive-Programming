/*
https://codeforces.com/contest/1918/problem/B
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

vec a, b;
vec va, vb;

ll gauss(int n){
    return (n * (n + 1)) / 2;
}

void sol(){
    int n;
    cin >> n;
    a.assign(n, 0);
    b.assign(n, 0);
    unordered_map<ll, ll> linker;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n; i++){
        linker[a[i]] = b[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        if(i == n - 1)cout << a[i] << '\n';
        else{cout << a[i] << " ";}
    }
    for(int i = 0; i < n; i++){
        if(i == n - 1)cout << linker[a[i]] << '\n';
        else{cout << linker[a[i]] << " ";}
    }

    
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