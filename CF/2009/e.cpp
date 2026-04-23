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
    ll n, k;
    cin >> n >> k;
    auto gauss = [](ll m) {
        return (m * (m + 1)) / 2;
    };
    auto calc = [&](ll m) {
        return gauss(m + k) - gauss(k - 1);
    };
    ll r = n;
    ll l = 0;
    ll goal = calc(n - 1) / 2;
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(calc(mid) <= goal) l = mid;
        else r = mid;
    }
    ll x = abs(calc(l) - (gauss(n + k - 1) - gauss(l + k)));
    ll y = abs(calc(l + 1) - (gauss(n + k - 1) - gauss(l + 1 + k)));
    cout << min(x, y) << endl;
    
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

