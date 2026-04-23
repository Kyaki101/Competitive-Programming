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
    ll n, k;
    cin >> n >> k;
    vll a(n);
    for(auto &i : a) cin >> i;
    ll x;
    cin >> x;
    x --;
    ll origi = a[x];
    ll l = 0, r = n - 1;
    ll ans = 0;
    while(l < r) {
        while(a[l] == origi && l < x) {
            l ++;
            if(ans & 1) a[l] = !a[l];
        }
        while(a[r] == origi && r > x) {
            r --;
            if(ans & 1) a[r] = !a[r];
        }

        if(l == r) {
            break;
        }
        a[l] = !a[l];
        a[r] = !a[r];
        ans ++;

    }
    if(ans & 1) ans ++;

    cout << ans << endl;

    
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

