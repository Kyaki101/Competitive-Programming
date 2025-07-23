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


void optimal(vector<ll> & a, ll &k, ll curr) {
    vector<pair<ll, ll>> best;
    ll n = a.size();
    for(int i = 0; i < n; i++) {
        if(TEST(a[i], curr) == 0) {
            ll num = 0;
            for(int j = 0; j < curr; j++) {
                if(TEST(a[i], j)) num = SET(num, j);
            }
            ll diff = (1LL << curr) - num;
            diff += (1LL << curr) - 1;
            best.push_back({diff, i});
        }
    }
    for(int i = 0; i < best.size(); i++) {
        if(k < best[i].first) break;
        k -= best[i].first;
        a[best[i].second] = SET(a[best[i].second], curr);
    }

}

void solve(){        
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    for(int i = 0; i < 62; i++) {
        optimal(a, k, i);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 62; j++) {
            if(TEST(a[i], j)) ans++;
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

