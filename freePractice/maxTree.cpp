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

ll counter(ll node, vector<vector<pair<ll, pair<ll, ll>>>> & g, vector<ll> & dp, vector<bool> & vis) {
    vis[node] = true;
    for(auto &i : g[node]) {
        if(!vis[i.first]) {
            dp[node] += counter(i.first, g, dp, vis);
        } 
    }
    dp[node] ++;
    return dp[node];

}


void dfs(ll node, vector<vector<pair<ll, pair<ll, ll>>>> & g, vector<ll> & dp, vector<bool> & vis, ll l, ll r, vll & ans) {
    vis[node] = true;
    for(auto &i : g[node]) {
        if(!vis[i.first]) {
            if(i.first < node) {
                if(i.second.first < i.second.second) {
                    dfs(i.first, g, dp, vis, l, l + dp[i.first] - 1, ans);
                    l += dp[i.first];
                }
                else {
                    dfs(i.first, g, dp, vis, r - dp[i.first] + 1, r, ans);
                    r -= dp[i.first];
                }

                continue;
            }
            if(i.second.first > i.second.second) {
                dfs(i.first, g, dp, vis, l, l + dp[i.first] - 1, ans);
                l += dp[i.first];
            }
            else {
                dfs(i.first, g, dp, vis, r - dp[i.first] + 1, r, ans);
                r -= dp[i.first];
            }
        }
    }
    ans[node] = l;


}

void solve(){        
    ll n;
    cin >> n;
    vector<vector<pair<ll, pair<ll, ll>>>> g(n + 1);
    for(int i = 0; i < n - 1; i++) {
        ll a, b, x, y;
        cin >> a >> b >> x >> y;
        g[a].PB({b, {x, y}});
        g[b].PB({a, {x, y}});
    }
    vector<ll> dp(n + 1, 0);
    vector<bool> vis(n + 1, false);
    counter(1, g, dp, vis);
    vector<ll> ans(n + 1, 0);
    vis.assign(n + 1, false);
    dfs(1, g, dp, vis, 1, n, ans);
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    

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

