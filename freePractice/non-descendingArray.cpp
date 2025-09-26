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

const int MAX = 2e5+20, MOD = 998244353;


void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    vll dp(n, 0);
    dp[0] = 2;
    if(a[0] > b[0]) swap(a[0], b[0]);
    for(int i = 1; i < n; i++) {
        if(a[i] > b[i]) swap(a[i], b[i]);
        if(b[i - 1] > a[i]) {
            dp[i] = dp[i - 1];
        }
        else dp[i] = dp[i - 1] * 2;
        dp[i] %= MOD;
    }
    cout << dp[n - 1] << endl;
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

