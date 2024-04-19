/*
*https://codeforces.com/contest/1951/problem/D
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    ll n, k;
    cin >> n >> k;
    if(k == n){
        cout << "YES\n1\n1\n";
        return;
    }
    if(k > n){
        cout << "NO\n";
        return;
    }
    if(2 * k > n + 1){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << "2\n";
    cout << n - k + 1 << ' ' << "1\n";
    
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

