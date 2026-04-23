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

ll maxi = 0;

void dfs(ll node, vector<vll> &g, vector<bool> &vis, ll d) {
    vis[node] = true;
    if(g[node].size() == 0) return;
    if(vis[g[node][0]]) {
        maxi = max(d + 1, maxi);
        return;
    }
    dfs(g[node][0], g, vis, d + 1);
}

void solve(){        
    ll n;
    cin >> n;
    map<string, ll> mapping;
    map<string, string> edges;
    vector<pair<string, string>> bruh;
    ll k = 0;
    for(int i = 0; i < n; i++) {
        string a, b, c;
        cin >> a >> b >> c;
        mapping[b] = k;
        edges[c] = b;
        bruh.PB({b, c});
        k++;
    }
    vector<vector<ll>> g(k);
    for(auto &[x, y] : bruh) {
        if(edges.find(x) != edges.end()) {
            g[mapping[x]].PB(mapping[y]);
        }
    }


    vector<bool> vis(k, false);
    for(int i = 0; i < k; i++) {
        if(!vis[i] && g[i].size() != 0) {
            dfs(i, g, vis, 0);
        }
    }
    if(maxi == 0) {
        cout << "No trades possible" << endl;
        return;
    }
    cout << maxi << endl;
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
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

