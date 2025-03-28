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

vector<ll> ans;

void findPath(vector<ll> & parents) {
    ans.clear();
    ll n = parents.size() - 1;
    while(parents[n] != -1) {
        ans.push_back(n);
        n = parents[n];
    }
    ans.push_back(0);
    reverse(ALL(ans));
}

bool dfs(ll node, ll d, ll x, vector<bool> & vis, ll target, vector<vector<pair<ll, ll> > > & g, vector<ll> & parents) {
    vis[node] = true;
    pair<ll, ll> nodo = {node, 0};

    parents[node] = -1;

    queue<pair<ll, ll> > cola;

    cola.push({node, 0});

    while(!cola.empty()) {
        nodo = cola.front();
        cola.pop();
        if(nodo.first == target) {
            findPath(parents);
            return true;
        }
        if(nodo.second < d) for(auto i : g[nodo.first]) {
            if(!vis[i.first] && i.second <= x) {
                vis[i.first] = true;
                cola.push({i.first, nodo.second + 1});
                parents[i.first] = nodo.first;
            }
        }
    }
    return false;

}

void solve(){        
    ll n, m, d;
    cin >> n >> m >> d;
    vector<vector<pair<ll, ll> > > g(n);
    for(int i = 0; i < m; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        a --;
        b --;
        g[a].push_back({b, w});
    }
    ll r = (1LL << 30);
    ll l = -1;
    vector<bool> vis;
    vector<ll> parents;
    while(l + 1 < r) {
        vis.assign(n, false);
        parents.assign(n, 0);
        ll mid = (l + r) / 2;
        if(dfs(0, d, mid, vis, n - 1, g, parents)) r = mid;
        else l = mid;
    }
    if(ans.size() == 0) {
        cout << -1 << endl;
        return;
    }
    cout << ans.size() - 1 << endl;
    for(auto i : ans) {
        cout << i + 1 << ' ';
    }
    cout << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}

