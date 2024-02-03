/*
https://codeforces.com/problemset/problem/1915/E
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

int n;

unordered_set<ll> finder;

vector<ll> nums;

vector <ll> acum;

void genAcum(){
    for(int i = 0; i < n; i++){
        if(!(i & 1)){
            acum.push_back(nums[i] + acum[i]);
        }
        else{
            acum.push_back((nums[i] * -1) + acum[i]);
        }
    }
}

void sol(){
    cin >> n;
    nums.assign(n, 0);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    acum.assign(1, 0);
    genAcum();
    sort(acum.begin(), acum.end());
    for(int i = 0; i < n; i++){
        if(acum[i + 1] == acum[i]){
            cout << "YES\n";
            return;
        }

    }
    cout << "NO\n";
    return;
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