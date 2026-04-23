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

ll height(ll node, vector<vll> &g, vector<bool>& vis) {
    vis[node] = true;
    ll ans = 0;
    for(auto i : g[node]) {
        if(!vis[i]) {
            ans = max(ans, 1 + height(i, g, vis));
        }
    }
    return ans;
}

void fillLev(ll node, ll d, vector<vll> &g, vector<bool> &vis, vll &lev, vll &parents) {
    vis[node] = true;
    lev[d] ++;
    bool check = false;
    for(auto i : g[node]) {
        if(!vis[i]) {
            fillLev(i, d + 1, g, vis, lev, parents);
            check = true;
        }
    }
    if(check) {
        parents[d + 1] ++;
    }
    
}



void solve(){        
    ll n;
    cin >> n;
    vector<vll> g(n + 1);
    for(int i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        g[a].PB(b);
        g[b].PB(a);
    }
    vector<bool> vis(n + 1);
    ll h = height(1, g, vis) + 1;
    vll lev(h), parents(h);

    vis.assign(n + 1, false);
    fillLev(1, 0, g, vis, lev, parents);


    ll maxi = 0;
    ll chokes = 0;

    for(int i = 1; i < (ll)lev.size(); i++) {
            maxi = max(maxi, lev[i]);
    }

    for(int i = 0; i < (ll)lev.size() - 1; i++) {
        if(parents[i + 1] == 1 && lev[i + 1] == maxi) chokes++;
    }
    cout << maxi + (chokes > 0) << endl;

    
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

