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

struct four {
    ll first;
    ll second;
    ll third;
    ll fourth;
};

struct segTree {
    ll size;
    vector<four> sums;

    void init(ll n) {
        size = 1;
        while(size < n) size *= 2;
        sums.assign(2 * size, {0, 0, 0, 0});
    }

    void compose(ll x) {
        ll left = 2 * x + 1;
        ll right = 2 * x + 2;
        sums[x].first = 0;
        sums[x].first = max(sums[x].first, sums[left].first);
        sums[x].first = max(sums[x].first, sums[right].first);
        sums[x].first = max(sums[x].first, sums[left].third + sums[right].second);
        sums[x].second = max(sums[left].second, sums[left].fourth + sums[right].second);
        sums[x].third = max(sums[right].third, sums[right].fourth + sums[left].third);
        sums[x].fourth = sums[left].fourth + sums[right].fourth;
    }

    void set(ll i, ll v, ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            sums[x] = {max(v, 0LL), max(v, 0LL), max(v, 0LL), v};
            return;
        }
        ll mid = (lx + rx) / 2;
        if(i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        }
        else {
            set(i, v, 2 * x + 2, mid, rx);
        }

        compose(x);
        
    }

    void set(ll i, ll v) {
        return set(i, v, 0, 0, size);
    }

    ll query() {
        return sums[0].first;
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
    cout << st.query() << endl;
    for(int i = 0; i < m; i++) {
        ll j, v;
        cin >> j >> v;
        st.set(j, v);
        cout << st.query() << endl;
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

