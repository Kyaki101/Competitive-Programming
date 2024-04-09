/*
*
*https://codeforces.com/contest/1955/problem/A
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n, a, b;
    cin >> n >> a >> b;
    if(a * 2 < b){
        cout << a * n << '\n';
        return;
    }
    if(n & 1){
        cout << b * (n / 2) + a << endl;
        return;
    }
    cout << b * (n / 2) << '\n';

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

