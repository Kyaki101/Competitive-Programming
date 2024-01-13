#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

vec nums;

bool isEven(int n){
    return n % 2 == 0;
}

void sol(){
    nums.assign(3, 0);
    cin >> nums[0] >> nums[1] >> nums[2];
    if(nums[0] == nums[2] && nums[2] == nums[1]){
        cout << "1 1 1\n"; return;
    }
    vec res(3, 0);
    if(isEven(nums[1]) && isEven(nums[2]))res[0] = 1;
    else if(!isEven(nums[1]) && !isEven(nums[2])) res[0] = 1;
    if(isEven(nums[0]) && isEven(nums[2]))res[1] = 1;
    else if(!isEven(nums[0]) && !isEven(nums[2])) res[1] = 1;
    if(isEven(nums[1]) && isEven(nums[0]))res[2] = 1;
    else if(!isEven(nums[1]) && !isEven(nums[0])) res[2] = 1;
    
    cout << res[0] << " " << res[1] << " " << res[2] << '\n';
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