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

void dijkstras(ll s, vector<vector<pair<ll, ll>>> & g, vector<ll> & memo, vector<bool> & vis) {
    memo[s] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> cola;
    cola.push({0, s});
    while(!cola.empty()) {
        auto curr = cola.top();
        if(vis[curr.second]) {
            cola.pop();
            continue;
        }
        vis[curr.second] = true;
        cola.pop();
        for(auto [w, v] : g[curr.second]) {
            cola.push({w + memo[curr.second], v});
            memo[v] = min(memo[v], w + memo[curr.second]);
        }
    }

}

void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> g(n + 1);
    for(int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({c, b});
    }
    vector<ll> memo(n + 1, (1LL << 60));
    vector<bool> vis(n + 1, false);
    dijkstras(1, g, memo, vis);
    for(int i = 1; i <= n; i++) {
        cout << memo[i] << ' ';
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

