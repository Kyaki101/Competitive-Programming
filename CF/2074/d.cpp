#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
typedef long long int ll;
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll> > a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i].second;
    }

    map<ll, ll> h;

    for(int i = 0; i < n; i++) {
        for(ll j = a[i].first - a[i].second, x = 0 - a[i].second; j <= a[i].first + a[i].second; j++, x++) {
            if(h.find(j) == h.end()) h[j] = 0;
            ll r = 1 << 30;
            ll l = 0;
            while(l + 1 < r) {
                ll mid = (r + l) / 2;
                if(x * x + mid * mid <= a[i].second * a[i].second) l = mid;
                else r = mid;
            }

            h[j] = max(h[j], l);
            
        }
    }
    ll ans = 0;
    for(auto i : h) {
        ans += (i.second * 2) + 1;

    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

