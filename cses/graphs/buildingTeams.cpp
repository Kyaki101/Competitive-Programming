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
ll n;

bool bfs(ll node, vector<vector<ll>> & g, vector<ll> & colors) {
    colors[node] = 1;
    queue<ll> cola;
    cola.push(node);
    while(!cola.empty()) {
        node = cola.front();
        cola.pop();
        for(auto i : g[node]) {
            if(!colors[i]) {
                if(colors[node] == 1) colors[i] = 2;
                else colors[i] = 1;
                cola.push(i);
            }
            else if(colors[i] == colors[node]) return false;
        }
    }
    return true;
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
    vector<ll> colors(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        if(!colors[i]) {
             if(!bfs(i, g, colors)) {
                cout << "IMPOSSIBLE" << endl;
                return;
            }           
        }

    }

    for(int i = 1; i <= n; i++) {
        cout << colors[i] << ' ';
    }
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

