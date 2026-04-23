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

vector<pair<ll, ll>> moves = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

vll match = {2, 3, 0, 1};


bool val(ll i, ll j, ll n, ll m) {
    return (i < n && j < m && i > -1 && j > -1);
}


ll dfs(ll i, ll j, vector<vll> &g, vector<vector<bool>> &vis) {
    vis[i][j] = true;
    ll tam = 1;
    ll a = g[i][j];
    for(int k = 0; k < 4; k++) {
        ll x = i + moves[k].first;
        ll y = j + moves[k].second;
        if(!val(x, y, g.size(), g[0].size())) continue;
        ll b = g[x][y];
        if(!TEST(a, k) && !TEST(b, match[k]) && !vis[x][y]) {
            tam += dfs(x, y, g, vis);
        }

    }
    return tam;

}

void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<vll> mat(n, vll(m));
    for(auto &i : mat) {
        for(auto &j : i) cin >> j;
    }
    vll ans;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j]) ans.PB(dfs(i, j, mat, vis));
        }
    }

    sort(ans.rbegin(), ans.rend());

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

