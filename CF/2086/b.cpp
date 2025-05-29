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
ll n;

void solve(){        
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    ll suma = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        suma += a[i];
    }

    ll i = 1;
    while(i <= k && i * suma < x) {
        i++;
    }
    if(i > k) {
        cout << 0 << endl;
        return;
    }
    ll j = i - 1;

    ll in = 0;
    ll s = 0;
    while(suma * j + s < x) {
        s += a[in];
        in ++;
    }
    DEBUG(suma * j + s);
    in --;
    cout << n * k - (n * j + in) << endl;


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

