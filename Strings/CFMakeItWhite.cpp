/*
https://codeforces.com/contest/1927/problem/A
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
    bool prim = false;
    int x = 0;
    int y = 0;
    for(int i = 0; i < n; i++){
        if(!prim && s[i] == 'B'){
            prim = true;
            x = i;
            y = i;
        }
        else if(s[i] == 'B'){
            y = i;
        }
    }
    y ++; x++;
    cout << y - x + 1 << '\n';
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