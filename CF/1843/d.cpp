#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
typedef long long int ll;
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;


ll dfs(ll node, vector<vector<ll> > & g, vector<ll> & dp, vector<bool> & vis) {
    bool isLeaf = true;
    vis[node] = true;
    ll ans = 0;
    for(auto i : g[node]) {
        if(!vis[i]) {
            isLeaf = false;
            ans += dfs(i, g, dp, vis);
        }
    }
    if(isLeaf) return dp[node] = 1LL;
    return dp[node] = ans;
}

void solve(){        
    ll n;
    cin >> n;
    vector<vector<ll> > g(n);
    for(int i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    vector<bool> vis(n, false);
    vector<ll> dp(n, 0);
    dfs(0, g, dp, vis);

    ll q;
    cin >> q;
    while(q--) {
        ll a, b;
        cin >> a >> b;
        a --; b--;
        cout << dp[a] * dp[b] << endl;
    }


}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

