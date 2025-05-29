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
const int MAX = 2e5+20, MOD = 998244353;
ll n;

void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll &i : a) cin >> i;
    vector<vector<ll>> dp(n + 1, vector<ll>(4, 0));

    for(int i = 1; i <= n; i++) {
        if(a[i - 1] == 1) {
            dp[i][1] = ((dp[i - 1][1] % MOD) + 1) % MOD;

            dp[i][2] = dp[i - 1][2];
            dp[i][3] = dp[i - 1][3]; 

        }
        else if(a[i - 1] == 2) {
            dp[i][2] = (((2 * (dp[i - 1][2] % MOD)) % MOD) + (dp[i - 1][1] % MOD)) % MOD;

            dp[i][1] = dp[i - 1][1];
            dp[i][3] = dp[i - 1][3];
        }
        else if(a[i - 1] == 3) {
            dp[i][3] = ((dp[i - 1][3] % MOD) + (dp[i - 1][2] % MOD)) % MOD;

            dp[i][1] = dp[i - 1][1];
            dp[i][2] = dp[i - 1][2];
        }
    }

    cout << dp[n][3] << endl;



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

