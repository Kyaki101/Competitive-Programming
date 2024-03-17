/*
https://codeforces.com/problemset/problem/1409/A
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n, m;
    cin >> n >> m;
    ll dif = abs((n / 10) - (m/10));
    int mini = min(n, m);
    int maxi = max(n, m);
    if(mini%10 >= maxi % 10){
        cout << dif << endl;
        return;
    }
    cout << dif + 1 << endl;
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