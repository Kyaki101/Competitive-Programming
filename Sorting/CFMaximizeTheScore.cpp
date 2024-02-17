/*
https://codeforces.com/contest/1930/problem/A
*/
#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

bool comp(int a, int b){
    return a > b;
}



void sol(){
    int n;
    cin >> n;
    vec a(2 * n, 0);
    for(int i = 0; i < 2 * n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end(), comp);
    ll sum = 0;
    for(int i = 1; i < n * 2; i += 2){
        sum += a[i];
    }
    cout << sum << '\n';

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