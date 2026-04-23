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
    ll l = 0;
    ll r = 10000000000000;
    auto check = [&](ll mid, ll available) {
        for(int i = 0; i < n; i++) {
            if(a[i] >= mid) continue;
            if(available < mid - a[i]) return false;
            available -= mid - a[i];
        }
        return true;
    };


    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(check(mid, k)) l = mid;
        else r = mid;
    }

    for(int i = 0; i < n; i++) {
        if(a[i] < l) k -= (l - a[i]), a[i] = l;
        
    }
    ll extra = 0;
    for(auto &i : a) {
        if(i > l) extra ++;
        if(k > 0 && i == l) extra ++, k --;
    }
    
    cout << l * n - (n - 1) + extra << endl;

    
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

