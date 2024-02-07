/*
https://codeforces.com/contest/1927/problem/B
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    vec a(n, 0);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    vec vis(26, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            if(vis[j] == a[i]){
                vis[j]++;
                cout << (char)(j + 'a');
                break;
            }
        }
    }
    cout << '\n';
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