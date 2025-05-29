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
    vector<pair<ll, ll>> mins;

    void init(ll n) {
        size = 1;
        while(size < n) size *= 2;
        mins.assign(size * 2, {(1LL << 60), 0});
    }


    void set(ll i, ll v, ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            mins[x] = {v, 1};
            return;
        }
        ll mid = (lx + rx) / 2;
        if(i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        }
        else {
            set(i, v, 2 * x + 2, mid, rx);
        }

        if(mins[2 * x + 1].first < mins[2 * x + 2].first) {
            mins[x] = mins[2 * x + 1];
            return;
        }
        if(mins[2 * x + 2].first < mins[2 * x + 1].first) {
            mins[x] = mins[2 * x + 2];
            return;
        }
        mins[x] = {mins[2 * x + 1].first, mins[2 * x + 1].second + mins[2 * x + 2].second};
    }

    void set(ll i, ll v) {
        set(i, v, 0, 0, size);
    }

    pair<ll, ll> query(ll l, ll r, ll x, ll lx, ll rx) {
        if(rx <= l || lx >= r) return {(1LL << 60), 0};
        if(l <= lx && r >= rx) return mins[x];
        pair<ll, ll> m1, m2;
        ll mid = (lx + rx) / 2;
        m1 = query(l, r, 2 * x + 1, lx, mid);
        m2 = query(l, r, 2 * x + 2, mid, rx);
        if(m1.first < m2.first) return m1;
        if(m2.first < m1.first) return m2;
        return {m2.first, m1.second + m2.second};

    }

    pair<ll, ll> query(ll l, ll r) {
        return query(l, r, 0, 0, size);
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

    while(q--) {
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
            pair<ll, ll> que = st.query(l, r);
            cout << que.first << ' ' << que.second << endl;
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

