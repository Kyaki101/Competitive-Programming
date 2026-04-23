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

void dfs(ll node, vector<vector<ll>> &g, vector<bool> &vis, vector<ll> & leaves) {
    bool check = false;
    vis[node] = true;
    for(auto &child : g[node]) {
        if(!vis[child]) {
            check = true;
            dfs(child, g, vis, leaves);
            leaves[node] += leaves[child];
            check = true;
        }
    }
    if(!check) leaves[node] = 1;
}

void solve(){        
    ll n;
    cin >> n;
    vector<vector<ll>> g(n + 1);
    for(int i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        g[a].PB(b);
        g[b].PB(a);
    }
    vll leaves(n + 1, 0);
    vector<bool> vis(n + 1);
    dfs(1, g, vis, leaves);
    ll q;
    cin >> q;
    while(q--) {
        ll x, y;
        cin >> x >> y;
        cout << leaves[x] * leaves[y] << endl;
    }
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        #ifdef ICPC 
            cout << "--------------------------------------------------" << endl;
        #endif // 
    }
    #ifdef ICPC 
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}

