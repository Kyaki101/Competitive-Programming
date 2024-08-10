/*
*https://codeforces.com/contest/1999/problem/A
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;


void sol(){
    string s;
    cin >> s;
    ll sum = 0;
    for(int i = 0; i < s.size(); i++){
        sum += s[i] -'0';
    }
    cout << sum << endl;
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

