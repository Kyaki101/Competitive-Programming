#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    ll n, k;
    cin >> n >> k;
    if(!(n & 1)){
        if(k <= n/2){
            cout << k * 2 - 1 << '\n';
        }
        else{
            k -= n/2;
            cout << k * 2 << '\n';
        }
    }
    else{
        if(k <= n/2 + 1){
            cout << k * 2 - 1 << '\n';
        }
        else{
            k -= n/2 + 1;
            cout << k * 2 << '\n';
        }
    }
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