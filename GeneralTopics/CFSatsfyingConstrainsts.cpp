#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

ll n;

vector<pair<ll, ll>> pares;

void sol(){
    cin >> n;
    pares.assign(n, make_pair(0, 0));
    ll a; ll b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        pares[i].first = a; pares[i].second = b;
    }
    ll low = -1 * (1 << 30);
    ll top = 1 * (1 << 30);
    for(int i = 0; i < n; i++){
        if(pares[i].first == 1){
            low = max(low, pares[i].second);
        }
        else if(pares[i].first == 2){
            top = min(top, pares[i].second);
        }
    }
    int range = (top - low) + 1;
    if(range < 0){cout << "0\n"; return;}
    for(int i = 0; i < n; i++){
        if(pares[i].first == 3 && pares[i].second >= low && pares[i].second <= top){
            range --;
        }
    }
    cout << range << '\n';
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