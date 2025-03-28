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


ll behind(vector<pair<ll, ll> > & a, ll x) {
    ll pos = 0;

    for(int i = 0; i < a.size(); i++) {
        if(a[i].first >= x) {

        }
        else {
            pos += min(x - a[i].first, a[i].second - a[i].first + 1);
        }
    }

    return pos;
}

void solve(){        
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll> > a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    ll l = -(1LL << 40);
    ll r = (1LL << 40);

    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(behind(a, mid) <= k) l = mid;
        else r = mid;
    }
    cout << l << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}

