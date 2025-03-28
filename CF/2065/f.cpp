#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
typedef long long int ll;
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;


bool lookUp(multiset<ll> & adj, ll num) {
    return adj.find(num) != adj.end();
}

void solve(){        
    ll n;
    cin >> n;
    vector<ll> val(n + 1);
    for(int i = 1; i < n + 1; i++) {
        cin >> val[i];
    }
    vector<vector<ll> > g(n + 1);
    vector<multiset<ll> > adj(n + 1);
    for(int i = 0; i < n - 1; i ++) {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        adj[a].insert(val[b]);
        g[b].push_back(a);
        adj[b].insert(val[a]);
    }
    string s = "";
    for(int i = 0; i < n; i++) {
        s.push_back('0');
    }


    for(int i = 1; i <= n; i++) {
        if(adj[i].find(val[i]) != adj[i].end()) {
            s[val[i] - 1] = '1';
            continue;
        }
        bool ans = false;
        for(int j = 0; j < g[i].size(); j++) {
            adj[g[i][j]].erase(adj[g[i][j]].find(val[i]));
            ans = ans || lookUp(adj[g[i][j]], val[i]);
            adj[g[i][j]].insert(val[i]);
        }
        if(ans) {
            s[val[i] - 1] = '1';
        }
    }
    cout << s << endl;



}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

