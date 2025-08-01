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

void solve(){        
    ll n;
    ll f, w;
    cin >> f >> w;
    cin >> n;
    vector<ll> a(n);
    ll tot = 0;
    for(auto &i : a) {
        cin >> i;
        tot += i;
    }
    vector<bool> dp(tot + 1);
    dp[0] = true;
    for(int i = 0; i < n; i++) {
        for(int s = tot; s - a[i] >= 0; s--) {
            dp[s] = dp[s] || dp[s - a[i]];
        }
    }

    ll ans = (1LL << 60);
    for(int i = 0; i <= tot; i++) {
        if(dp[i]) {
            ans = min(ans, max((i + w - 1) / w, (tot - i + f - 1) / f));
        }
    }
    cout << ans << endl;

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

