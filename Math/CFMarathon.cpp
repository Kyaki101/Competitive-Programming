/*
https://codeforces.com/problemset/problem/1692/A
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    vec a(4, 0);
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    int cont = 0;
    for(int i = 1; i < 4; i++){
        if(a[i] > a[0]){
            cont ++;
        }
    }
    cout << cont << endl;
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