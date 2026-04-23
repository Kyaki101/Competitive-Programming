#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T, class cmp>
using ordered_set = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

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

bool cmp(const pair<ll, ll> &a, const pair<ll, ll> &b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

void solve(){        
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> a(n);
    for(auto &i : a) cin >> i.first;
    for(auto &i : a) cin >> i.second;
    ordered_set<pair<ll, ll>, less<pair<ll, ll>>> elimed;
    ordered_set<pair<ll, ll>, less<pair<ll, ll>>> pissed;
    map<ll, ll> ord;
    
    ll ans = 0;

    sort(ALL(a));

    for(int i = 0; i < n; i++) {
        pissed.insert({a[i].first, ord[a[i].first]});
        ord[a[i].first] ++;
        elimed.insert({a[i].second, ord[a[i].second]});
        ord[a[i].second] ++;

        ll done = elimed.order_of_key({a[i].first, -1});
        ll mad = pissed.order_of_key({a[i].first, -1});
        mad -= done;
        if(mad <= k) ans = max(ans, (n - done) * a[i].first);
    }

    pissed.clear(), ord.clear(), elimed.clear();

    sort(ALL(a), cmp);

    for(int i = 0; i < n; i++) {
        pissed.insert({a[i].first, ord[a[i].first]});
        ord[a[i].first] ++;
    }

    for(int i = 0; i < n; i++) {
        elimed.insert({a[i].second, ord[a[i].second]});
        ord[a[i].second] ++;

        ll done = elimed.order_of_key({a[i].second, -1});
        ll mad = pissed.order_of_key({a[i].second, -1});
        mad -= done;
        if(mad <= k) ans = max(ans, (n - done) * a[i].second);
    }

    cout << ans << endl;






    
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

