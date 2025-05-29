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

ll u, v;

bool bfs(ll node, vector<vector<ll>> & g, vector<ll> & parents) {
    parents[node] = node;
    queue<ll> cola;
    cola.push(node);
    while(!cola.empty()) {
        node = cola.front();
        cola.pop();
        for(auto i : g[node]) {
            if(!parents[i]) {
                parents[i] = node;
                cola.push(i);
            }
            else if(parents[node] != i) {
                if(parents[i] != 0) {
                    u = node;
                    v = i;
                    return true;
                }
            }
        }
    }
    return false;
}

void solve(){        
    ll n, m;    
    cin >> n >> m;
    vector<vector<ll>> g(n + 1);
    for(int i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bool f = false;
    vector<ll> parents(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        if(!parents[i]) {
            if(bfs(i, g, parents)) {
                f = true;
                break;
            }
        }
    }
    if(!f) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    set<ll> first;
    vector<ll> ans1, ans2;
    ll inter = 0;
    while(parents[u] != u) {
        ans1.push_back(u);
        first.insert(u);
        u = parents[u];
    }
    ans1.push_back(u);
    first.insert(u);

    while(parents[v] != v && first.find(v) == first.end()) {
        ans2.push_back(v);
        v = parents[v];

    }
    ans2.push_back(v);
    inter = v;
    reverse(ALL(ans2));

    ll i = 0;
    vector<ll> res;
    while(ans1[i] != inter) {
        res.push_back(ans1[i]);
        i++;
    }
    for(int j = 0; j < ans2.size(); j++) {
        res.push_back(ans2[j]);
    }
    cout << res.size() + 1 << endl;
    for(auto i : res) cout << i << ' ';
    cout << ans1[0] << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

