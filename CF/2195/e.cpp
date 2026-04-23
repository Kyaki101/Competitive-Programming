#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define R second
#define L first
#define PB push_back
#define ll long long
typedef vector<ll> vll;

const int MAX = 2e5+20, MOD = 1e9+7;

ll add(ll a, ll b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

ll mult(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}


ll dfs(ll node, vector<pair<ll, ll>> &g, vll & dp) {
    if(g[node].L == 0) return 0;
    return dp[node] = add(4, add(dfs(g[node].L, g, dp), dfs(g[node].R, g, dp)));
}

void sec(ll node, vector<pair<ll, ll>> &g, vll & dp, vll &parent) {
    if(g[node].L == 0) {
        dp[node] = 1 + dp[parent[node]];
        return;
    }
    dp[node] = add(1 + dp[parent[node]], dp[node]);
    sec(g[node].L, g, dp, parent);
    sec(g[node].R, g, dp, parent);
}

void solve(){        
    ll n;
    cin >> n;
    vector<pair<ll, ll>> g(n + 1);
    vector<ll> parent(n + 1);
    g[0] = {1, 0};
    for(int i = 1; i <= n; i++) {
        cin >> g[i].L >> g[i].R;
        parent[g[i].L] = i;
        parent[g[i].R] = i;
    }
    vll dp(n + 1);
    dp[0] = 0;
    dfs(1, g, dp);
    sec(1, g, dp, parent);
    for(int i = 1; i <= n; i++) {
        cout << dp[i] << ' ';
    }
    cout << endl;





    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        #ifdef ICPC 
            cout << "--------------------------------------------------" << endl;
        #endif // 
    }
    #ifdef ICPC 
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}

