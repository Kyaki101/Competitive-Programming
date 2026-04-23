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
    if(x & 1) {
        return ((n % MOD) * (expo(n, x - 1) % MOD)) % MOD;
    }
    ll y = expo(n, x / 2);
    return ((y % MOD) * (y % MOD)) % MOD;
}



ll gauss(ll n) {
    return (n * (n + 1LL)) / 2LL;
}


ll powerSeries(ll k, ll x) {
    if(x == 1) {
        return (k + 1) % MOD;
    }
    ll top = ((expo(k, x + 1) % MOD) - 1 + MOD) % MOD;
    ll bottom = (k - 1) % MOD;
    return ((top % MOD) * (expo(bottom, MOD - 2) % MOD)) % MOD;

}

void solve(){        
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for(auto &[x, y] : a) {
        cin >> x >> y;
    }
    vector<ll> suffix(n, 1), prefix(n, 1);
    ll count = 1;
    ll i = 0;
    for(auto [_, c] : a) {
        count = ((count % MOD) * ((c + 1) % MOD)) % MOD;
        if(i == 0) {
            prefix[i] = (c + 1) % (MOD - 1);
        }
        else {
            prefix[i] = ((prefix[i - 1] % (MOD - 1)) * ((c + 1) % (MOD - 1))) % (MOD - 1);
        }
        i++;
    }
    for(int j = n -1; j > -1; j--) {
        if(j == n - 1) {
            suffix[j] = (a[j].second + 1) % (MOD - 1);
        }
        else {
            suffix[j] = ((suffix[j + 1] % (MOD - 1)) * ((a[j].second + 1) % (MOD - 1))) % (MOD - 1);
        }

    }
    ll prod = 1;
    i = 0;
    for(auto [x, y] : a) {
        ll curr = 1;
        ll left;
        ll right;
        if(i == 0) {
            left = 1;
        }
        else {
            left = prefix[i - 1];
        }
        if(i == n - 1) {
            right = 1;
        }
        else {
            right = suffix[i + 1];
        }
        curr = ((left % (MOD - 1)) * (right % (MOD - 1))) % (MOD - 1);
        ll inv = expo(y + 1, MOD - 2);
        ll pre = expo(x, gauss(y));
        ll nxt = expo(pre, curr);
        prod = ((prod % MOD) * (nxt % MOD)) % MOD;
        i++;
    }
    ll sum = 1;
    for(auto [x, y] : a) {
        ll pwSum = powerSeries(x, y);
        sum = ((sum % MOD) * (pwSum % MOD)) % MOD;
    }
    cout << count << ' ';
    cout << sum << ' ';
    cout << prod << endl;

    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

