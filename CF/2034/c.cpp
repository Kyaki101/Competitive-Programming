#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
typedef long long int ll;
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;


bool valid(ll n, ll m, ll x, ll y) {
    return x < n && y < m && x > -1 && y > -1;
}

ll moves[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};


void dfs(vector<string> & mat, vector<vector<bool> > & bad, ll i, ll j) {
    bad[i][j] = true;
    for(int k = 0; k < 4; k++) {
        ll x = i + moves[k][0];
        ll y = j + moves[k][1];
        if(valid(mat.size(), mat[0].size(), x, y) && !bad[x][y]) {
            if(k == 0) {
                if(mat[x][y] == 'D' || mat[x][y] == '?') {


                    dfs(mat, bad, x, y);

                }
            }
            if(k == 1) {
                if(mat[x][y] == 'R' || mat[x][y] == '?') {


                    dfs(mat, bad, x, y);

                }
            }
            if(k == 2) {
                if(mat[x][y] == 'U' || mat[x][y] == '?') {

                    dfs(mat, bad, x, y);

                }
            }
            if(k == 3) {
                if(mat[x][y] == 'L' || mat[x][y] == '?') {

                    dfs(mat, bad, x, y);

                }
            }
        }
    }

}

void cycle(ll n, ll m, vector<string> & mat, vector<vector<int> > & vis, ll i, ll j, vector<vector<bool> > & bad) {
    ll x = 0;
    ll y = 0;
    if(mat[i][j] == 'R') {
        x = i;
        y = j + 1;
    }
    if(mat[i][j] == 'L') {
        x = i;
        y = j - 1;
    }
    if(mat[i][j] == 'U') {
        x = i - 1;
        y = j;
    }
    if(mat[i][j] == 'D') {
        x = i + 1;
        y = j;
    }

    ll ans = false;
    if(valid(n, m, x, y)) {
        if(mat[x][y] == '?' || bad[x][y] || vis[x][y] == 1) {
            bad[i][j] = true;
            bad[x][y] = true;
            vis[i][j] = 2;
            vis[x][y] = 2;
            return;
        }
        if(vis[x][y] == 2) {
            vis[i][j] = 2;
            return;
        }
        else {
            vis[x][y] = 1;
            cycle(n, m, mat, vis, x, y, bad);
            ans = bad[x][y];
            bad[i][j] = ans;
            vis[x][y] = 2;
            return;
            
        }

    }
    else vis[i][j] = 2;
}

void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<string> mat(n);
    for(int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    vector<vector<bool> > bad(n, vector<bool>(m, false));

    vector<vector<int> > vis(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] != '?' && !bad[i][j]) {
                vis[i][j] = 1;
                cycle(n, m, mat, vis, i, j, bad);
                vis[i][j] = 2;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if((mat[i][j] == 'D' || mat[i][j] == '?') && valid(n, m, i + 1, j) && (mat[i + 1][j] == 'U' || mat[i + 1][j] == '?')) {
                bad[i][j] = true;
                bad[i + 1][j] = true;
            }
            if ((mat[i][j] == 'R' || mat[i][j] == '?') && valid(n, m, i, j + 1) && (mat[i][j + 1] == 'L' || mat[i][j + 1] == '?')) {
                bad[i][j] = true;
                bad[i][j + 1] = true;
            }
            if ((mat[i][j] == 'U' || mat[i][j] == '?') && valid(n, m, i - 1, j) && (mat[i - 1][j] == 'D' || mat[i - 1][j] == '?')) {
                bad[i][j] = true;
                bad[i - 1][j] = true;
            }
            if ((mat[i][j] == 'L' || mat[i][j] == '?') && valid(n, m, i, j - 1) && (mat[i][j - 1] == 'R' || mat[i][j - 1] == '?')) {
                bad[i][j] = true;
                bad[i][j - 1] = true;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(bad[i][j]) {
                dfs(mat, bad, i, j);
            }
        }
    }


    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {

                ans += bad[i][j];
        }
    }
    cout << ans << endl;


}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

