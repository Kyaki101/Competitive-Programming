/*
https://codeforces.com/problemset/problem/96/A
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    string s;
    cin >> s;
    int c = 0;
    char cur = '2';
    for(char i : s){
        if(cur == i){
            c++;
        }
        else{c = 1; cur = i;}
        if(c == 7){
            cout << "YES\n"; return;
        }
    }
    cout << "NO\n";
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