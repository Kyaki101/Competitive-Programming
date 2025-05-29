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

ll fill(vector<ll> & memo, ll x, vector<ll> & a, vector<bool> & vis) {
    if(x < 0) return 0;
    if(x == 0) return 1;
    if(vis[x]) return memo[x];
    vis[x] = true;
    ll val = 0;
    for(int i = 0; i < a.size(); i++) {
        val = ((val % MOD) + (fill(memo, x - a[i], a, vis) % MOD) % MOD);
    }
    return memo[x] = val;
}

void solve(){        
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> memo(x + 1, 0);
    vector<bool> vis(x + 1, false);
    fill(memo, x, a, vis);
    cout << memo[x] % MOD << endl;
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

