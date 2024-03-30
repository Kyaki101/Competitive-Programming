int n;
#include <bits/stdc++.h>



typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

vec nums = {10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111, 10000, 10001, 10010, 10011, 10100, 10101, 10110, 10111, 11000, 11001, 11010, 11011, 11100, 11101, 11110, 11111, 100000};


bool recur(ll n){
    if(n == 0){
        return true;
    }
    if(n == 1){
        return true;
    }
    for(int i = 0; i < nums.size(); i++){
        if(n == nums[i]){
            return true;
        }
    }
    for(int i = 0; i < nums.size(); i++){
        if(n % nums[i] == 0){
            return recur(n / nums[i]);
        }
    }
    return false;
}

void sol(){
    ll n;
    cin >> n;
    if(recur(n)){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";

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