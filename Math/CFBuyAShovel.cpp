/*
https://codeforces.com/problemset/problem/732/A
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n, b;
    cin >> n >> b;
    for(int i = 1; i < 11; i++){
        if((n * i) % 10 == b || (n * i) % 10 == 0){
            cout << i << '\n';
            return;
        }
    }
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