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
    ll x, y, k;
    cin >> x >> y >> k;
    ll size = 1000000000000;
    if(y == 1) {
        cout << -1 << endl;
        return;
    }
    ll nxt = y - (k % y);
    ll mv = 0;
    while(x --) {
        ll back = k / y;
        ll front = ((k + back) / y) - (back);
        mv += back + front;
        size = size - (size / y);
        if(k > size) {
            cout << -1 << endl;
            return;
        }
    }
    cout << k + mv << endl;



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

