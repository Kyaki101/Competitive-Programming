/*
https://codeforces.com/problemset/problem/520/A
*/
#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vec a(26, 0);
    vec b(26, 0);
    for(int i : s){
        if((int) i > 90){
            a[i - 97] = 1;
        }
        else b[i - 65] = 1;
    }
    for(int i = 0; i < 26; i++){
        if(!a[i] && !b[i]){
            cout << "NO\n"; return; 
        }
    }
    cout << "YES\n"; return;
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