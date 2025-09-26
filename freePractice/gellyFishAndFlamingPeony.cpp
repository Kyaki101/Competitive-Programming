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

vector<ll> f(5001, 0);

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll k = 0;
    for(auto &i : a) {
        cin >> i;
        k = gcd(k, i);
    }
    bool stop = false;
    for(auto i : a) {
        if(k == i) stop = true;
    }
    if(stop) {
        ll cnt = 0;
        for(int i = 0; i < n; i++) if(a[i] != k) cnt++;
        cout << cnt << endl;
        return;
    }
    for(auto &i : a) i /= k;
    vector<ll> dp(5001, (1 << 30));
    dp[0] = 0;
    for(auto i : a) dp[i] = 1;

    for(int j = 0; j < n; j++) {
        auto new_dp = dp;
        for(int i = 0; i < 5001; i++) {
            if(dp[i] != (1 << 30)) {
                new_dp[gcd(a[j], i)] = min(dp[i] + 1, new_dp[gcd(a[j], i)]);
            }
        }
        dp.swap(new_dp);
    }
    cout << n + dp[1] - 2<< endl;

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

