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
const int MAX = 2e5+20, MOD = 998244353;


void dfs(vector<vector<ll>> & g, map<ll, vector<ll>, greater<ll>> & mapa, ll node, ll height) {
    mapa[height].push_back(node);
    for(auto i : g[node]) {
        dfs(g, mapa, i, height + 1);
    }
}



void solve(){        
    ll n;
    cin >> n;
    vector<vector<ll>> g(n + 1);
    for(int i = 2; i <= n; i++) {
        ll x; cin >> x;
        g[x].push_back(i);
    }
    map<ll, vector<ll>, greater<ll>> mapa;
    map<ll, ll> acum;
    vector<ll> indi(n + 1, 0);
    vector<ll> path(n + 1, 0);
    dfs(g, mapa, 1, 0);
    for(auto &i : mapa) {
        for(auto &j : i.second) {
            for(auto c : g[j]) {
                acum[i.first] = (acum[i.first] + path[c]) % MOD;
                indi[j] = (indi[j] + path[c]) % MOD;
            }
        }
        for(auto &j : i.second) {
            path[j] = ((acum[i.first] % MOD) - (indi[j] % MOD) + MOD) % MOD;
            path[j] ++;
            path[j] %= MOD;
        }
    }
    
    path[1] = 0;
    for(auto i : g[1]) {
        path[1] = (path[1] + path[i]) % MOD;
    }
    path[1] ++;
    path[1] %= MOD;

    cout << path[1] << endl;

    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

