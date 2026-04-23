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



void decomp(ll node, vector<vll> &g, vector<bool> &vis, set<ll> &comp) {
    vis[node] = true;
    comp.insert(node);
    for(auto child : g[node]) {
        if(!vis[child]) decomp(child, g, vis, comp);
    }

}

bool color(ll node, bool bruh, vector<vll> &g, unordered_map<ll, bool> &vis, unordered_map<ll, bool> & col) {
    vis[node] = true;
    col[node] = bruh;
    bool ans = true;
    for(auto child : g[node]) {
        if(!vis[child]) {
            ans = ans && color(child, !bruh, g, vis, col);
        }
        else {
            if(col[child] == bruh) {
                return false;
            }
        }
    }
    return ans;

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
    vector<bool> vis(n + 1, false);

    vector<set<ll>> components;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            set<ll> temp;
            decomp(i, g, vis, temp);
            components.PB(temp);
        }
    }

    ll ans = 0;

    for(auto &un : components) {
        unordered_map<ll, bool> visi;
        unordered_map<ll, bool> c1, c2;
        for(auto node : un) {
            vis[node] = false;
            c1[node] = false;
            c2[node] = false;
        }
        ll maxi = 0;
        if(color(*un.begin(), true, g, visi, c1)) {
            ll temp = 0;
            for(auto node : un) {
                temp += c1[node];
            }
            maxi = max(temp, maxi);

        }
        for(auto node : un) visi[node] = false;

        if(color(*un.begin(), false, g, visi, c2)) {
            ll temp = 0;
            for(auto node : un) {
                temp += c2[node];
            }
            maxi = max(temp, maxi);

        }
        ans += maxi;

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

