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
    ll n, k, p;
    cin >> n >> k >> p;
    if(abs(p) * n < abs(k)) {
        cout << -1 << endl;
        return;
    }
    if(k == 0) {
        cout << 0 << endl;
        return;
    }
    if(abs(k) % abs(p) == 0) {
        cout << abs(k) / abs(p) << endl;
        return;
    }
    cout << abs(k) / abs(p) + 1 << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

