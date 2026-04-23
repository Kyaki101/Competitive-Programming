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


ll msb(ll n) {
    ll ans = 0;
    for(int i = 0; i < 60; i++) {
        if(TEST(n, i)) ans = i;
    }
    return ans;
}

void solve(){        
    ll a, b;
    cin >> a >> b;
    ll ma = msb(a), mb = msb(b);
    if(mb > ma) {
        cout << -1 << endl;
        return;
    }
    ll e = CLEAR(a, ma);
    ll c = CLEAR(b, mb);
    if(mb == ma) {
        cout << 2 << endl;
        cout << e << ' ' << c << endl;
        return;
    }
    
    cout << 3 << endl;
    cout << e << ' ';
    cout << b << ' ';
    cout << (1 << (ma)) << endl;



    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

