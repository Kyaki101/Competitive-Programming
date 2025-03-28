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



ll possible(vector<ll> & a, vector<ll> & b, ll x, ll k) {
    ll bef = 0;
    for(int i = 0; i < a.size(); i++) {
        ll y = x - a[i];
        ll l = -1;
        ll r = a.size();
        while(l + 1 < r) {
            ll mid = (l + r) / 2;
            if(b[mid] < y) l = mid;
            else r = mid;
        }
        bef += l + 1;
    }


    return bef < k;
}

void solve(){        
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(ALL(a));
    sort(ALL(b));
    ll l = 0;
    ll r = (1LL << 40);

    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(possible(a, b, mid, k)) l = mid;
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

