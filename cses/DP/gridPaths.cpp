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

ll moves[4][2] = {{1, 0}, {0, 1}};

ll cover(ll n, ll i, ll j, vector<string> & mat, vector<vector<ll> > & memo, vector<vector<bool>> & vis) {
    if(mat[i][j] == '*') {
        vis[i][j] = true;
        return memo[i][j] = 0;
    }

    if(i == n - 1 && j == n - 1) return memo[i][j] = 1;

    if(vis[i][j]) {
        return memo[i][j];
    }

    vis[i][j] = true;
    ll val = 0;
    for(int k = 0; k < 2; k++) {
        ll x = i + moves[k][0];
        ll y = j + moves[k][1];
        if(x > -1 && y > -1 && x < n && y < n) {
            val = ((val % MOD) + (cover(n, x, y, mat, memo, vis) % MOD)) % MOD;
        }
    }
    return memo[i][j] = val;


}

void solve(){        
    ll n;
    cin >> n;
    vector<string> mat(n);
    for(auto &i: mat) cin >> i;
    vector<vector<ll>> memo(n, vector<ll>(n, 0));
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    cover(n, 0, 0, mat, memo, vis);
    cout << memo[0][0] << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

