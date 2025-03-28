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
    vector<ll> a(n);
    vector<ll> b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m ; i++) {
        cin >> b[i];
    }
    sort(ALL(b));
    a[0] = min(b[0] - a[0], a[0]);
    for(int i = 1; i < n; i++) {
        ll r = m;
        ll l = -1;
        while(l + 1 < r) {
            ll mid = (l + r) / 2;
            if(b[mid] - a[i] >= a[i - 1]) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        if(r != m) {
            if(a[i] < a[i - 1]) {
                a[i] = b[r] - a[i];
            }
            else a[i] = min(a[i], b[r] - a[i]);
        }
    }

    for(int i = 1; i < n; i++) {
        if(a[i] < a[i - 1]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

