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

void dfs(ll node, vector<vll> & g, vector<bool> & vis, vector<ll> & ans) {
    ans.PB(node);
    vis[node] = true;
    for(auto i : g[node]) {
        if(!vis[i]) dfs(i, g, vis, ans);
    }
}

void solve(){        
    ll n, t;
    cin >> n >> t;
    vector<vll> g(n + 1);
    map<ll, ll> mapa;
    for(int i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        g[a].PB(b);
        g[b].PB(a);
        mapa[a] ++;
        mapa[b] ++;
    }
    ll leaf = 0;
    for(auto &[x, y] : mapa) {
        if(y == 1) {
            leaf = x;
        }
    }
    vector<bool> vis(n + 1, false);
    vll ans;

    dfs(leaf, g, vis, ans);

    ll start;
    cin >> start;
    ll index;
    for(int i = 0; i < n; i++) {
        if(ans[i] == start) index = i;
    }
    if(index & 1) {
        cout << "Ron" << endl;
        return;
    }
    if(((n - 1) - index) & 1) {
        cout << "Ron" << endl;
        return;
    } 
    cout << "Hermione" << endl;

    
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

