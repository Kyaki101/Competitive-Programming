/*
https://codeforces.com/problemset/problem/750/A
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n, k;
    cin >> n >> k;
    int time = k;
    for(int i = 1; i <= n; i++){
        if(i * 5 + time > 240){
            cout << i - 1 << '\n';
            return;
        }
        time += i * 5;

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