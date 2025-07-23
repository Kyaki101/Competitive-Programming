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
    ll y = expo(n, x / 2) % MOD;
    return ((y % MOD) * (y % MOD)) % MOD;
}

void solve() {        
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    map<ll, ll> posA;
    map<ll, ll> posB;
    ll p = 0;
    for(auto &i : a) {
        cin >> i;
        posA[i] = p;
        p++;
    }
    p = 0;
    for(auto &i : b) {
        cin >> i;
        posB[i] = p;
        p++;
    }
    vector<ll> m1(n), m2(n);
    m1[0] = a[0]; m2[0] = b[0];
    for(int i = 1; i < n; i++) {
        m1[i] = max(m1[i - 1], a[i]);
    }

    for(int i = 1; i < n; i++) {
        m2[i] = max(m2[i - 1], b[i]);
    }

    for(int i = 0; i < n; i++) {
        ll inv = i - posB[m2[i]];
        if(m1[i] == m2[i]) {
            if(b[i - posA[m1[i]]] >= a[inv]) {
                ll ans = ((expo(2, m1[i]) % MOD) + (expo(2, b[i - posA[m1[i]]]) % MOD)) % MOD;
                cout << ans << ' ';
            }
            else {
                ll ans = ((expo(2, m2[i]) % MOD) + (expo(2, a[inv]) % MOD)) % MOD;
                cout << ans << ' ';
            }
        }
        else if(m1[i] > m2[i]) {
            ll ans = ((expo(2, m1[i]) % MOD) + (expo(2, b[i - posA[m1[i]]]) % MOD)) % MOD;
            cout << ans << ' ';
        }
        else {
            ll ans = ((expo(2, m2[i]) % MOD) + (expo(2, a[inv]) % MOD)) % MOD;
            cout << ans << ' ';

        }
    }
    cout << endl;
    
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

