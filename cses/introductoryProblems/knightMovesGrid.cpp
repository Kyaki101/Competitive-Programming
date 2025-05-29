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


int moves[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};


bool valid(vector<vector<bool>> & vis, ll n, pair<ll, ll> mv) {
    return mv.first > -1 && mv.first < n && mv.second > -1 && mv.second < n && !vis[mv.first][mv.second];
}

void bfs(vector<vector<ll>> & mat, vector<vector<bool>> & vis, ll n) {
    queue<pair<ll, ll>> cola;
    cola.push({0, 0});
    vis[0][0] = true;
    while(!cola.empty()) {
        pair<ll, ll> curr = cola.front();
        for(int i = 0; i < 8; i++) {
            pair<ll, ll> nxt = {curr.first + moves[i][0], curr.second + moves[i][1]};
            if(valid(vis, n, nxt)) {
                cola.push(nxt);
                vis[nxt.first][nxt.second] = true;
                mat[nxt.first][nxt.second] = mat[curr.first][curr.second] + 1;
            }
        }
        cola.pop();
    }

}


void solve(){        
    ll n;
    cin >> n;
    vector<vector<ll>> mat(n, vector<ll>(n, 0));
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    bfs(mat, vis, n);
    for(auto i : mat) {
        for(auto j : i) cout << j << ' ';
        cout << endl;
    }

    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

