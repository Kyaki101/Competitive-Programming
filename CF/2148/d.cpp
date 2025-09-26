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
    vector<ll> bruh(n);
    for(auto &i : bruh) cin >> i;
    vector<ll> a, b;
    for(auto i : bruh) {
        if(i & 1) a.PB(i);
        else b.PB(i);
    }
    ll i = 0;
    ll j = (ll)(a.size()) - 1;
    ll ans = 0;
    sort(a.rbegin(), a.rend());
    while(i <= j) {
        if(i == j) {
            ans += a[i];
        }
        else ans += a[i];
        i ++;
        j --;
    }
    for(auto i : b) ans += i;
    if(a.size() == 0) {
        cout << 0 << endl;
        return;
    }
    cout << ans << endl;
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

