/*
https://codeforces.com/contest/1950/problem/A
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a < b && b < c){
        cout << "STAIR\n";
        return;
    }
    if(a < b && b > c){
        cout << "PEAK\n";
        return;
    }
    cout << "NONE\n";
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