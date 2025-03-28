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


void dfs(ll node, vector<vector<ll> > & g, vector<bool> & vis, vector<ll> & memo, ll steps) {
    vis[node] = true;
    memo[node] = steps;
    for(auto i : g[node]) {
        if(!vis[i]) dfs(i, g, vis, memo, steps + 1);
    }

}

void solve(){        
    ll n;
    cin >> n;
    ll a, b;
    cin >> a >> b;
    a --;
    b --;
    vector<vector<ll> > g(n);
    for(int i = 0; i < n -1 ; i++) {
        ll x, y;
        cin >> x >> y;
        x --; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<bool> visA(n, false);
    vector<bool> visB(n, false);
    vector<ll> memoA(n, 0);
    vector<ll> memoB(n, 0);

    dfs(a, g, visA, memoA, 0LL);
    dfs(b, g, visB, memoB, 0LL);

    pair<ll, ll> dist;
    ll mini = (1 << 30);
    ll st;
    for(int i = 0; i < n; i++) {
        if(max(memoA[i], memoB[i]) < mini) {
            dist.first = memoA[i];
            dist.second = memoB[i];
            mini = max(memoA[i], memoB[i]);
            st = i;
        }
    }




}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

