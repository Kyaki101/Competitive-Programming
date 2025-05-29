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
            if(v == -1) {
                if(sums[x] == 0) {
                    sums[x] = 1;
                    return;
                }
                sums[x] = 0;
                return;
            }
            sums[x] = v;
            return;
        }
        ll mid = (rx + lx) / 2;
        if(i < mid) set(i, v, 2 * x + 1, lx, mid); 
        else set(i, v, 2 * x + 2, mid, rx); 
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];

    }

    void set(ll i, ll v) {
        return set(i, v, 0, 0, size);
    }

    ll query(ll k, ll x, ll lx, ll rx) {
        if(rx - lx == 1) return lx;
        ll mid = (lx + rx) / 2;
        if(sums[2 * x + 1] > k) {
            return query(k, 2 * x + 1, lx, mid);
        }
        return query(k - sums[2 * x + 1], 2 * x + 2, mid, rx);
    }

    ll query(ll k) {
        return query(k, 0, 0, size);
    }
};

void solve(){        
    ll n, m;
    cin >> n >> m;
    segTree st;
    st.init(n);
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        st.set(i, x);
    }
    for(int i = 0; i < m; i++) {
        ll opt;
        cin >> opt;
        if(opt == 2) {
            ll k;
            cin >> k;
            cout << st.query(k) << endl;;
        }
        else {
            ll j;
            cin >> j;
            st.set(j, -1);
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

