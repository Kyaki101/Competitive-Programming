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


bool possible(ll x, vector<ll> & a, ll k) {
    ll n = a.size();
    ll count = 1;
    ll suma = 0;
    for(int i = 0; i < n; i++) {
        if(suma + a[i] > x) {
            suma = 0;
            count ++;
        }
        suma += a[i];
    }
    cout << endl;
    return count <= k;
}

void solve(){        
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll maxi = 0;
    for(int i = 0; i < k; i++) {
        cin >> a[i];
        maxi = max(a[i], maxi);
    }
    ll l = maxi - 1;
    ll r = accumulate(ALL(a), 0LL);
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(possible(mid, a, k)) r = mid;
        else l = mid;
    }
    cout << r << endl;



    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}

