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

vector<vector<ll>> dp(1000002, vector<ll>(2, 0));

void solve(){        
    ll n;
    cin >> n;
    ll ans = ((dp[n][0] + dp[n][1]) % MOD);
    cout << ans << endl;
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    dp[1][1] = 1;
    dp[1][0] = 1;
    for(int i = 1; i < 1000000; i++) {
        dp[i + 1][0] += 2 * dp[i][0];
        dp[i + 1][1] += dp[i][0];
        dp[i + 1][0] += dp[i][1];
        dp[i + 1][1] += 4 * dp[i][1];
        dp[i + 1][0] %= MOD;
        dp[i + 1][1] %= MOD;
    }
    while(t--){
        solve();
    }return 0;
}

