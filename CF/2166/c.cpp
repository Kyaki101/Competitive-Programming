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
    vll a(n);
    vector<pair<ll, ll>> pos;
    ll maxi = -1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pos.PB({a[i], i});
        maxi = max(maxi, a[i]);
    }
    if(n == 2) {

        cout << maxi << endl;
        return;

    }
    sort(ALL(pos));
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[((pos[i].second - 1) + n) % n] > pos[i].first) {
            ans += a[((pos[i].second - 1) + n) % n]; 
        }
        if(a[(pos[i].second + 1) % n] >= pos[i].first) {
            ans += a[(pos[i].second + 1) % n];
        }

    }


    cout << ans - maxi << endl;

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

