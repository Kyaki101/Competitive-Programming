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


bool possible(ll x, vector<ll> & a, ll k) {
    ll n = a.size();
    ll count = 1;
    ll prev = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] - prev >= x) {
            prev = a[i];
            count ++;
        }
        
    }
    return count >= k;
}

void solve(){        
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll mini = (1 << 30);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i > 0) mini = min(a[i] - a[i - 1], mini);
    }

    ll l = mini;
    ll r = 1 << 30;
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(possible(mid, a, k)) l = mid;
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

