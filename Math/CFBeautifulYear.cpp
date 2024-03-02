/*
https://codeforces.com/problemset/problem/271/A
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

bool different(string n){
    int nums[10] = {0};
    for(char i : n){
        if(nums[i - '0'] == 1)return false;
        (nums[i - '0']) = 1;
    }
    return true;
} 

void sol(){
    int n; cin >> n;
    n++;
    while(!different(to_string(n))){
        n++;
    }
    cout << n << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
              
    int t;
    t = 1;
    while(t--){
        sol();
    }


    return 0;
}