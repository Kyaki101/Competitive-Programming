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

void dfs(ll node, vector<vll> &g, vector<bool> &vis, vll &leaves) {
    ll count = 0;
    vis[node] = true;
    for(auto i : g[node]) {
        if(!vis[i]) {
            count++;
            dfs(i, g, vis, leaves);
        }
    }
    if(!count) leaves.PB(node);
    
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
    string s;
    cin >> s;
    s = '0' + s;
    vll leaves;
    vector<bool> vis(n + 1);
    dfs(1, g, vis, leaves);
    string bruh;
    for(auto i : leaves) bruh.PB(s[i]);

    ll ans = 0;
    bool turn = 0;
    ll full = 0;
    for(int i = 2; i <= n; i++) if(s[i] == '?')full ++;
    ll o = 0;
    for(auto i : bruh) if(i == '?') o++;
    full = full - o;

    if(s[1] != '?') for(int i = 0; i < (ll)bruh.size(); i++) {
        if(bruh[i] != '?' && s[1] != bruh[i]) {
            ans++;
            continue;
        }
        if(bruh[i] == '?' && !turn) {
            turn = 1;
            ans++;
        }
        else if(bruh[i] == '?' && turn) {
            turn = 0;
        }

    }

    if(s[1] != '?') {
        cout << ans << endl;
        return;
    }




    ll ones = 0, zeros = 0;
    for(auto i : bruh) {
        if(i == '1') ones++;
        if(i == '0') zeros++;
    }

    if(ones != zeros) {
        cout << max(ones, zeros) + o / 2 << endl;
        return;
    }

    if(full & 1) {
        cout << ones + (o + 1) / 2 << endl;
        return;
    }

    cout << ones + o / 2 << endl;






    
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

