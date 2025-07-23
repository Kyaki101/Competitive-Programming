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


ll dp(ll curr, vector<ll> & memo) {
    if(curr == 0) return 1;
    if(curr < 0) return 0;
    if(memo[curr] != -1) {
        return memo[curr];
    }
    return memo[curr] = ((dp(curr - 1, memo) % MOD) + (dp(curr - 2, memo) % MOD) + (dp(curr - 3, memo) % MOD) + (dp(curr - 4, memo) % MOD) + (dp(curr - 5, memo) % MOD) + (dp(curr - 6, memo) % MOD)) % MOD;
}

void solve(){        
    ll n; cin >> n;
    vector<ll> memo(n + 1, -1);
    cout << dp(n, memo) << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

