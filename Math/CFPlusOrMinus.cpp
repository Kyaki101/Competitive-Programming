/*
https://codeforces.com/problemset/problem/1807/A
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int a, b, c;
    cin >> a >> b >> c;
    if(c > max(a, b)){
        cout << '+' << '\n';
        return;
    }
    cout << '-' << endl;
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