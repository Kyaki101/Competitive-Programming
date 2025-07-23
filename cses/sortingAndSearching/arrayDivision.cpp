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

bool good(ll n, ll k, vector<ll> & a, ll x) {
    for(int i = 0; i < n; i++) {
        if(a[i] > x) {
            return false;
        }
    }
    ll divis = 1;
    ll curr = 0;
    for(int i = 0; i < n; i++) {
        curr += a[i];
        if(curr > x) {
            curr = a[i];
            divis ++;
        }
    }
    return divis <= k;

}

void solve(){        
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto &i : a) {
        cin >> i;
    }
    ll l = 0;
    ll r = (1LL << 50);
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(good(n, k, a, mid)) r = mid;
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

