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
    cin >> n;
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    vector<vector<pair<ll, ll>>> dp(n, vector<pair<ll, ll>>(n, {0, 0}));
    for(int j = 0; j < n; j++) {
        if((n - 1) & 1) {
            dp[n - 1][j].second = a[j];
        }
        else dp[n - 1][j].first = a[j];
    }
    ll sep = 1;
    for(int i = n - 2; i > -1; i--) {
        for(int j = 0; j + sep < n; j++) {
            if(i & 1) {
                if(a[j] + dp[i + 1][j + 1].second > a[j + sep] + dp[i + 1][j].second) {
                    dp[i][j] = {dp[i + 1][j + 1].first, a[j] + dp[i + 1][j + 1].second};
                }
                else {
                    dp[i][j] = {dp[i + 1][j].first, a[j + sep] + dp[i + 1][j].second};
                }
                continue;
            }

            if(a[j] + dp[i + 1][j + 1].first> a[j + sep] + dp[i + 1][j].first) {
                dp[i][j] = {a[j] + dp[i + 1][j + 1].first, dp[i + 1][j + 1].second};
            }
            else {
                dp[i][j] = {a[j + sep] + dp[i + 1][j].first, dp[i + 1][j].second};
            }

        }
        sep++;
    }

    // for(auto i : dp) {
    //     for(auto j : i) cout << "{ " << j.first << ' ' << j.second << " } ";
    //     cout << endl;
    // }

    cout << dp[0][0].first << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

