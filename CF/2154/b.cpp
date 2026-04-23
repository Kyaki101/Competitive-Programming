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
    vll a(n);
    for(auto &i : a) cin >> i;
    ll maxi = a[0];
    for(int i = 1; i < n; i++) {
        maxi = max(a[i], maxi);
        if(i & 1) {
            a[i] = maxi;
        }
    }
    ll ans = 0;
    if(a[1] == a[0]) {
        ans ++;
    }
    for(int i = 2; i < n; i ++, i++) {
        if(a[i - 1] <= a[i]) {
            ans += a[i] - a[i - 1] + 1;
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

