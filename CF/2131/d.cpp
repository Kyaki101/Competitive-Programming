#include <bits/stdc++.h>
using namespace std;

#define SET(m,i) ((m)|(1ULL<<(i)))
#define TEST(m,i) ((m)&(1ULL<<(i)))
#define CLEAR(m,i) ((m)&~(1ULL<<(i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define DEBUG_ALL(a) for(auto &w:a)cout<<w<<' ';cout<<endl;
#define ALLN(x,n) begin(x), begin(x)+n
#define ALL(x) begin(x), end(x)
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
const ll MAX = 2e5+20, MOD = 1e9+7;



void solve(){        
    ll n;
    cin >> n;
    vector<vector<ll>> g(n + 1);
    for(int i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll potLeaves = 0;
    for(int i = 1; i <= n; i++) {
        if(g[i].size() == 1) potLeaves ++;
    }
    ll ans = (1 << 30);
    for(int i = 1; i <= n; i++) {
        ll clone = potLeaves;
        if(g[i].size() == 1) clone --;
        for(auto child : g[i]) {
            if(g[child].size() == 1) {
                clone --;
            }
        }
        ans = min(ans, clone);
        
    }
    cout << ans << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
        //cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}

