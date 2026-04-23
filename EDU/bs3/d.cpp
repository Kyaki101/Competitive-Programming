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
#define pll pair<ll, ll>
typedef vector<ll> vll;

const int MAX = 2e5+20, MOD = 1e9+7;

void solve(){        
    ll n, m, d;
    cin >> n >> m >> d;
    vector<vector<pll>> g(n + 1);
    ll r = 0, l = (1LL << 60);
    for(int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].PB({b, c});
        l = min(c, l);
        r = max(c, r);
    }
    vll ans;

    auto possible = [&](ll mid) {
        vll minEdges(n + 1, (1 << 30));
        minEdges[1] = 0;
        vll parent(n + 1, 0);
        for(int i = 1; i < n; i++) {
            for(auto [child, weight] : g[i]) {
                if(weight <= mid && minEdges[i] + 1 < minEdges[child]) {
                    minEdges[child] = minEdges[i] + 1;
                    parent[child] = i;
                }
            }
        }
        if(minEdges[n] <= d) {
            ans = parent;
            return true;
        }
        return false;
    };

    l --;
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(possible(mid)) r = mid;
        else l = mid;

    }
    if(!possible(r)) {
        cout << -1 << endl;
        return;
    }

    vll res;
    ll index = n;
    while(ans[index] != 0) {
        res.PB(index);
        index = ans[index];
    }
    res.PB(1);
    reverse(ALL(res));
    cout << res.size() - 1 << endl;
    for(auto i : res) cout << i << ' ';
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

