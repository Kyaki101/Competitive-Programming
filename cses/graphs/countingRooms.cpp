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
ll n;


ll moves[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};


bool valid(ll n, ll m, ll i, ll j, vector<string> & mat) {
    return i > -1 && j > -1 && i < n && j < m && mat[i][j] == '.';

}


void bfs(ll i, ll j, vector<vector<bool>> & vis, vector<string> & mat) {
    queue<pair<ll, ll>> cola;
    vis[i][j] = true;
    cola.push({i, j});
    while(!cola.empty()) {
        pair<ll, ll> curr = cola.front();
        cola.pop();
        for(int k = 0; k < 4; k++) {
            pair<ll, ll> temp = {curr.first + moves[k][0], curr.second + moves[k][1]};
            if(valid(mat.size(), mat[0].size(), temp.first, temp.second, mat) && !vis[temp.first][temp.second]) {
                cola.push(temp);
                vis[temp.first][temp.second] = true;
            }
        }
    }
}

void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<string> mat(n);
    for(int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    vector<vector<bool>> vis(n, vector<bool>(m));
    ll counter = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && mat[i][j] == '.') bfs(i, j, vis, mat), counter ++;
        }
    }
    cout << counter << endl;



}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

