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

void solve(){        
    ll n;
    cin >> n;
    vll a(n);
    for(auto &i : a) cin >> i;
    vector<vll> count(n + 1);
    vector<ll> dp(n);
    for(int i = 0; i < n; i++) {
        count[a[i]].PB(i);
        if(count[a[i]].size() >= a[i]) {
            ll start = count[a[i]][count[a[i]].size() - a[i]];
            ll bef;
            if(start == 0) bef = 0;
            else bef = dp[start - 1];
            ll bef2;
            if(i == 0) bef2 = 0;
            else bef2 = dp[i - 1];
            dp[i] = max(bef2, bef + a[i]);
        }
        else {
            if(i == 0) dp[i] = 0;
            else dp[i] = dp[i - 1];
        }
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

