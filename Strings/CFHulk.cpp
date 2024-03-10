/*
https://codeforces.com/problemset/problem/705/A
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        if(i & 1)cout << "I hate that ";
        else cout << "I love that ";
    }
    if(n & 1)cout << "I hate it\n";
    else cout << "I love it\n";
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