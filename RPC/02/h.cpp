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


bool good(ll x, ll n) {
    if((x * (x + 1)) / 2 <= n) return true;
    return false;

}

void solve(){        
    ll n;
    cin >> n;
    ll r = 1 << 30;
    ll l = 0;
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(good(mid, n)) {
            l = mid;
        }
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

