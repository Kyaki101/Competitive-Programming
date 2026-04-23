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
    ll n;
    cin >> n;
    vll a(n * 2);
    for(auto &i : a) cin >> i;
    map<ll, ll> mapa;
    ll ans = 0;
    ll odds = 0;
    bool found = false;
    for(auto i : a) mapa[i] ++;
    ll fs = 0;
    for(auto [x, y] : mapa) {
        if(y & 1) {
            ans ++;
            odds ++;
            if(y >= 3) found = true;
            continue;
        }
        ll j = y / 2;
        if(j & 1) {
            ans += 2;
        }
        else {
            fs ++;
        }
    }
    if((fs & 1) && fs > 0 && (found || odds >= 2)) {
        cout << 2 * fs + ans << endl;
        return;
    }
    if(!(fs & 1)) {
        cout << 2 * fs + ans << endl;
        return;
    }
    cout << 2 * (fs - 1) + ans << endl;
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

