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
    ll l, r, x;
    cin >> l >> r >> x;
    ll a, b;
    cin >> a >> b;

    if(a == b) {
        cout << 0 << endl;
        return;
    }

    if(a + x > r && a - x < l || abs(b - l) < x && abs(b - r) < x) {
        cout << -1 << endl;
        return;
    }

    if(abs(a - b) >= x) {
        cout << 1 << endl;
        return;
    }

    if(b < a) {
        if(abs(a - r) >= x || abs(b - l) >=x) {
            cout << 2 << endl;
            return;
        }
    }
    if(b > a) {
        if(abs(a - l) >= x || abs(b - r) >= x) {
            cout << 2 << endl;
            return;
        }
    }
    cout << 3 << endl;
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

