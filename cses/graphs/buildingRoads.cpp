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


struct UF { 
    vector<ll> link;
    vector<ll> size;
    void init(ll n) {
        link.assign(n + 1, 0);
        size.assign(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            link[i] = i;
            size[i] = 1;
        }
    }
    ll find(ll x) {
        while(link[x] != x) x = link[x];
        return x;
    }
    bool same(ll x, ll y) {
        return find(x) == find(y);
    }
    void unite(ll a, ll b) {
        if(same(a, b)) return;
        a = find(a);
        b = find(b);
        if(size[a] < size[b]) swap(a, b);
        size[a] += size[b];
        link[b] = a;
    }

};



void solve(){        
    ll n, m;
    cin >> n >> m;
    UF uf;
    uf.init(n);
    for(int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        uf.unite(a, b);
    }
    vll roads;
    for(int i = 2; i <= n; i++) {
        if(!uf.same(1, i)) {
            roads.PB(i);
            uf.unite(1, i);
        }
    }
    cout << roads.size() << endl;
    for(auto i : roads) {
        cout << 1 << ' ' << i << endl;
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

