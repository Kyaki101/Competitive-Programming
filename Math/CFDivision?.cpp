/*
https://codeforces.com/problemset/problem/1669/A
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    ll n;
    cin >> n;
    if(n <= 1399){
        cout << "Division 4\n";
        return;
    }
    if(n >= 1400 && n <= 1599){
        cout << "Division 3\n";
        return;
    }
    if(n >= 1600 && n <= 1899){
        cout << "Division 2\n";
        return;
    }
        if(n >= 1900){
        cout << "Division 1\n";
        return;
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