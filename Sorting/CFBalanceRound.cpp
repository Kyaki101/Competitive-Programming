#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<ll> vec;
using namespace std;

int n;
int dif;
vec nums;

void sol(){
    cin >> n >> dif;
    nums.assign(n, 0);
    for(int i = 0; i < n; i ++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    ll counter = 1;
    ll res = 0;
    for(int i = 1; i < n; i++){
        if(abs(nums[i] - nums[i - 1]) > dif){
            res = max(counter, res);
            counter = 1;
        }
        else counter ++;
    }
    res = n - max(counter, res);
    cout << res << '\n';
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
