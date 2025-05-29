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


ll memoize(ll n, vector<ll> & memo) {
    if(n < 0) return (1 << 30);
    if(n == 0) return 0;
    if(memo[n]) return memo[n];
    ll val = (1 << 30);
    string s = to_string(n);
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != '0') {
            ll v = s[i] - '0';
            val = min(val, memoize(n - v, memo) + 1);
        }
    }
    return memo[n] = val;
}

void solve(){        
    ll x;
    cin >> x;
    vector<ll> memo(x + 1, 0);
    memoize(x, memo);
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

