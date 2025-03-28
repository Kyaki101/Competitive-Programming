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

bool possible(ll x, vector<ll> a, ll k) {
    ll suma = 0;
    for(int i = 0; i < a.size(); i++) {
        suma += min(a[i], x);
    }
    return suma >= x * k;

}

void solve(){        
    ll k, n;
    cin >> k >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll l = 0;
    ll r = accumulate(ALL(a), 0LL);
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(possible(mid, a, k)) l = mid;
        else r = mid;
    }

    cout << l << endl;
    

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}

