#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;

// vector<ll> fact(200005);
//
// ll expo(ll n, ll x) {
//     if(x == 0) return 1;
//     if(x & 1) return ((n % MOD) * (expo(n, x - 1) % MOD)) % MOD;
//     ll y = expo(n, x / 2);
//     return ((y % MOD) * (y % MOD)) % MOD;
// }
//
// ll choose(ll n, ll k) {
//     ll upper = fact[n];
//     ll under = fact[k];
//     under = ((under % MOD) * (fact[n - k] % MOD)) % MOD;
//     ll inv = expo(under, MOD - 2);
//     return ((upper % MOD) * (inv % MOD)) % MOD;
// }

void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> mapa;
    for(auto &i : a) {
        cin >> i;
        mapa[i] ++;
    }
    ll ans = 1;
    for(auto i : mapa) {
        ll pre = 1 + i.second;
        ans = ((ans % MOD) * (pre % MOD)) % MOD;
    }
    cout << ans - 1 << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

