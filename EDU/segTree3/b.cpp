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
        heap.assign(2 * size, 0);
    }

    void set(ll i, ll v, ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            heap[x] = v;
            return;
        }
        ll mid = (lx + rx) / 2;
        if(i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        }
        else {
            set(i, v, 2 * x + 2, mid, rx);
        }

        heap[x] = heap[2 * x + 1] + heap[2 * x + 2];
    }

    void set(ll i, ll v) {
        set(i, v, 0, 0, size);
    }


    ll query(ll l, ll r, ll x, ll lx, ll rx) {
        if(rx <= l || lx >= r) {
            return 0;
        }
        if(lx >= l && rx <= r) {
            return heap[x];
        }
        ll mid = (lx + rx) / 2;
        ll s1 = query(l, r, 2 * x + 1, lx, mid);
        ll s2 = query(l, r, 2 * x + 2, mid, rx);
        return s1 + s2;
    }

    ll query(ll i) {
        return query(i + 1, size, 0, 0, size);
    }


};

void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    segTree st;
    st.init(n);
    for(auto &i: a) {
        cin >> i;
    }
    vector<ll> ans(n);
    for(int i = n - 1; i > -1; i--) {
        ll front = st.query(i + 1);
        ans[i] = n - front - a[i];
        st.set(ans[i] - 1, 1);
        for(auto i : st.heap) {
            cout << i << ' ';
        }
        cout << endl;
    }
    for(auto i : ans) cout << i << ' ';
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

