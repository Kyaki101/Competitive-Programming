/*
https://codeforces.com/problemset/problem/32/B
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    string s;
    cin >> s;
    int i = 0;
    while(i < s.size()){
        if(s[i] == '.'){
            cout << '0';
            i ++;
        }
        else if(s[i] == '-' && s[i + 1] == '.'){
            cout << '1';
            i ++; i++;
        }
        else if(s[i] == '-' && s[i + 1] == '-'){
            cout << '2';
            i ++; i++;
        }
    }
    cout << '\n';
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