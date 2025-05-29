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

bool dfs(ll node, vector<vector<ll>> & g, vector<bool> & vis, vector<bool> & taken, vector<pair<ll, ll>> & ans) {
    vis[node] = true;
    vector<ll> need;
    for(auto i : g[node]) {
        if(!vis[i] && !taken[i] && !dfs(i, g, vis, taken, ans)) {
            need.push_back(i);
        }
    }

    for(int i = 0; i + 1 < need.size(); i++, i++) {
        ans.push_back({need[i], need[i + 1]});
        taken[need[i]] = true;
        taken[need[i + 1]] = true;
    }
    if(need.size() & 1) {
        ans.push_back({node, need[need.size() - 1]});
        taken[node] = true;
        taken[need[need.size() - 1]] = true;
    }
    return taken[node];
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
    vector<bool> taken(n + 1, false);
    vector<bool> vis(n + 1, false);
    vector<pair<ll, ll>> ans;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i, g, vis, taken, ans);
        }
    }
    cout << ans.size() << endl;
    for(auto i : ans) {
        cout << i.first << ' ' << i.second << endl;
    }

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

