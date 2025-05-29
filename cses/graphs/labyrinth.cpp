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

ll moves[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

bool found = false;
ll x, y;

bool valid(ll i, ll j, ll n, ll m, vector<string> & mat, vector<vector<bool>> & vis) {
    return i > -1 && j > -1 && i < n && j < m && mat[i][j] != '#' && !vis[i][j];
}


void bfs(ll a, ll b, ll n, ll m, vector<string> & mat, vector<vector<bool>> & vis, vector<vector<char>> & steps) {
    vis[a][b] = true;
    queue<pair<ll, ll>> cola;
    cola.push({a, b});
    while(!cola.empty()) {
        pair<ll, ll> curr = cola.front();
        cola.pop();
        if(mat[curr.first][curr.second] == 'B') {
            found = true;
            x = curr.first;
            y = curr.second;
            return;
        }
        for(int i = 0; i < 4; i++) {
            pair<ll, ll> temp = {curr.first + moves[i][0], curr.second + moves[i][1]};
            if(valid(temp.first, temp.second, n, m, mat, vis)) {
                if(i == 0) steps[temp.first][temp.second] = 'U';
                if(i == 1) steps[temp.first][temp.second] = 'L';
                if(i == 2) steps[temp.first][temp.second] = 'D';
                if(i == 3) steps[temp.first][temp.second] = 'R';
                vis[temp.first][temp.second] = true;
                cola.push(temp);
            }
            

        }
    }
}


void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<string> mat(n);
    vector<vector<bool>> vis(n, vector<bool>(m));
    for(int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    vector<vector<char>> steps(n, vector<char>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 'A') {
                bfs(i, j, n, m, mat, vis, steps);
                break;
            }
        }
    }

    if(!found) {
        cout << "NO" << endl;
        return;
    }

    string ans = "";
    while(mat[x][y] != 'A') {
        if(steps[x][y] == 'U') {
            ans.push_back('U');
            x ++;
        }
        else if(steps[x][y] == 'D') {
            ans.push_back('D');
            x --;
        }
        else if(steps[x][y] == 'R') {
            ans.push_back('R');
            y --;
        }
        else if(steps[x][y] == 'L') {
            ans.push_back('L');
            y ++;
        }
    }
    reverse(ALL(ans));
    cout << "YES" << endl;
    cout << ans.size() << endl;
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

