/*
*https://codeforces.com/problemset/problem/469/A
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    int a, b;
    cin >> a;
    vec p(a);
    for(int i = 0; i < a; i++){
        cin >> p[i];
    }
    cin >> b;
    vec q(b);
    for(int i = 0; i < b; i++){
        cin >> q[i];
    }
    vector<bool> vis(n, false);
    for(int i = 0; i < a; i++){
        vis[p[i] - 1] = true;
    }
    for(int i = 0; i < b; i++){
        vis[q[i] - 1] = true;
    }
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            cout << "Oh, my keyboard!\n";
            return;
        }
    }
    cout << "I become the guy.\n";
    
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

