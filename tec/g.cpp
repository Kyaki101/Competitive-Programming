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

bool check(ll mid, vll & a, set<ll> &b) {
    bool bruh = true;
    for(int i = 0; i < (ll)a.size(); i++) {
        auto it = b.lower_bound(a[i]);
        if(it != b.begin()) {
            auto nxt = it;
            nxt --;
            if(it == b.end()) {
                bruh = bruh && abs(a[i] - *nxt) <= mid;
                continue;
            }
            bruh = bruh && (abs(a[i] - *nxt) <= mid || abs(a[i] - *it) <= mid);
            continue;
        }
        bruh = bruh && abs(a[i] - *it) <= mid;
    }
    return bruh;
}

void solve(){        
    ll n, m;
    cin >> n;
    cin >> m;
    vll a(n);
    set<ll> b;
    for(auto &i : a) cin >> i;
    for(int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        b.insert(x);
    }
    ll l = -1;
    ll r = (1LL << 40);
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(check(mid, a, b)) r = mid;
        else l = mid;
    }
    cout << r << endl;



    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
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

