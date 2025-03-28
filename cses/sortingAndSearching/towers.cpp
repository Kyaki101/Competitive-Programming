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

void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> towers;
    for(int i = 0; i < n; i++) {
        ll l = -1;
        ll r = towers.size();
        while(l + 1 < r) {
            ll mid = (l + r) / 2;
            if(towers[mid] > a[i]) {
                r = mid;
            }
            else l = mid;
        }
        if(r == towers.size()) {
            towers.push_back(a[i]);
        }
        else {
            towers[r] = a[i];
        }

    }
    cout << towers.size() << endl;
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}

