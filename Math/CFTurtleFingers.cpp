#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    ll a, b, l;
    cin >> a >> b >> l;
    /*if (l%a && l%b) {
        cout << 1 << '\n';
        return;
    }*/
    set<ll> k;
    for (ll pa = 1; !(l%pa) && l/pa; pa *= a) for (ll pb = 1; !((l/pa)%pb) && l/pa/pb; pb *= b) k.insert(l/pa/pb);
    cout << k.size() << '\n';
    /*for (auto i : k) {
        cout << i << ' ';
    }
    cout << '\n';*/
    return;
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