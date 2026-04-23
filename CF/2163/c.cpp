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
    vll b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    vll prefMin(n);
    vll prefMax(n);
    vll suffMin(n);
    vll suffMax(n);
    prefMax[0] = prefMin[0] = a[0];
    for(int i = 1; i < n; i++) {
        prefMin[i] = min(prefMin[i - 1], a[i]);
        prefMax[i] = max(prefMax[i - 1], a[i]);
    }

    suffMin[n - 1] = suffMax[n - 1] = b[n - 1];
    for(int i = n - 2; i > -1; i--) {
        suffMin[i] = min(suffMin[i + 1], b[i]);
        suffMax[i] = max(suffMax[i + 1], b[i]);
    }

    auto checker = [&](ll lower, ll upper) {
        ll l1 = -1;
        ll r1 = n;
        while(l1 + 1 < r1) {
            ll mid = (l1 + r1) / 2;
            if(prefMin[mid] >= lower && prefMax[mid] <= upper) l1 = mid;
            else r1 = mid;
        }
        if(l1 == -1) return false;

        ll l2 = -1;
        ll r2 = n;
        while(l2 + 1 < r2) {
            ll mid = (l2 + r2) / 2;
            if(suffMin[mid] >= lower && suffMax[mid] <= upper) r2 = mid;
            else l2 = mid;
        }
        if(r2 == n) return false;

        return l1 >= r2;

    };

    ll l = 1, ans = 0;
    for(int r = 1; r <= 2 * n; r++) {
        while(l <= r && checker(l, r)) {
            ans += n * 2 - r + 1;
            l++;
        }

    }
    cout << ans << endl;


};

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

