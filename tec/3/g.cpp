#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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


template<class T, class cmp>
using ordered_set = tree<T, null_type, cmp, rb_tree_tag,
      tree_order_statistics_node_update>;

const int MAX = 2e5+20, MOD = 1e9+7;
ll n;

struct pos{
    ll x, y, dir;
};

struct cmp{
    bool operator()(const pos &a, const pos &b) const {
        if(a.x == b.x) {
            if(a.y == b.y) return a.dir < b.dir;
            return a.y < b.y;
        }
        return a.x < b.x;
    }
};

void solve(){        
    ll a, b, d;
    cin >> a >> b >> d;
    map<ll, ordered_set<ll, less<ll>>> xAxis, yAxis;
    for(int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        xAxis[x].insert(y);
        yAxis[y].insert(x);
    }
    map<pos, ll, cmp> vis;


    pos curr = {a, b, 0};
    ll bruh = 0;


    auto east = [&]() {
        if(yAxis.find(curr.y) == yAxis.end()) {
            curr.x += d;
            d = 0;
            return;
        }
        ordered_set<ll, less<ll>> & axis = yAxis[curr.y];
        ll would = axis.order_of_key(curr.x);
        if(would == (ll)axis.size()) {
            curr.x += d;
            d = 0;
            return;
        }
        ll limit = *axis.find_by_order(would);
        ll dist = min(d, (limit - 1) - curr.x);
        d -= dist;
        curr.x += dist;
        bruh += dist;
        return;


    };

    auto north = [&]() {
        if(xAxis.find(curr.x) == xAxis.end()) {
            curr.y += d;
            d = 0;
            return;
        }
        ordered_set<ll, less<ll>> & axis = xAxis[curr.x];
        ll would = axis.order_of_key(curr.y);
        if(would == (ll)axis.size()) {
            curr.y += d;
            d = 0;
            return;
        }
        ll limit = *axis.find_by_order(would);
        ll dist = min(d, (limit - 1) - curr.y);
        d -= dist;
        curr.y += dist;
        bruh += dist;
        return;


    };

    auto west = [&]() {
        if(yAxis.find(curr.y) == yAxis.end()) {
            curr.x -= d;
            d = 0;
            return;
        }
        ordered_set<ll, less<ll>> & axis = yAxis[curr.y];
        ll would = axis.order_of_key(curr.x);
        if(would == 0LL) {
            curr.x -= d;
            d = 0;
            return;
        }
        ll limit = *axis.find_by_order(would - 1);
        ll dist = min(d, curr.x - (limit + 1));
        d -= dist;
        curr.x -= dist;
        bruh += dist;
        return;


    };

    auto south = [&]() {
        if(xAxis.find(curr.x) == xAxis.end()) {
            curr.y -= d;
            d = 0;
            return;
        }
        ordered_set<ll, less<ll>> & axis = xAxis[curr.x];
        ll would = axis.order_of_key(curr.y);
        if(would == 0LL) {
            curr.y -= d;
            d = 0;
            return;
        }
        ll limit = *axis.find_by_order(would - 1);
        ll dist = min(d, curr.y - (limit + 1));
        d -= dist;
        curr.y -= dist;
        bruh += dist;
        return;


    };

    curr.dir = 3;
    while(d) {

        curr.dir = (curr.dir + 1) % 4;
        if(vis.find(curr) != vis.end() && d >= bruh - vis[curr]) {
            ll dist = bruh - vis[curr];
            d -= dist * (d / dist);
        }
        vis[curr] = bruh;
        if(curr.dir == 0) {
            east();
        }
        else if(curr.dir == 1) {
            north();
        }
        else if(curr.dir == 2) {
            west();
        }
        else {
            south();
        }

    }
    cout << curr.x << ' ' << curr.y << endl;
    

    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(cin >> n){
        if(n != 0) solve();
        #ifdef ICPC 
            cout << "--------------------------------------------------" << endl;
        #endif // 
    }
    #ifdef ICPC 
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}

