/*
https://codeforces.com/problemset/problem/1512/A
*/
#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    vec a(n);
    for(int i = 0; i < n; i++){
        cin >> a [i];
    }
    for(int i = 1; i < n; i++){
        if(a[i] != a[i - 1]){
            if(i == 1){
                if(a[i] != a[2]){
                    cout << 2 << '\n'; return;
                }
                else{
                    cout << 1 << '\n'; return;
                }
            }
            cout << i + 1 << '\n';
            return;
        }
    }
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