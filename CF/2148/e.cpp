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
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    map<ll, ll> elems;
    for(auto i : a) {
        elems[i] ++;
    }
    map<ll, ll> divis;
    for(auto [x, y] : elems) {
        if(y % k != 0) {
            cout << 0 << endl;
            return;
        }
        divis[x] = y / k;
    }
    map<ll, ll> curr;
    ll l = 0;
    ll ans = 0;
    for(int r = 0; r < n; r++) {
        curr[a[r]] ++;
        while(l < r && curr[a[r]] > divis[a[r]]) {
            curr[a[l]] --;
            l++;
        }
        ans += r - l + 1;
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

