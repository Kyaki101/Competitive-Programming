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


struct unionFind {
    ll n;
    vector<ll> link;
    vector<ll> size;

    void init(ll tam) {
        n = tam;
        link.assign(n + 1, 0);
        size.assign(n + 1, 1);

        for(int i = 1; i <= tam; i++)
            link[i] = i;
    }

    ll find(ll x) {
        if(x == link[x]) return x;
        return link[x] = find(link[x]);
    }

    void unite(ll i, ll j) {
        i = find(i);
        j = find(j);
        if(i == j) return;

        if(size[i] < size[j]) swap(i, j);

        link[j] = i;
        size[i] += size[j];
    }
};

void solve(){        
    ll n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<vll> f(n + 1), g(n + 1);
    unionFind god, fix;
    god.init(n);
    fix.init(n);
    ll steps = 0;

    for(int i = 0; i < m1; i++) {
        ll a, b;
        cin >> a >> b;
        f[a].PB(b);
        f[b].PB(a);
    }

    for(int i = 0; i < m2; i++) {
        ll a, b;
        cin >> a >> b;
        god.unite(a, b);
        g[a].PB(b);
        g[b].PB(a);
    }

    vector<bool> vis(n + 1, false);

    for(int i = 1; i <= n; i++) {
        vis[i] = true;
        for(auto child : f[i]) {
            if(god.find(i) != god.find(child) && vis[child]) {
                continue;

            } 
            if(god.find(i) != god.find(child) && !vis[child]) {
                 steps++;
            }

            else {
                fix.unite(i, child);
            }
        }
    }


    vis.assign(n + 1, false);



    for(int i = 1; i <= n; i++) {
        vis[i] = true;
        for(auto child : g[i]) {
            if(vis[child]) continue;
            if(fix.find(i) != fix.find(child)) {
                fix.unite(i, child);
                steps ++;
            }
        }
    }
    cout << steps << endl;


    
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

