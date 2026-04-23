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

ll block;


struct query {
    ll l;
    ll r;
    ll index;
};

bool cmp(const query &a, const query &b) {
    if(a.l / block == b.l / block) {
        return a.r < b.r;
    }
    return a.l / block < b.l / block;
}

void solve(){        
    ll n, q;
    cin >> n >> q;
    vll a(n);
    for(auto &i : a) cin >> i;
    block = ceil(sqrt(n));
    
    ll l = 0;
    ll r = -1;
    vector<query> queries;
    ll index = 0;
    while(q--) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        queries.PB({x, y, index});
        index ++;
    }
    sort(ALL(queries), cmp);

    vll vals = a;
    sort(ALL(vals));
    vals.erase(unique(ALL(vals)), vals.end());

    for(auto &x : a) {
        x = lower_bound(ALL(vals), x) - vals.begin();
    }

    vll mapa(n, 0);
    ll dist = 0;

    auto addRight = [&]() {
        r++;
        if(mapa[a[r]] == 0) dist ++;
        mapa[a[r]] ++;
    };

    auto addLeft = [&]() {
        l--;
        if(mapa[a[l]] == 0) dist ++;
        mapa[a[l]] ++;
    };

    auto removeRight = [&]() {
        mapa[a[r]] --;
        if(mapa[a[r]] == 0) dist --;
        r--;
    };

    auto removeLeft = [&]() {
        mapa[a[l]] --; 
        if(mapa[a[l]] == 0) dist--;
        l++;
    };

    vector<pair<ll, ll>> ans;
    for(auto &[x, y, i] : queries) {
        while(r < y) addRight();
        while(l > x) addLeft();
        while(l < x) removeLeft();
        while(r > y) removeRight();

        ans.PB({i, dist});
    }
    sort(ALL(ans));
    for(auto &[x, y] : ans) {
        cout << y << endl;
    }
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

