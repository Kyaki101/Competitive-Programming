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


ll expo(ll n, ll x) {
    if(x == 0) return 1;
    if(x & 1) return ((expo(n, x - 1) % MOD) * (n % MOD)) % MOD;
    ll y = expo(n, x / 2);
    return (y * y) % MOD;
}

void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    vll suff(n + 1, 0);
    for(int i = n - 1; i > -1; i--) {
        suff[i] = suff[i + 1] + a[i];
    }
    ll top = 0;
    for(int i = 0; i < n; i++) {
        top = (top + ((suff[i + 1] % MOD) * (a[i] % MOD)) % MOD) % MOD;
    }
    ll bot = (n * (n - 1)) / 2;
    bot %= MOD;
    bot = expo(bot, MOD - 2);
    cout << (top * bot) % MOD << endl;
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

