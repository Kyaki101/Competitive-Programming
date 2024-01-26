#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

int n;
vec nums;


int findMin(){
    int min = (1 << 30);
    int index = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] < min){
            min = nums[i];
            index = i;
        }
    }
    return index;
}

void sol(){
    cin >> n;
    nums.assign(n, 0);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int lowest = findMin();
    ll prod = 1;
    for(int i = 0; i < n; i++){
        if(i == lowest){
            prod *= (nums[i] + 1);
        }
        else{
            prod *= nums[i];
        }
    }
    cout << prod << '\n';
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