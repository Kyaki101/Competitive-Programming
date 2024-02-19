/*
https://codeforces.com/problemset/problem/546/A
*/
#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    ll a, b, c;
    cin >> a >> b >> c;
    ll price = (ll)((c*(c+1))/2) * a;
    cout << price - b << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
              
    int t;
    t = 1;
    while(t--){
        sol();
    }


    return 0;
}