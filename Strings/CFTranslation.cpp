/*
https://codeforces.com/problemset/problem/41/A
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    if(a == b){std::cout << "YES\n"; return;}
    std::cout << "NO\n";
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