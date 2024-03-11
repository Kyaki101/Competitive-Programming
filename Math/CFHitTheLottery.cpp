/*
https://codeforces.com/problemset/problem/996/A
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

int bill[5] = {100, 20, 10, 5, 1};

void sol(){
    int n;
    cin >> n;
    int res = 0;
    for(int i = 0; i < 5; i++){
        res += n / bill[i];
        n -= (n / bill[i]) * bill[i];
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