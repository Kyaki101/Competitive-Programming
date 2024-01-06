#include <bits/stdc++.h>

using namespace std;

typedef std::vector<int> lista;

typedef long long int ll;


ll a;

ll b;

ll c;

lista nums;

void sol(){
    nums.assign(3, 0);
    cin >> nums[0] >> nums[1] >> nums[2];
    sort(nums.begin(), nums.end());
    if(nums[0] == nums[1] && nums[1] == nums[2]){
        cout << "YES\n";
        return;
    }
    if(nums[1] % nums[0] == 0 && nums[2] % nums[0] == 0 && (nums[1]/nums[0] - 1) + (nums[2]/nums[0] - 1) <= 3){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
     
}

int main(){
    int t;
    cin >> t;
    while(t--){
        sol();
    }

    return 0;
}

