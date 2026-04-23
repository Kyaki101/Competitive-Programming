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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    vector<pair<ll, ll>> bef, aft;
    ll p = 0;
    ll suma = 0;
    for(int i = 0; i < n; i++) {
        suma += a[i];
        if(suma >= k) {
            bef.PB({p, i}); 
            p = i + 1;
            suma = 0;
        }
    }
    suma = 0;
    for(int i = n - 1; i > -1; i--) {
        suma += a[i];
        if(suma >= k) {
            aft.PB({i, p});
            p = i - 1;
            suma = 0;
        }

    }

    vector<ll> pref(n), suff(n);
    for(const auto &[x, y] : bef) {
        pref[y] = 1;
    }
    for(const auto &[x, y] : aft) suff[x] = 1;

    for(int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + pref[i];
    }
    for(int i = n - 2; i > -1; i--) {
        suff[i] = suff[i + 1] + suff[i];
    }
    auto valid = [&](ll l, ll r) {
        ll ans = 0;
        if(l > 0) {
            ans += pref[l - 1];
        }
        if(r < n - 1) ans += suff[r + 1];
        return ans >= m;
    };
    if(pref[n - 1] < m) {
        cout << -1 << endl;
        return;
    }


    ll l = 0;
    ll maxi = 0;
    ll acum = 0;
    for(int r = 0; r < n; r++) {
        acum += a[r];
        while(l < r && !valid(l, r)) {
            acum -= a[l];
            l++;
        }
        if(valid(l, r)) maxi = max(acum, maxi);
    }
    cout << maxi << endl;
    

    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        #ifdef ICPC 
            cout << "--------------------------------------------------" << endl;
        #endif // 
    }
    #ifdef ICPC 
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}

