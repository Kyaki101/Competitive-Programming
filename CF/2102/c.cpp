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

void solve(){        
    ll n;
    cin >> n;
    vector<vector<ll>> grid(n, vector<ll>(n));
    pair<ll, ll> dir = {1, 0};
    pair<ll, ll> pos = {0, 0};
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    ll visi = 0;
    ll num = n * n - 1;
    

    while(visi < n * n) {

        vis[pos.first][pos.second] = true;
        grid[pos.first][pos.second] = num;
        visi ++;
        if(visi == n * n) {
            break;
        }
        pair<ll, ll> nxt = {dir.first + pos.first, dir.second + pos.second};
        if(nxt.first == n || nxt.second == n || nxt.first < 0 || nxt.second < 0 || vis[nxt.first][nxt.second]) {
            if(dir == make_pair(1LL, 0LL)) {
                dir = {0, 1};
            }
            else if(dir == make_pair(0LL, 1LL)) {
                dir = {-1, 0};
            }
            else if(dir == make_pair(-1LL, 0LL)) {
                dir = {0, -1};
            }
            else if(dir == make_pair(0LL, -1LL)) {
                dir = {1, 0};
            }
        }
        pos = {pos.first + dir.first, pos.second + dir.second};
        num --;

    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << grid[i][j] << ' ';
        }

        cout << endl;
    }

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

