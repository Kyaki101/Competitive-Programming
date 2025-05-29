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


void bfs(ll node, vector<vector<ll>> & g, vector<ll> & vis, vector<ll> & parent) {
    vis[node] = true;
    queue<ll> cola;
    cola.push(node);
    while(!cola.empty()) {
        node = cola.front();
        cola.pop();
        for(auto i : g[node]) {
            if(!vis[i]) cola.push(i), vis[i] = true, parent[i] = node;
        }
    }
}


void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n + 1);
    vector<ll> vis(n + 1, false);
    vector<ll> parent(n + 1, 0);
    for(int i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(1, g, vis, parent);
    if(!vis[n]) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    
    ll x = n;
    vector<ll> ans;
    while(x != 1) {
        ans.push_back(x);
        x = parent[x];
    }
    ans.push_back(1);
    reverse(ALL(ans));
    cout << ans.size() << endl;
    for(auto i : ans) cout << i << ' ';
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

