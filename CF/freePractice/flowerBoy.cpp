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
    ll size;
    vll heap;
    void init(ll n) {
        size = 1;
        while(size < n) size *= 2;
        heap.assign(size * 2, (1LL << 60));
    }
    void update(ll i, ll v, ll x, ll l, ll r) {
        if(l + 1 == r) {
            heap[x] = v;
            return;
        }
        ll mid = (l + r) / 2;
        if(mid > i) {
            update(i, v, 2 * x + 1, l, mid);
        }
        else {
            update(i, v, 2 * x + 2, mid, r);
        }
        heap[x] = min(heap[2 * x + 1], heap[2 * x + 2]);
    }
    void update(ll i, ll v) {
        update(i, v, 0, 0, size);
    }

    ll query(ll l, ll r, ll x, ll lx, ll rx) {
        if(lx >= l && rx <= r) {
            return heap[x];
        }

        if(rx <= l || lx >= r) return (1LL << 60);
        
        ll mid = (lx + rx) / 2;
        ll left = query(l, r, 2 * x + 1, lx, mid);
        ll right = query(l, r, 2 * x + 2, mid, rx);
        return min(left, right);
    }
    ll query(ll l, ll r) {
        return query(l, r, 0, 0, size);
    }
};

void solve(){        
    ll n, m;
    cin >> n >> m;
    vll a(n), b(m);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;

    segTree seg;
    seg.init(m);
    for(int i = 0; i < m; i++) {
        seg.update(i, b[i]);
    }

    vll pref(n), suff(n);
    ll p = 0;

    for(int i = 0; i < n; i++) {
        if(p == m) {
            cout << 0 << endl;
            return;
        }

        if(a[i] >= b[p]) {
            p++;
        }
        pref[i] = p;
    }
    if(p == m) {
        cout << 0 << endl;
        return;
    }
    ll c = 0;
    p = m - 1;
    for(int i = n - 1; i > -1; i--) {
        if(a[i] >= b[p]) {
            p--;
            c++;
        }
        suff[i] = c;
    }



    ll mini = (1LL << 60);

    for(int i = 0; i < n; i++) {
        if(i == n - 1) {
            if(pref[i] == m - 1) {
                mini = min(mini, b[m - 1]);
            }
            continue;
        }

        if(i == 0 && suff[i] == m - 1) {
            mini = min(mini, b[0]);
        }


        if(pref[i] + suff[i + 1] >= m - 1) {
            ll left = max(0LL, m - suff[i + 1] - 1);
            ll right = min(m, pref[i] + 1);
            mini = min(mini, seg.query(left, right));
        }
    }

    if(mini == (1LL << 60)) {
        cout << -1 << endl;
        return;
    }
    cout << mini << endl;
    
    
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

