/*
*https://codeforces.com/contest/1992/problem/A
*/
#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    vec nums(3);
    for(int i = 0; i < 3; i++){
        cin >> nums[i];
    }
    for(int i = 0; i < 5; i++){
        sort(nums.begin(), nums.end());
        nums[0] ++;
    }
    cout << nums[0] * nums[1] * nums[2] << endl;
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

