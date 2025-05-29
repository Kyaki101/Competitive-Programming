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

void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for(ll &i: a) cin >> i;
    if(m == 1) {
        cout << 1 << endl; return;
    }
        
    vector<vector<ll>> dp(n, vector<ll>(m + 1, 0));
    for(int i = 0; i < n; i++) {
        if(a[i] != 0) {
            if(i == 0) dp[0][a[i]] = 1;
            else {
                if(a[i] == m) dp[i][m] = ((dp[i - 1][m - 1] % MOD) + (dp[i - 1][m] % MOD)) % MOD;
                else if(a[i] == 1) dp[i][a[i]] = ((dp[i - 1][1] % MOD) + (dp[i - 1][2] % MOD)) % MOD;
                else dp[i][a[i]] = ((dp[i - 1][a[i] - 1] % MOD) + (dp[i - 1][a[i]] % MOD) + (dp[i - 1][a[i] + 1] % MOD)) % MOD;
            }
            continue;
        }
        for(ll int j = 1; j <= m; j++) {
            if(i == 0) dp[0][j] = 1;
            else {
                if(j == m) dp[i][j] = ((dp[i - 1][m] % MOD) + (dp[i - 1][m - 1] % MOD)) % MOD;
                else if(j == 1) dp[i][j] = ((dp[i - 1][1] % MOD) + (dp[i - 1][2] % MOD)) % MOD;
                else dp[i][j] = ((dp[i - 1][j - 1] % MOD) + (dp[i - 1][j] % MOD) + (dp[i - 1][j + 1] % MOD)) % MOD;
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= m; i++) {
        ans = ((ans % MOD) + (dp[n - 1][i] % MOD)) % MOD;
    }
    cout << ans << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

