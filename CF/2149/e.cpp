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
    ll n, k, b, c;
    cin >> n >> k >> b >> c;
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    map<ll, ll> mapa;
    ll l = 0;
    ll ans = 0;
    for(int r = 0; r < n; r++) {
        mapa[a[r]]++;
        while(l < r && mapa.size() > k) {
            mapa[a[l]] --;
            if(mapa[a[l]] == 0) {
                mapa.erase(a[l]);
            }
            l++;
        }
        if(mapa.size() == k) {
            ans += r - l + 1;
        }
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

