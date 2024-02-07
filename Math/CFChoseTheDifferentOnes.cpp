/*
https://codeforces.com/contest/1927/problem/C
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

int a[200001];

int b[200001];

void sol(){
    int n, m, k;
    cin >> n >> m >> k;
    set<int> as;
    set<int> bs;
    int p;
    for(int i = 0; i < n; i++){
        cin >> p;
        as.insert(p);
    }
    for(int i = 0; i < m; i++){
        cin >> p;
        bs.insert(p);
    }
    for(int i = 1; i <= k; i++){
        if (!as.count(i) && !bs.count(i)) {
            cout << "NO\n"; return;
        }
    }
    int aCounter = 0, bCounter = 0;
    for(int i = 1; i <= k; ++i) {
        if (!as.count(i)){
            bCounter ++;
        }
        if(!bs.count(i)){
            aCounter ++;
        }
        if(aCounter > (k >> 1) || bCounter > (k >> 1)){
            cout << "NO\n"; return;
        }
    }
    cout << "YES\n";
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