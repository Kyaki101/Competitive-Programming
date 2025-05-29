#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;


bool good(ll x, ll k, vector<ll> & a) {
    ll count = 0;
    for(int i = 0; i < a.size(); i++) {
        count += x / a[i];
        if(count >= k) return true;
    }
    return false;
}

void solve(){        
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto &i: a) cin >> i;
    ll r = (1LL << 60);
    ll l = 0;
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(good(mid, k, a)) {
            r = mid;
        }
        else l = mid;
    }
    cout << r << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

