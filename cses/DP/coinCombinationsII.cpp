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




void solve(){        
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(ll &i : a) cin >> i;
    vector<ll> memo(x + 1, 0);
    memo[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= x; j++) {
            if(j - a[i] >= 0) memo[j] = ((memo[j] % MOD) + (memo[j - a[i]] % MOD)) % MOD;  
        }
    }
    cout << memo[x] << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

