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

void solve(){        
    ll n, m;
    cin >> n >> m;
    vll a(n), b(m);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    sort(ALL(b));
    sort(a.rbegin(), a.rend());

    ll x = 0;
    ll ans = 0;
    ll p = 0;
    ll acum = 0;
    for(int i = 0; i < n; i++) {
        if(p == m) {
            ans += a[i];
            continue;
        }

        x++;
        if(x == b[p]) {
            ans += acum;
            x = 0;
            p++;
            acum = 0;
            continue;
        }

        acum += a[i];
    }
    cout << ans + acum << endl;

    
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

