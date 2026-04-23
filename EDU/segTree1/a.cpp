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

struct segTree {
    vector<ll> heap;
    ll size;
    void init(ll n) {
        size = 1;
        while(size < n) {
            size *= 2;
        }
        heap.assign(size * 2, 0);
    }
    void set(ll i, ll v, ll x, ll lx, ll rx) {
        if(lx + 1 == rx) {
            heap[x] = v;
            return;
        }
        ll mid = (lx + rx) / 2;
        if(mid > i) {
            set(i, v, 2 * x + 1, lx, mid);
        }
        else set(i, v, 2 * x + 2, mid, rx);
        heap[x] = heap[2 * x + 1] + heap[2 * x + 2];
    }
    void set(ll i, ll v) {
        set(i, v, 0, 0, size);
    }

    ll query(ll l, ll r, ll x, ll lx, ll rx) {
        if(lx >= l && rx <= r) {
            return heap[x];
        }
        if(rx <= l || lx >= r) {
            return 0;
        }
        ll mid = (lx + rx) / 2;
        ll izq = query(l, r, 2 * x + 1, lx, mid);
        ll der = query(l, r, 2 * x + 2, mid, rx);
        return izq + der;
    }
    ll query(ll l, ll r) {
        return query(l, r, 0, 0, size);
    }

};

void solve(){        
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for(auto &i : a) {
        cin >> i;
    }
    segTree sTree;
    sTree.init(n);
    for(int i = 0; i < n; i++) {
        sTree.set(i, a[i]);
    }
    while(q--) {
        ll t, x, y;
        cin >> t >> x >> y;
        if(t == 1) {
            sTree.set(x, y);
        }
        if(t == 2) {
            cout << sTree.query(x, y) << endl;
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

