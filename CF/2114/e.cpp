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



void dfs(vector<vector<ll>> & g, ll node, vector<bool> & vis, bool odd, vector<ll> & ans, vector<ll> & vals, ll bestE, ll bestO) {
    vis[node] = true;
    if(odd) {
        ans[node] = vals[node] + bestO;
        bestO += vals[node];
        bestE = max(0LL, bestE - vals[node]);
    }
    else {
        ans[node] = vals[node] + bestE;
        bestE += vals[node];
        bestO = max(0LL, bestO - vals[node]);
    }

    for(auto i : g[node]) {
        bool stat = !odd;
        if(!vis[i]) {
            
            dfs(g, i, vis, stat, ans, vals, bestE, bestO);
        }
    }

}


void solve(){        
    ll n;
    ll bestO = 0;
    ll bestE = 0;
    cin >> n;
    vector<vector<ll>> g(n + 1);
    vector<ll> da(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> da[i];
    }
    bestE = 0;
    bestO = 0;
    for(int i = 0; i < n - 1; i++) {
        ll x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<bool> vis(n + 1, false);
    vector<ll> ans(n + 1, 0);
    dfs(g, 1, vis, true, ans, da, bestE, bestO);
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
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
    }return 0;
}

