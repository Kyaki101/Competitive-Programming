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


void bfs(vector<vector<ll>> & g, vector<bool> & vis, vector<ll> & p) {
    vis[1] = true;
    queue<ll> cola;
    cola.push(1);
    p[1] = 0;
    while(!cola.empty()) {
        ll curr = cola.front();
        cola.pop();
        for(auto i : g[curr]) {
            if(!vis[i]) {
                p[i] = curr;
                vis[i] = true;
                cola.push(i);
            }
        }
    }
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
    vector<ll> p(n + 1);
    bfs(g, vis, p);
    if(!vis[n]) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vector<ll> ans;
    ll curr = n;
    while(curr != 0) {
        ans.PB(curr);
        curr = p[curr];
    }
    cout << ans.size() << endl;
    reverse(ALL(ans));
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

