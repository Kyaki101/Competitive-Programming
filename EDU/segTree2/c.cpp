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
    vector<ll> heap;

    void init(ll n) {
        size = 1;
        while(size < n) size *= 2;
        heap.assign(size * 2, 0);
    }

    ll query(ll n, ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            if(heap[x] < n) return -1;
            return lx;
        }
        ll mid = (lx + rx) / 2;
        if(heap[2 * x + 1] >= n) {
            return query(n, 2 * x + 1, lx, mid);
        }
        return query(n, 2 * x + 2, mid, rx);

    }

    ll query(ll n) {
        return query(n, 0, 0, size);
    }


    void set(ll i, ll v, ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            heap[x] = v;
            return;
        }
        ll mid = (rx + lx) / 2;
        if(i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        }
        else {
            set(i, v, 2 * x + 2, mid, rx);
        }

        heap[x] = max(heap[2 * x + 1], heap[2 * x + 2]);
    }

    void set(ll i, ll v) {
        set(i, v, 0, 0, size);
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
        ll opt;
        cin >> opt;
        if(opt == 1) {
            ll i, v;
            cin >> i >> v;
            st.set(i, v);
        }
        else {
            ll k;
            cin >> k;
            cout << st.query(k) << endl;;
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

