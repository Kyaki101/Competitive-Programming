#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

int n, k;

vec nums;

bool isValid(int j){
    return j < n;
}

void sol(){
    cin >> n >> k;
    nums.assign(n, 0);
    int inv = 0;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    for(int i = 0; i < n; i++){
        if(abs((i + 1) - nums[i]) % k != 0){
            inv ++;
        }
    }
    if(!inv){
        cout << "0\n";
    }
    else if(inv == 2){
        cout << "1\n";
    }
    else cout << "-1\n";
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