/*
*https://codeforces.com/problemset/problem/61/A
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    string s, b;
    cin >> s >> b;
    for(int i = 0; i < s.size(); i++){ 
        if(s[i] == b[i]){ 
            cout << 0;
        }
        else cout << 1;
    }
    cout << '\n';
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

