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

void solve(){        
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> a(n);
    for(auto &i : a) {
        cin >> i;
    }
    ll len = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > q) {
            if(k == 1) {
                ans += (len * (len - 1)) / 2 + len;
            }
            else {
                ll r = k;
                while(r <= len) {
                    ans += len - r + 1;
                    r++;
                }
            }
            len = 0;
        }
        else len ++;
    }
    if(k == 1) {
        ans += (len * (len - 1)) / 2 + len;
    }
    else {
        ll r = k;
        while(r <= len) {
            ans += len - r + 1;
            r++;
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

