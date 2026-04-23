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
    ll l = 0;
    ll suma = 0;
    ll mini = (1 << 30);
    for(int r = 0; r < n; r++) {
        suma += a[r];
        while(suma - a[l] >= k) {
            suma -= a[l];
            l++;
        }
        if(suma >= k) {
            mini = min(mini, r - l + 1);
        }
    }
    if(mini == (1 << 30)) {
        cout << -1 << endl;
        return;
    }
    cout << mini << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

