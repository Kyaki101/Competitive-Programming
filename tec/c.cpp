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

pair<ll, ll> moves[8] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

ll val(ll i, ll j, ll n, ll m) {
    return i > -1 && i < n && j > -1 && j < m;
}




ll getMax(ll i, ll j, vector<vll> &a) {
    ll n = a.size();
    ll m = a[0].size();
    ll ans = -1 * (1 << 30);
    for(int k = 0; k < 4; k++) {
        ll x = i + moves[k].first;
        ll y = j + moves[k].second;
        if(val(x, y, n, m)) {
            ans = max(ans, a[x][y]);
        }
    }
    return ans;
}

void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<vll> a(n, vll(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    if(n == 1 && m == 1) {
        cout << a[0][0] << endl;
        return;
    }

    bool change = true;
    while(change) {

        vector<pair<ll, pair<ll, ll>>> bruh;


        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(getMax(i, j, a) < a[i][j]) bruh.PB({getMax(i, j, a), {j, i}});
            }
        }

        change = bruh.size();
        sort(ALL(bruh));
        

        for(auto &[x, y] : bruh) {
            a[y.second][y.first] = getMax(y.second, y.first, a);
        }
    }
    for(auto i : a) {
        for(auto j : i) cout << j << ' ';
        cout << endl;
    }
    

    
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

