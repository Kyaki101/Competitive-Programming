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

ll gauss(ll n) {
    return (n * (n - 1)) / 2;
}

void solve(){        
    ll n;
    cin >> n;
    ll r = (1LL << 32) - 1;
    ll l = 1;
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(gauss(mid) <= n) l = mid;
        else r = mid;
    }
    cout << l + (n - gauss(l))<< endl;

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

