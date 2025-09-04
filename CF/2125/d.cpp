#include <bits/stdc++.h>
using namespace std;

#define SET(m,i) ((m)|(1ULL<<(i)))
#define TEST(m,i) ((m)&(1ULL<<(i)))
#define CLEAR(m,i) ((m)&~(1ULL<<(i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define DEBUG_ALL(a) for(auto &w:a)cout<<w<<' ';cout<<endl;
#define ALLN(x,n) begin(x), begin(x)+n
#define ALL(x) begin(x), end(x)
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
#define right first.second
#define left first.first
#define proba second.first
#define invproba second.second
const ll MAX = 2e5+20, MOD = 998244353;

ll binPow(ll n, ll x) {
    if(x == 0) return 1;
    if(x & 1) return ((n % MOD) * (binPow(n, x - 1) % MOD)) % MOD;
    ll y = binPow(n, x / 2);
    return ((y % MOD) * (y % MOD)) % MOD;
}


ll divi(ll p, ll q) {
    ll inv = binPow(q, MOD - 2);
    return ((p % MOD) * (inv % MOD)) % MOD;
}

ll mul(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll add(ll a, ll b) {
    return ((a % MOD) + (b % MOD) + MOD) % MOD;
}



void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> a(m + 1);
    for(int i = 0; i < n; i++) {
        ll l, r, p, q;
        cin >> l >> r >> p >> q;
        a[r].push_back({l, divi(p, q)});
    }
    vector<ll> acum(m + 1);
    acum[0] = 1;
    for(int i = 1; i <= m; i++) {
        ll curr = 1;
        for(auto &[_, p] : a[i]) {
            curr = mul(curr, add(1, -p));
        }
        acum[i] = mul(curr, acum[i - 1]);
    }

    vector<ll> dp(m + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= m; i++) {
        for(auto &[l, p] : a[i]) {
            ll curr = p;
            curr = mul(curr, dp[l - 1]);
            ll ac = divi(acum[i], acum[l - 1]);
            curr = mul(curr, divi(ac, add(1, -p)));
            dp[i] = add(dp[i], curr);

        }
    }
    cout << dp[m] << endl;
    




}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    while(T--){
        solve();
        //cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}

