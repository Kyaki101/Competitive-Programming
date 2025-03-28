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

void solve(){        
    ll n, c, b;
    cin >> n >> b >> c;
    if(c >= n) {
        cout << n << endl;
        return;
    }
    if(b == 0 && c == 0 && (n == 1 || n == 2)) {
        cout << (n == 2) << endl;
        return;
    }
    if(b == 0 && c == 0) {
        cout << -1 << endl;
        return;
    }

    if(b == 0) {
        cout << n - 1 << endl;
        return;
    }
    ll ans = n;
    ll mini = c;
    ans -= (n - (max(0LL, mini - 1))) / b;
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

