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


bool possible(ll n, ll m, ll x, ll k) {
    return (n * m) - ((m / x) * n) >= k;
}

void solve(){        
    ll n, m, k;
    cin >> n >> m >> k;

    ll l = 0; ll r = m + 1;
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(possible(n, m, mid, k)) {
            r = mid;
        }
        else l = mid;
    }

    cout << l << endl;

    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

