/*
*https://codeforces.com/problemset/problem/1873/A
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    string s;
    cin >> s;
    string t = "abc";
    int counter = 0;
    for(int i = 0; i < 3; i++){
        if(s[i] == t[i]) counter ++;
    }
    if(counter == 0)cout << "NO\n";
    else cout << "YES\n";
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

