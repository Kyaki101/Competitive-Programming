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


int moves[4][2] = {{1, 0}, {0, 1}};

void solve(){        
    ll n;
    cin >> n;
    vector<string> mat(n);
    for(int i = 0; i < n; i++) cin >> mat[i];
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    vector<vector<ll>> memo(n, vector<ll>(n, 0));
    memo[n - 1][n - 1] = 1;
    vis[n - 1][n - 1] = true;
    if(mat[0][0] == '*') {
        cout << 0 << endl;
        return;
    }
    function<ll (ll, ll)> dfs = [&](ll i, ll j) {
        if(vis[i][j]) {
            return memo[i][j];
        }
        vis[i][j] = true;
        for(int k = 0; k < 2; k++) {
            ll x = i + moves[k][0];
            ll y = j + moves[k][1];
            if(x < n && x > -1 && y < n && y > -1 && mat[x][y] != '*') {
                memo[i][j] = (memo[i][j] + dfs(x, y)) % MOD;
            }
        }
        return memo[i][j];
    };
    dfs(0, 0);
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

