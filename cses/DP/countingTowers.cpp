#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
vector<ll> memo(1000001, 0);

ll expo(ll n, ll x) {
    if(x == 0) return 1;
    if(x & 1) return ((n % MOD) * (expo(n, x - 1) % MOD)) % MOD;
    ll y = expo(n, x / 2);
    return ((y % MOD) * (y % MOD)) % MOD;
}

void solve(){        
    ll n;
    cin >> n;
    cout << memo[n] << endl;
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    memo[1] = 2;
    for(int i = 2; i <= 1000000; i++) {
        memo[i] = ((memo[i - 1] % MOD) * (2 % MOD) + (expo(2, i) % MOD)) % MOD;
    }
    while(t--){
        solve();
    }return 0;
}

