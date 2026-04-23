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
    vll a(n);
    for(auto &i : a) cin >> i;
    auto possible = [&](ll mid) {
        ll counter = k - 1;
        ll last = a[0];
        for(int i = 1; i < n; i++) {
            if(a[i] - last >= mid) {
                last = a[i];
                counter --;
            }
        }
        return counter <= 0;
    };
    ll l = 0;
    ll r = a[n - 1] - a[0] + 1;
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(possible(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;


}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

