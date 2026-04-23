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

bool dfs(vector<vll> &g, ll node, vector<bool> &vis) {
    vis[node] = true;
    bool bruh = true;
    for(auto child : g[node]) {
        if(vis[child]) return false;
        bruh = bruh && dfs(g, child, vis);
    }
    return bruh;
}

void solve(){        
    ll n;
    cin >> n;
    vector<string> mat(n);
    for(auto &i : mat) cin >> i;
    vector<vector<ll>> g(n);

    auto verify = [&](ll node, ll k, set<ll> &comp) {
        for(int i = 0; i < n; i++) {
            if(i == node || i == k) continue;
            if(mat[k][i] == '1' && mat[node][i] == '0') return false;
            if(mat[k][i] == '1') comp.insert(i);
        }
        return true;

    };

    for(int i = 0; i < n; i++) {
        set<ll> complement;
        for(int j = 0; j < n; j++) {
            if(i == j) {
                if(mat[i][j] != '1') {
                    cout << "NO" << endl;
                    return;
                }
                continue;
            }
            if(mat[i][j] == '1' && mat[j][i] == '1') {
                cout << "NO" << endl;
                return;
            }
            if(mat[i][j] == '1') {
                ll k = j;
                if(!verify(i, k, complement)) {
                    cout << "NO" << endl;
                    return;
                }

            }
        }
        for(int j = 0; j < n; j++) {
            if(mat[i][j] == '1' && i != j) {
                if(complement.find(j) == complement.end()) {
                    g[i].PB(j);
                }
            }
        }
    }


    vector<bool> vis(n, false);


    for(int i = 0; i < n; i++) {
        bool final = true;
        vis.assign(n, false);
        bool bruh = dfs(g, i, vis);

        for(int j = 0; j < n; j++) {
            final = final && vis[j];
        }
        if(final && bruh) {
            cout << "YES" << endl;
            for(int j = 0; j < n; j++) {
                for(auto child : g[j]) {
                    cout << j + 1 << ' ' << child + 1 << endl;
                }
            }
            return;
        }

    }

    cout << "NO" << endl;


    
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

