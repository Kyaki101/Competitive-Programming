/*
*https://codeforces.com/contest/1991/problem/A
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    vec nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int maxi = -1;
    for(int i = 0; i < n; i++, i++){
        maxi = max(maxi, nums[i]);
    }
    cout << maxi << endl;
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

