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
    ll x, y, a;
    cin >> x >> y >> a;
    ll l = 0;
    ll r = (1LL << 32);
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(mid * x + mid * y > a) {
            r = mid;
        }
        else l = mid;
    }

    ll res = r * x + r * y;
    if(res - y > a) {
        cout << "NO" << endl;
        return;
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

