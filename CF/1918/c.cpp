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
    ll a, b, r;
    cin >> a >> b >> r;
    ll ans = 0;
    ll start = 61;
    while(start > -1 && TEST(a, start) == TEST(b, start)) {
        start --;
    }
    start --;
    auto ver = [](ll a, ll b, ll i) {
        return (TEST(b, i) && !TEST(a, i));
    };

    for(int i = start; i > -1; i--) {
        if(a < b && ver(a, b, i) && SET(ans, i) <= r) {
            ans = SET(ans, i);
        }
        if(b < a && ver(b, a, i) && SET(ans, i) <= r) {
            ans = SET(ans, i);
        }

    }
    cout << abs((a ^ ans) - (b ^ ans)) << endl;
    
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

