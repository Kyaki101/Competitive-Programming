/*
https://codeforces.com/problemset/problem/266/A
*/
#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    char pre = s[0];
    int count = 0;
    for(int i = 1; i< n; i++){
        if(s[i] == pre) count ++;
        else pre = s[i];
    }
    cout << count << endl;
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