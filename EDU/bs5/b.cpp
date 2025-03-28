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


bool possible(ll n, ll x, ll k) {
    ll before = 0;
    for(int i = 1; i <= n; i++) {
        ll l = 0;
        ll r = n * n + 2;
        while(l + 1 < r) {
            ll mid = (l + r) / 2;
            if(mid * i < x) {
                l = mid;
            }
            else r = mid;
        }
        before += min(l , n);
    }

    return before < k;

}

void solve(){        
    ll n, k;
    cin >> n >> k;

    ll l = 1;
    ll r = n * n + 1;
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(possible(n, mid, k)) {
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

