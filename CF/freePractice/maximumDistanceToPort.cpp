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

void bfs(vector<vll> &g, vll &dist, vector<bool> &vis) {
    queue<ll> cola;
    cola.push(1);
    dist[1] = 0;
    vis[1] = true;
    while(!cola.empty()) {
        ll node = cola.front();
        cola.pop();
        for(auto i : g[node]) {
            if(!vis[i]) {
                dist[i] = dist[node] + 1;
                cola.push(i);
                vis[i] = true;
            }
        }
    }


}

void solve(){        
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vll> g(n + 1);
    vll ty(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> ty[i];
    }
    for(int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        g[a].PB(b);
        g[b].PB(a);
    }

    vll time(k + 1);
    vll dist(n + 1, (1LL << 30));
    vector<bool> vis(n + 1);
    bfs(g, dist, vis);
    for(int i = 1; i <= n; i++) {
        time[ty[i]] = max(time[ty[i]], dist[i]);
    }
    for(int i = 1; i <= k; i++) {
        cout << time[i] << ' ';
    }
    cout << endl;

    
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

