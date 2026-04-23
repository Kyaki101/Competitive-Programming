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
    ll n;
    cin >> n;
    vll a(n), b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    for(int i = 0; i < n - 1; i++) {
        if(a[i] % a[i + 1] != 0) {
            cout << "NO" << endl;
            return;
        }
    }
    for(int i = n - 1; i > 0; i--) {
        if(b[i] % b[i - 1] != 0) {
            cout << "NO" << endl;
            return;
        }
    }
    if(a[n - 1] != b[0]) {
        cout << "NO" << endl;
        return;
    }
    for(int i = 1; i < n; i++) {
        if(gcd(a[i - 1], b[i]) != b[0]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

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

