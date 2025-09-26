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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto & i : a) cin >> i;
    ll total = 0;
    for(int i = 0; i < n; i++) {
        if(i % 2) total -= a[i];
        else total += a[i];
    }

    ll minOdd = LLONG_MAX >> 1;
    ll minEven = LLONG_MAX >> 1;
    ll init = total;

    ll ans = 0;

    ans = init + (n - 1) - !(n % 2);

    for(int i = 0; i < n; i++) {
        if(i % 2) {
            ans = max(init + i + a[i] + a[i] - minEven, ans);
            minOdd = min(minOdd, i - a[i] - a[i]);
        }
        else {
            ans = max(init + i - a[i] - a[i] - minOdd, ans);
            minEven = min(minEven, i + a[i] + a[i]);
        }
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

