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

ll dfs(ll node, vector<vll> &g, vector<bool> &vis, vll & subtr, vll &parent) {
    vis[node] = true;
    ll ans = 1;
    for(auto i : g[node]) {
        if(!vis[i]) {
            parent[i] = node;
            ans += dfs(i, g, vis, subtr, parent);
        }
    }
    return subtr[node] = ans;
}

void solve(){        
    ll n, k;
    cin >> n >> k;
    vector<vll> g(n + 1);
    vll subtr(n + 1, 0);
    vll parent(n + 1, 0);
    for(int i = 0; i < n - 1; i++) {
        ll x, y;
        cin >> x >> y;
        g[x].PB(y);
        g[y].PB(x);
    }
    vector<bool> vis(n + 1);
    dfs(1, g, vis, subtr, parent);
    ll ans = n;
    for(int i = 1; i <= n; i++) {
        ll before = n - subtr[i];
        for(auto j : g[i]) {
            if(j == parent[i]) continue;
            if(before + subtr[i] - subtr[j] >= k) {
                ans += subtr[j];
            }
        }
        if(subtr[i] >= k) ans += before;
    }
    cout << ans << endl;

    
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

