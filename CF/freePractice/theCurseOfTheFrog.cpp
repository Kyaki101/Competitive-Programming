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
    ll n, x;
    cin >> n >> x;
    vll a(n);
    vll b(n);
    vll c(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    ll noRoll = 0;
    ll maxRoll = 0;
    for(int i = 0; i < n; i++) {
        noRoll += a[i] * (b[i] - 1);
        if(a[i] * b[i] - c[i] > maxRoll) {
            maxRoll = a[i] * b[i] - c[i];
        }
    }
    if(maxRoll <= 0) {
        if(noRoll >= x) {
            cout << 0 << endl;
            return;
        }
        cout << -1 << endl;
        return;
    }

    ll goal = x - noRoll;
    if(goal <= 0) {
        cout << 0 << endl;
        return;
    }
    ll ans = goal / maxRoll;
    if(ans * maxRoll + noRoll < x) {
        cout << goal / maxRoll + 1 << endl;
        return;
    }
    cout << goal / maxRoll << endl;




    
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

