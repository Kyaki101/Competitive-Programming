/*
https://codeforces.com/problemset/problem/1030/A
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n, k;
    cin >> n;
    for(int i = 0; i< n; i++){
        cin >> k;
        if(k){
            cout << "HARD\n";
            return;
        }
    }
    cout << "EASY\n";
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