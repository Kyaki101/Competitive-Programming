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
    vector<ll> mins;

    void init(ll n) {
        size = 1;
        while(size < n) size *= 2;
        mins.assign(size * 2, (1LL << 60));
    }

    void set(ll i, ll v, ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            mins[x] = v;
            return;
        }
        ll m = (lx + rx) / 2;
        if(i < m) {
            set(i, v, 2 * x + 1, lx, m);
        }
        else {
            set(i, v, 2 * x + 2, m, rx);
        }
        
        mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]);
    }

    void set(ll i, ll v) {
        set(i, v, 0, 0, size);
    }

    ll minimum(ll l, ll r, ll x, ll lx, ll rx) {
        if(lx >= r || l >= rx) return (1LL << 60);
        if(lx >= l && rx <= r) return mins[x];
        ll mid = (lx + rx) / 2;
        ll m1 = minimum(l, r, 2 * x + 1, lx, mid);
        ll m2 = minimum(l, r, 2 * x + 2, mid, rx);
        return min(m1, m2);
    }

    ll minimum(ll l, ll r) {
        return minimum(l, r, 0, 0, size);
    }

};

void solve(){        
    ll n, q;
    cin >> n >> q;

    segTree st;
    st.init(n);
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        st.set(i, x);
    }

    while(q --) {
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
            cout << st.minimum(l, r) << endl;
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

