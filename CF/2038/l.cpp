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
    ll a = n, b = n, c = n;
    ll ans = 0;
    ans += n / 2;
    b -= (n / 2) * 2;
    a -= n / 2;
    if(b == 1) {
        if(a == 1) {
            a --;
            b --;
            ans ++;
        }
        else if( a % 3 == 1) {
            c --;
            b --;
            ans ++;
        }
    }
    ans += a / 3;
    a -= (a / 3) * 3;
    if(a == 2) {
        ans ++;
        a--, a--;
    }
    else if(a == 1) {
        ans ++;
        a--;
        c --;
    }
    ans += (c + 1) / 2;
    cout << ans << endl;



}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

