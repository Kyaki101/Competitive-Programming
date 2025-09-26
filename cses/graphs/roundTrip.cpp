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


bool dfs(vector<vll> & g, ll node, vector<bool> & vis, vll & p, vector<ll> & path) {
    vis[node] = true;
    for(auto i : g[node]) {
        if(vis[i]) {
            if(i != p[node]) {
                path.PB(i);
                path.PB(node);
                return true;
            }
            continue;
        }
        p[i] = node;
        if(dfs(g, i, vis, p, path)) {
            path.PB(node);
            return true;
        }
    }
    return false;


}

void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<vll> g(n + 1);
    for(int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        g[a].PB(b);
        g[b].PB(a);
    }
    vector<ll> path;
    vector<ll> p(n + 1, 0);
    vector<bool> vis(n + 1, false);
    for(int i = 1; i <= n; i++) {

        if(!vis[i] && dfs(g, i, vis, p, path)) {
            ll size = 1;
            ll i = 1;
            while(path[i] != path[0]) i++, size++;
            size ++;
            cout << size << endl;
            cout << path[0] << ' ';
            i = 1;
            while(path[i] != path[0]) {
                cout << path[i] << ' ';
                i++;
            }
            cout << path[0] << endl;
            return;
        }
    }
    cout << "IMPOSSIBLE" << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

