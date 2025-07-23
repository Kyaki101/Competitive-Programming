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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> dp(501, vector<ll>(501 + 1, 0));
    for(int i = 1; i <= 500; i++) {
        dp[i][i] = 0;
    }
    for(int i = 2; i <= 500; i++) dp[i][1] = i - 1;
    for(int i = 2; i <= 500; i++) dp[1][i] = i - 1;

    for(int i = 2; i <= 500; i++) {
        for(int j = 2; j <= 500; j++) {
            if(i != j) {
                dp[i][j] = (1 << 30);
                for(int k = 1; k < i; k++) {
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                }
                for(int k = 1; k < j; k++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
        }
    }
    // for(int i = 1; i <= 5; i++) {
    //     for(int j = 1; j <= 5; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << dp[n][m] << endl;
    

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

