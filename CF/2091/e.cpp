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

vector<ll> factors(10000009, 0);

void solve(){        
    ll n;
    cin >> n;

    ll ans = 0;


    for(int i = 2; i <= n; i++) {
        ans += factors[i];
        if(factors[i] == 0) ans++;
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    for(int i = 2; i <= 10000009; i++) {
        if(factors[i] == 0) {
            for(int j = i * 2; j <= 10000009; j+= i) {
                factors[j] ++;
            }
        }

    }
    while(t--){
        solve();
    }return 0;
}

