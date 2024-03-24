/*
https://codeforces.com/problemset/problem/758/A
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    vec a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int maxi = -1;
    for(int i = 0; i < n; i++){
        maxi = max(maxi, a[i]);
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        res += abs(maxi - a[i]);
    }
    cout << res << endl;
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