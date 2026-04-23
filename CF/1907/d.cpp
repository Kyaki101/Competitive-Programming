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
    vector<pair<ll, ll>> a(n);
    for(auto &[x, y]: a) {
        cin >> x >> y;
    }
    auto check = [&](ll mid) {
        ll left = 0;
        ll right = 0;
        for(int i = 0; i < n; i++) {
            ll t = left - mid;
            ll e = right + mid;
            if(e < a[i].first) {
                return false;
            }
            if(t > a[i].second) {
                return false;
            }
            right = min(a[i].second, e);
            left = max(a[i].first, t);
        }
        return true;
    };

    ll l = -1;
    ll r = 2000000000;
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(check(mid)) {
            r = mid;
        }
        else l = mid;
    }
    cout << r << endl;
    
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

