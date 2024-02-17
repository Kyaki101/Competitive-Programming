/*
https://codeforces.com/problemset/problem/791/A
*/
#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int a, b;
    cin >> a >> b;
    int res = 0;
    while(a <= b){
        res ++;
        a *= 3;
        b *= 2;
    }
    cout << res << endl;
    
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