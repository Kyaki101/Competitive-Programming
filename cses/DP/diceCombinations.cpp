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

ll fill(vector<ll> & memo, ll n) {
    if(n < 0) return 0;
    if(n == 0) return 1;
    if(memo[n]) return memo[n];
    return memo[n] = ((fill(memo, n - 1) % MOD) + (fill(memo, n - 2) % MOD) + (fill(memo, n - 3) % MOD) + (fill(memo, n - 4) % MOD) + (fill(memo, n - 5) % MOD) + (fill(memo, n - 6) % MOD)) % MOD;
}


void solve(){        
    ll n;
    cin >> n;
    vector<ll> memo(n + 1, 0);
    fill(memo, n);
    cout << memo[n] << endl;;


        
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

