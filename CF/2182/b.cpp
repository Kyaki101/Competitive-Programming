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
    ll a, b;
    cin >> a >> b;
    ll i = 0;
    ll j = 1;
    ll acount = 0;
    ll bcount = 0;
    while(acount + (1 << i) <= a) {
        acount += (1 << i);
        i++, i++;
    }
    while(bcount + (1 << j) <= b) {
        bcount += (1 << j);
        j++, j++;
    }
    ll ans = min(i, j);
    i = 1;
    j = 0;
    acount = 0, bcount = 0;
    while(acount + (1 << i) <= a) {
        acount += (1 << i);
        i++, i++;
    }
    while(bcount + (1 << j) <= b) {
        bcount += (1 << j);
        j++, j++;
    }
    ans = max(ans, min(i, j));
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

