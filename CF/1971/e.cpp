#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
ll n;

void solve(){        
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> a(k + 1, 0);
    vector<ll> b(k + 1, 0);
    for(int i = 1; i < k + 1; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= k; i++) {
        cin >> b[i];
    }

    for(int i = 0; i < q; i++) {
        ll x;
        cin >> x;
        ll r = k;
        ll l = 0;
        while(l + 1 < r) {
            ll mid = (l + r) / 2;
            if(a[mid] <= x) l = mid;
            else r = mid;
        }
        if(x == a[l]) {
            cout << b[l] << ' ';
            continue;
        }
        ll dist = x - a[l];
        ll ans = b[l] + dist * (b[l + 1] - b[l]) / (a[l + 1] - a[l]);
        cout << ans << ' ';

    }
    cout << endl;
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

