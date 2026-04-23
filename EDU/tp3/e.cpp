#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define F second
#define S first
#define PB push_back
#define ll long long
typedef vector<ll> vll;

const int MAX = 2e5+20, MOD = 1e9+7;

void solve(){        
    ll n, weight;
    cin >> n >> weight;
    vll a(n), b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    ll cost = 0;
    ll w = 0;
    ll l = 0;
    ll ans = 0;
    for(int r = 0; r < n; r++) {
        w += a[r];
        cost += b[r];
        while(w > weight) {
            w -= a[l];
            cost -= b[l];
            l++;
        }
        ans = max(cost, ans);
    }

    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

