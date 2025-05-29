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

ll expo(ll n, ll x) {
    if(x == 0) return 1;
    if(x & 1) return ((n % MOD) * (expo(n, x - 1) % MOD)) % MOD;
    ll y = expo(n, x / 2);
    return ((y % MOD) * (y % MOD)) % MOD;
}

void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<ll> vals(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j += i) {
            vals[i] = max(vals[i], a[j]);
        }
    }
    sort(vals.rbegin(), vals.rend());
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans = (ans + (vals[i] * (expo(2, n - (i + 1)) % MOD) % MOD)) % MOD;
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

