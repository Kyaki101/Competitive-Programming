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

map<ll, char> mv;

map<char, pair<ll, ll>> nxt;


string bfs(ll e1, ll e2, ll s1, ll s2, vector<string> & mat, vector<vector<bool>> & vis) {
    ll n = mat.size();
    ll m = mat[0].size();
    vector<vector<char>> path(n, vector<char>(m, ' '));
    queue<pair<ll, ll>> cola;
    cola.push({s1, s2});
    vis[s1][s2] = true;
    while(!cola.empty()) {
        auto [i, j] = cola.front();
        cola.pop();

        for(int k = 0; k < 4; k++) {
            ll x = i + moves[k][0];
            ll y = j + moves[k][1];
            if(x < n && y < m && x > -1 && y > -1 && mat[x][y] != '#' && !vis[x][y]) {
                vis[x][y] = true;
                path[x][y] = mv[k];
                cola.push({x, y});
            }
        }
    }
    if(!vis[e1][e2]) {
        return " ";
    }
    string ans = "";
    while(e1 != s1 || e2 != s2) {
        ans.PB(path[e1][e2]);
        ll r1 = e1;
        e1 += nxt[path[e1][e2]].first;
        e2 += nxt[path[r1][e2]].second;
    }
    reverse(ALL(ans));
    return ans;


}

void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<string> mat(n);
    for(auto &i : mat) cin >> i;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    ll s1, s2;
    ll e1, e2;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 'A') {
                s1 = i; s2 = j;
            }
            if(mat[i][j] == 'B') {
                e1 = i; e2 = j;
            }
        }
    }
    string pre = bfs(e1, e2, s1, s2, mat, vis);
    if(pre == " ") {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << pre.size() << endl;
    cout << pre << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    nxt['U'] = {1, 0};
    nxt['R'] = {0, -1};
    nxt['D'] = {-1, 0};
    nxt['L'] = {0, 1};

    mv[0] = 'U';
    mv[1] = 'R';
    mv[2] = 'D';
    mv[3] = 'L';




    while(t--){
        solve();
    }return 0;
}

