/*
*https://codeforces.com/contest/1992/problem/C
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    ll n, m, k;
    cin >> n >> m >> k;
    ll i = n;
    while(i > m){
        cout << i << " ";
        i --;
    }
    int j = 1;
    while(j <= i){
        cout << j << " ";
        j ++;
    }

    cout << endl;
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

