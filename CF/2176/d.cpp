#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define F second
#define S first
#define PB push_back
#define ll long long
typedef vector<ll> vll;

const int MAX = 2e5+20, MOD = 998244353;

struct Edge {
    ll u;
    ll v;
    ll s;
    Edge(ll u, ll v, ll s) : u(u), v(v), s(s){}
    bool operator < (Edge &other) {
        return s < other.s;
    }
    bool operator > (Edge &other) {
        return s > other.s;
    }
};

void solve(){        
    ll n, m;
    cin >> n >> m;
    vll a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vll> g(n + 1);
    vector<Edge> edges;
    for(int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        g[u].PB(v);
        Edge ed(u, v, a[u] + a[v]);
        edges.PB(ed);
    }
    sort(edges.rbegin(), edges.rend());

    vector<map<ll, ll>> dp(n + 1);

    auto add = [&](ll x, ll y) {
        return ((x % MOD) + (y % MOD)) % MOD;
    };

    ll ans = 0;

    for(auto [u, v, s] : edges) {
        ll curr = add(dp[v][s], 1);
        dp[u][a[v]] = add(dp[u][a[v]], curr);
        ans = add(ans, curr);
    }
    cout << ans << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

