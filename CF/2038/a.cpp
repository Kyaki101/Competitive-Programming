#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
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
    vll a(n), b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    vll c;
    ll track = k;
    reverse(ALL(a));
    reverse(ALL(b));
    for(int i = 0; i < n; i++) {
        ll l = 0;
        ll r = a[i] + 1;
        
        while(l + 1 < r) {
            ll mid = (l + r) / 2;
            if(a[i] - mid * b[i] >= 0) l = mid;
            else r = mid;
        }
        l = min(track, l);
        track -= l;
        c.PB(l);
    }
    reverse(ALL(c));
    if(track == 0) {
        for(auto i : c) {
            cout << i << ' ';
        }
        cout << endl;
        return;
    }
    for(auto _ : c) {
        cout << 0 << ' ';
    }
    cout << endl;
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

