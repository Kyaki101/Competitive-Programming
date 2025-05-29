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


ll fill(vector<ll> & dp, ll x, vector<ll> & a) {
    if(x < 0) return (1 << 30);
    if(x == 0) return 0;
    if(dp[x]) return dp[x];

    ll mini = (1 << 30);
    for(int i = 0; i < a.size(); i++) {
        mini = min(mini, fill(dp, x - a[i], a));
    }
    return dp[x] = 1 + mini;

}

void solve(){        
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(ll &i : a) cin >> i;
    vector<ll> dp(x + 1);
    fill(dp, x, a);
    if(dp[x] >= (1 << 29)) {
        cout << -1 << endl;
        return;
    }
    cout << dp[x] << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

