/*
*https://codeforces.com/problemset/problem/1703/B
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    string s;
    cin >> n >> s;
    bool nums[26] = {false};
    int counter = 0;
    for(int i = 0; i < n; i++){
        if(!nums[s[i] - 'A']){
            counter ++;
            counter ++;
            nums[s[i] - 'A'] = true;
        }
        else counter ++;
    }
    cout << counter << endl;
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

