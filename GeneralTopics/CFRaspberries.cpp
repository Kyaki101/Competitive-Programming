/*
*Author: EmmanuelRojas
*Site: CodeForces
https://codeforces.com/problemset/problem/1883/C
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<ll> vec;
using namespace std;

ll n, k;

vec nums;

void sol(){
    cin >> n >> k;
    nums.assign(n, 0);
    ll prod = 1;
    ll evens = 0;
    ll odds = 0;
    for(ll i = 0; i < n; i++){
        cin >> nums[i];
        prod*= nums[i];
        if(nums[i] & 1)odds ++;
        else evens ++;
    }
    ll maxima = -1;

    for(ll i = 0; i < n; i++){
        if(nums[i] % k == 0){cout << "0\n"; return;}
        maxima = max(maxima, nums[i] % k);
    }
    if(k == 4){
        if(evens >= 2){cout << "0\n"; return;}
        if(evens == 1){cout << "1\n"; return;}
        if(abs(k - maxima) == 1){cout << "1\n"; return;}
        if(evens == 0){cout << "2\n"; return;}
    }
    cout << abs(k - maxima) << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
              
    ll t;
    cin >> t;
    while(t--){
        sol();
    }


    return 0;
}