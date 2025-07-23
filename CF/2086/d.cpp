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
vector<ll> factorial(500010);


ll binExpo(ll n, ll x) {
    if(x == 0) return 1;
    if(x & 1) return ((n % MOD) * (binExpo(n, x - 1) % MOD)) % MOD;
    ll y = binExpo(n, x / 2) % MOD;
    return ((y % MOD) * (y % MOD)) % MOD;
}

void solve(){        
    vector<ll> a(26);
    ll suma = 0;
    for(int i = 0; i < 26; i++) {
        cin >> a[i];
        suma += a[i];
    } 
    ll even = suma  / 2;
    ll odd = (suma + 1) / 2;
    vector<ll> dp(suma + 1);
    dp[0] = 1;
    for(int i = 0; i < 26; i++) {
        if(a[i] == 0) continue;
        for(int j = suma - a[i]; j >= 0; j--) {
            dp[j + a[i]] = dp[j] + dp[j + a[i]];
        }
    }
    ll upper = factorial[even] * factorial[odd];
    upper %= MOD;
    ll under = 1;
    for(int i = 0; i < 26; i++) {
        under = ((under % MOD) * (factorial[a[i]] % MOD)) % MOD;
    }

    under = binExpo(under, MOD - 2);
    ll tot = ((upper % MOD) * (under % MOD)) % MOD;
    tot = ((tot %MOD) * (dp[odd] % MOD)) % MOD;
    cout << tot << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    factorial[0] = 1;
    for(int i = 1; i < 500010; i++) {
        factorial[i] = ((i % MOD) * (factorial[i - 1] % MOD)) % MOD;
    }
    while(t--){
        solve();
    }return 0;
}

