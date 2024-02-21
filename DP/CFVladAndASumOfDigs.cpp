#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;


ll nums[200010];

ll digSum(int n){
    string s = to_string(n);
    ll counter = 0;
    for(char i : s){
        counter += (int)(i - '0');
    }
    return counter;
}

void fillNums(){
    nums[0] = 0;
    for(int i = 1; i < 200001; i++){
        nums[i] = nums[i - 1] + digSum(i);
    }
}


void sol(){
    int n;
    cin >> n;
    cout << nums[n] << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
              
    int t;
    cin >> t;
    fillNums();
    while(t--){
        sol();
    }


    return 0;
}