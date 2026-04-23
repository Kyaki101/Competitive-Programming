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
    vll pref(n);
    vll suff(n);
    ll curr = 0;
    for(int i = 0; i < n; i++) {
        curr = pref[i] = gcd(a[i], curr);
    }
    curr = 0;
    for(int i = n - 1; i > -1; i--) {
        curr = suff[i] = gcd(a[i], curr);
    }
    ll ans = 0;
    for(int i = 0; i < n - 1; i++) {
        ans += min(suff[i], pref[i]);
    }
    cout<< ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

