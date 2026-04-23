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
#define pll pair<ll, ll>
typedef vector<ll> vll;

const int MAX = 2e5+20, MOD = 1e9+7;

struct segTree {
    ll size;
    vector<pll> heap;

    void init(long long unsigned n) {
        size = bit_ceil()
        heap.assign(2 * size, {(1LL << 60), 0});
    }

    void set(ll i, ll v, ll x, ll lx, ll rx) {
        if(lx + 1 == rx) {
            heap[x] = {v, 1};
            return;
        }
        ll mid = (rx + lx) / 2;
        if(mid > i) {
            set(i, v, 2 * x + 1, lx, mid);
        }
        else {
            set(i, v, 2 * x + 2, mid, rx);
        }
        auto left = heap[2 * x + 1];
        auto right = heap[2 * x + 2];
        if(left.first == right.first) {
            heap[x] = {left.first, left.second + right.second};
            return;
        }
        if(left.first < right.first) {
            heap[x] = left;
            return;
        }

        heap[x] = right;

    }
    void set(ll i, ll v) {
        set(i, v, 0, 0, size);
    }

    pll query(ll l, ll r, ll x, ll lx, ll rx) {
        if(lx >= l && rx <= r) {
            return heap[x];
        }
        if(rx <= l || lx >= r) {
            return {(1LL << 60), 0};
        }

        ll mid = (lx + rx) / 2;

        auto left = query(l, r, 2 * x + 1, lx, mid);
        auto right = query(l, r, 2 * x + 2, mid, rx);

        if(left.first == right.first) {
            return {right.first, right.second + left.second};
        }
        if(left.first < right.first) {
            return left;
        }
        return right;

    }
    pll query(ll l, ll r) {
        return query(l, r, 0, 0, size);
    }

};

void solve(){        
    ll n, q;
    cin >> n >> q;
    segTree sTree;
    sTree.init(n);
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    for(int i = 0; i < n; i++) {
        sTree.set(i, a[i]);
    }
    while(q--) {
        ll t, x, y;
        cin >> t >> x >> y;
        if(t == 1) {
            sTree.set(x, y);
        }
        else {
            auto temp = sTree.query(x, y);
            cout << temp.first << ' ' << temp.second << endl;
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

