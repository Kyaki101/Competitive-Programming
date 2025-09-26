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

ll moves[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(vector<string> & mat, vector<vector<bool>> & vis, ll i, ll j) {
    vis[i][j] = true;
    for(int k = 0; k < 4; k++) {
        ll x = i + moves[k][0];
        ll y = j + moves[k][1];
        if(x > -1 && y > -1 && x < mat.size() && y < mat[0].size() && mat[x][y] != '#' && !vis[x][y]) {
            dfs(mat, vis, x, y);
        }
    }
}

void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<string> mat(n);
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    ll cnt = 0;
    for(auto &i : mat) cin >> i;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == '.' && !vis[i][j]) {
                cnt ++;
                dfs(mat, vis, i, j);
            }
        }
    }
    cout << cnt << endl;

    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

