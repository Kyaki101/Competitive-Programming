/*
*https://codeforces.com/problemset/problem/1472/B
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    vec a(n);
    ll res = 0;
    int one = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        res += a[i];
        if(a[i] == 1){
            one = 1;
        }
    }
    if(res & 1){
        cout << "NO\n";
        return;
    }
    if(one == 1){
        cout << "YES\n";
        return;
    }
    if(n & 1){
        cout << "NO\n";
        return;
    }
    cout <<"YES\n";

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

