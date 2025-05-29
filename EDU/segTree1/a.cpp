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

struct segTree {

    ll size;
    vector<ll> sums;

    void init(ll n) {
        size = 1;
        while(size < n) size *= 2;
        sums.assign(size * 2, 0);
    }

    void set(ll i, ll v, ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            sums[x] = v;
            return;
        }
        ll m = (lx + rx) / 2;
        if(i < m) {
            set(i, v, 2 * x + 1, lx, m);
        }
        else {
            set(i, v, 2 * x + 2, m, rx);
        }

        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];

    }

    void set(ll i, ll v) {
        set(i, v, 0, 0, size);
    }

    ll sum(ll l, ll r, ll x, ll lx, ll rx) {
        if(lx >= r || l >= rx) return 0;
        if(lx >= l && rx <= r) return sums[x];
        ll m = (lx + rx) / 2;
        ll s1 = sum(l, r, 2 * x + 1, lx, m);
        ll s2 = sum(l, r, 2 * x + 2, m, rx);
        return s1 + s2;

    }

    ll sum(ll l, ll r) {
        return sum(l, r, 0, 0, size);
    }
};


void solve(){        
    ll n, m;
    cin >> n >> m;
    
    segTree st;
    st.init(n);

    for(int i = 0; i < n; i++) {
        int v;
        cin >> v;
        st.set(i, v);
    }
    while(m--) {
        ll op;
        cin >> op;
        if(op == 1) {
            ll i, v;
            cin >> i >> v;
            st.set(i, v);
        }
        else {
            ll l, r;
            cin >> l >> r;
            cout << st.sum(l, r) << endl;
        }
    }
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

