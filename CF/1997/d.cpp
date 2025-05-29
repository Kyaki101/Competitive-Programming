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


ll dfs(ll node, vector<vector<ll>> & g, vector<ll> & a) {
    if(g[node].size() == 0) {
        return a[node];
    }

    ll mini = (1LL << 60);

    for(int i = 0; i < g[node].size(); i++) {
        mini = min(mini, dfs(g[node][i], g, a));
    }

    ll diff = mini - a[node];
    if(node == 1) {
        return a[node] + mini;
    }
    if(diff > 0) {
        return a[node] + (diff / 2);
    }
    return min(a[node], mini);
}

void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<ll>> graph(n + 1);
    for(int i = 2; i <= n; i++) {
        ll x;
        cin >> x;
        graph[x].push_back(i);
    }
    cout << dfs(1, graph, a) << endl;
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

