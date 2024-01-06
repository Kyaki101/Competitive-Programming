#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<ll> vec;
using namespace std;

ll a;
ll b;
ll n;

vec tools;

void sol(){
    cin >> a >> b >> n;
    tools.assign(n, 0);
    for(int i = 0; i < n; i++){
        cin >> tools[i];
    }
    if(b == 0){cout << 0 << '\n'; return;}
    ll res = b;
    b = 1;
    for(int i = 0; i < n; i++){
        res += (min(a - 1, tools[i]));
    }
    cout << res << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--){
        sol();
    }


    return 0;
}