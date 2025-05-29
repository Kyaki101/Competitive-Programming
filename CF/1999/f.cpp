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

vector<ll> facts(200020);

ll expo(ll n, ll x) {
    if(x == 0) return 1;
    if(x & 1) return ((n % MOD) * (expo(n, x - 1) % MOD)) % MOD;
    ll y = expo(n, x / 2);
    return ((y % MOD) * (y % MOD)) % MOD;
}

void solve(){        
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll ones = 0;
    ll zeroes = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 1) ones ++;
        else zeroes ++;
    }

    ll ini = k / 2 + 1;

    ll count = 0;
    for(int i = ini; i <= k; i++) {
        if(ones < i || zeroes < (k - i)) {
            continue;
        }
        ll fUp = facts[ones];
        ll fDown = ((facts[i] % MOD) * (facts[ones - i] % MOD)) % MOD;
        fDown = expo(fDown, MOD - 2);
        ll first = ((fUp % MOD) * (fDown % MOD)) % MOD;
        ll sUp = facts[zeroes];
        ll sDown = ((facts[k - i] % MOD) * (facts[zeroes - (k - i)] % MOD)) % MOD;
        sDown = expo(sDown, MOD - 2);
        ll second = ((sUp % MOD) * (sDown % MOD)) % MOD;
        ll ans = ((first % MOD) * (second % MOD)) % MOD;
        count = ((count % MOD) + (ans % MOD)) % MOD;
    }
    cout << count << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    facts[0] = 1;
    for(int i = 1; i < 200020; i++) {
        facts[i] = (i * (facts[i - 1] % MOD)) % MOD;

    }
    while(t--){
        solve();
    }return 0;
}

