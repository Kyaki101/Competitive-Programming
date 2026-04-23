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

ll prod(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}
ll suma(ll a, ll b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

void solve(){        
    string s;
    cin >> s;
    ll n = s.size();
    map<ll, ll> mapa;
    mapa[0] = 1;
    ll sum = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') sum ++;
        else sum --;
        ans = suma(ans, prod(mapa[sum], n - i));
        mapa[sum] += i + 2;
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

