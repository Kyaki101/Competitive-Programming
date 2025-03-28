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


ll powerSum(ll n, ll k) {
    if(n == 0) return 0;
    if(n == 1) {
        return k + 1;
    }
    return (1 - pow(n, k + 1)) / (1 - n);
}


bool found(ll x, ll k) {
    ll r = 1000010;
    ll l = 1;
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(powerSum(mid, k) >= x) {
            DEBUG(powerSum(mid, k));
            r = mid;
        }
        else l = mid;
    }
    if(powerSum(r, k) == k) return true;
    return false;
}

void solve(){        
    ll x;
    cin >> x;
    for(int i = 2; i <= 20; i++) {
        if(found(x, i)) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

