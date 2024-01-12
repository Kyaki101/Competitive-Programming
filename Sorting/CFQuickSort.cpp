#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

int n, k;

vec nums;

void sol(){
    cin >> n >> k;
    nums.assign(n, 0);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int counter = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] > i + 1 || abs(nums[i] - (i + 1)) < counter){
            counter ++;
        }
    }
    if(counter % k){cout << (counter / k) + 1 << '\n'; return;}
    cout << counter / k << '\n';
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