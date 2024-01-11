#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

int n;
vec nums;

int findGreatestDif(){
    int great = 0;
    for(int i = 0; i < n; i++){
        great = max(great, abs(nums[i] - (i + 1)));
    }
    return great;
}

void sol(){
    cin >> n;
    nums.assign(n, 0);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int greatest = findGreatestDif();
    for(int i = 0; i < n; i++){
        if(abs(nums[i] - (i + 1))){
            greatest = gcd(greatest, nums[i] - (i + 1));
        }
    }
    cout << greatest << '\n';
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