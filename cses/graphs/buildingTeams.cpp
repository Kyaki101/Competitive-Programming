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

const int MAX = 2e5+20, MOD = 1e9+7;

bool dfs(vector<vector<ll>> & g, ll node, vector<bool> & vis, vector<bool> & c) {
    vis[node] = true;
    bool state = true;
    for(auto i : g[node]) {
        if(vis[i]) {
            if(c[i] == c[node]) state = false;
            continue;
        }
        c[i] = !c[node];
        state = state && dfs(g, i, vis, c);
    }
    return state;



}

void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n + 1);
    for(int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        g[a].PB(b);
        g[b].PB(a);
    }
    vector<bool> vis(n + 1, false);
    vector<bool> color(n + 1);
    bool state = true;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) state = state && dfs(g, i, vis, color);
    }
    if(!state) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(color[i]) cout << 1 << ' ';
        else cout << 2 << ' ';
    }
    cout << endl;


}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

