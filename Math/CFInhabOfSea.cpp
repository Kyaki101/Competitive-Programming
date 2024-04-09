/*
*
*https://codeforces.com/contest/1955/problem/C
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    ll n, k;
    cin >> n >> k;
    vector<ll> attacks(n);
    for(int i = 0; i < n; i++){
        cin >> attacks[i];
    }
    ll left;
    ll right;
    if(k & 1){
        left = (k / 2) + 1;
        right = (k / 2);
    }
    else{
        left = (k / 2);
        right = (k / 2);
    }
    int counter = 0;
    for(int i = 0; i < n && left > 0; i++){
        if(left >= attacks[i]){
            left -= attacks[i];
            counter ++;
            attacks[i] = 0;
        }
        else{
            attacks[i] -= left;
            left = 0;
        }
    }
    for(int i = n - 1; i >= 0 && right >= attacks[i] && attacks[i] > 0; i--){
        counter ++;
        right -= attacks[i];
    }
    cout << counter << endl; 
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

