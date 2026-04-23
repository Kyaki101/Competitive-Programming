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
#define ll int
typedef vector<ll> vll;

const int MAX = 2e5+20, MOD = 1e9+7;

ll k;

vector<vector<int>> moves = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};


bool valid(ll i, ll j, ll n, ll m) {
    return i > -1 && i < n && j > -1 && j < m;
}

struct node {
    ll i;
    ll j;
    int ptr;
    int dir;
    ll kinks;
};

bool ans = false;

bool vis[10][10][110][9][110];





void bfs(ll i, ll j, vector<vector<char>>& mat, string &s) {
    queue<node> cola;
    cola.push({i, j, 1, 8, 0});
    vis[i][j][1][8][0] = true;
    while(!cola.empty()) {
        auto temp = cola.front();
        cola.pop();
        if(temp.ptr == (ll)s.size()) {
            ans = ans || temp.kinks == k;
            continue;
        }
        for(int w = 0; w < 8; w++) {
            ll x = temp.i + moves[w][0];
            ll y = temp.j + moves[w][1];
            if(valid(x, y, mat.size(), mat[0].size()) && mat[x][y] == s[temp.ptr]) {
                if(temp.dir == 8 || temp.dir == w) {
                    node perm = {x, y, temp.ptr + 1, w, temp.kinks};
                    if(!vis[perm.i][perm.j][perm.ptr][w][perm.kinks]) cola.push(perm);
                    vis[perm.i][perm.j][perm.ptr][w][perm.kinks] = true;
                }
                else {
                    node perm = {x, y, temp.ptr + 1, w, temp.kinks + 1};
                    if(!vis[perm.i][perm.j][perm.ptr][w][perm.kinks]) cola.push(perm);
                    vis[perm.i][perm.j][perm.ptr][w][perm.kinks] = true;
                }
            }
        }

    }
}

void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    for(auto &i : mat) 
        for(auto &j : i) cin >> j;

    cin >> k;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == s[0]) {
                bfs(i, j, mat, s);
            }
        }
    }
    if(ans) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;



    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
        #ifdef ICPC 
            cout << "--------------------------------------------------" << endl;
        #endif // 
    }
    #ifdef ICPC 
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}

