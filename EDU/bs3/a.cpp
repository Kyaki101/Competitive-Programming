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
#define pll pair<ll, ll>
typedef vector<ll> vll;

const int MAX = 2e5+20, MOD = 1e9+7;

void solve(){        
    ll n;
    cin >> n;
    vector<pll> a(n);
    for(auto & [x, y] : a) {
        cin >> x >> y;
    }
    double l = 0;
    double r = 3000000001;
    for(int i = 0; i < 100; i++) {
        double mid = (l + r) / 2;
        double mini = -1 * (1LL << 62);
        double maxi = (1LL << 62);
        for(auto [pos, v] : a) {
            mini = max(mini, pos - mid * v);
            maxi = min(maxi, pos + mid * v);
        }

        if(mini <= maxi) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << fixed << setprecision(10) << r << endl;

    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

