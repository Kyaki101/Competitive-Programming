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


bool bfs(vector<vector<pair<ll, ll>>> & g, ll n, ll x, vector<ll> & vals) {
    queue<ll> cola;
    vector<bool> vis(n + 1, false);
    vector<ll> maxi(n + 1, 0LL);
    cola.push(1);
    maxi[1] = min(x, vals[1]);
    while(!cola.empty()) {
        ll nodo = cola.front();
        cola.pop();
        if(nodo == n) {
            return true;
        }
        for(auto i : g[nodo]) {
            if(i.second <= maxi[nodo]) {
                maxi[i.first] = max(min(x, maxi[nodo] + vals[i.first]), maxi[i.first]);
                if(!vis[i.first]) {
                    cola.push(i.first);
                    vis[i.first] = true;
                }
            }
        }
    }
    return false;
    


}

void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> g(n + 1);
    vector<ll> vals(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> vals[i];
    }
    for(int i = 0; i < m; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
    }
    for(int i = 1; i <= n; i++) {
        sort(ALL(g[i]));
    }
    ll l = -1;
    ll r = 2000000000;
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(bfs(g, n, mid, vals)) r = mid;
        else l = mid;
    }
    if(r == 2000000000) {
        cout << -1 << endl;
        return;
    }
    cout << r << endl;


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

