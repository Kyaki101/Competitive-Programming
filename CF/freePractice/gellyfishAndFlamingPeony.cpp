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

const int MAX = 5001, MOD = 1e9+7;

vector<vll> g(MAX, vll(MAX, 0));

void solve() {
    ll n;
    cin >> n;
    vll a(n);
    ll k = 0;
    for(auto &i : a) {
        cin >> i;
        k = g[k][i];
    }
    vll f(MAX, (1 << 30));
    ll m = 0;

    for(auto &i : a) i /= k, f[i] = 0, m = max(m, i);

    for(int x = m; x > 0; x--) {
        for(int i = 0; i < n; i++) {
            ll y = a[i];
            f[g[x][y]] = min(f[g[x][y]], f[x] + 1);
        }
    }
    ll ans = max(f[1] - 1, 0LL);
    for(auto i : a) {
        if(i != 1) ans ++;
    }

    cout << ans << endl;
    
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    for(int i = 1; i < MAX; i++) g[i][0] = g[0][i] = g[i][i] = i;
    for(int i = 1; i < MAX; i++) {
        for(int j = 1; j < i; j++) {
            g[i][j] = g[j][i] = g[j][i % j];
        }
    }
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

