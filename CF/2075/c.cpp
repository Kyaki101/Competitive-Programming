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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);

    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(ALL(a));
    ll ans = 0;

    for(int i = 1; i < n; i++) {
        ll g;
        ll l = -1; 
        ll r = m;
        while(l + 1 < r) {
            ll mid = (l + r) / 2;
            if(a[mid] >= i) {
                r = mid;
            }
            else l = mid;
        }
        g = m - r;
        ll p;

        ll goal = n - i;
        l = -1; r = m;
        while(l + 1 < r) {
            ll mid = (l + r) / 2;
            if(a[mid] >= goal) {
                r = mid;
            }
            else l = mid;
        }
        p = m - r;
        ans += g * p - min(g, p);

    }
    cout << ans << endl;


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

