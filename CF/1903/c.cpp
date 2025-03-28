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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll suma = 0;
    vector<ll> acum(n + 1, 0);
    for(ll i = 0; i < n; i++) {
        suma += a[i] * (i + 1);
        acum[i + 1] = suma;
    }
    ll maxi = -1 * (1LL << 60);
    ll suff = 0;
    ll scalar = n;
    for(int i = n - 1; i > -1; i--) {
        suff += a[i];
        maxi = max(maxi, acum[i] + suff * scalar);
        scalar --;
    }
    cout << maxi << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

