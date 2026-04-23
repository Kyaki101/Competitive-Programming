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

struct pos {
    ll x, y, rights, lefts, origin;
};

struct cmp {
    bool operator()(const pos &a, const pos &b) const {
        return a.rights + a.lefts < b.rights + b.lefts;
    }
    
};

void solve(){        
    ll n, m, r, c;
    cin >> n >> m >> r >> c;
    ll x, y; 
    cin >> y >> x;

    r --, c--;

    vector<string> mat(n);
    for(auto &i : mat) cin >> i;

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    vis[r][c] = true;

    auto check = [&](ll i, ll j) {
        return i > -1 && i < n && j > -1 && j < m && mat[i][j] != '*' && !vis[i][j];
    };
    ll orr = 1;

    priority_queue<pos, vector<pos>, cmp> cola;
    cola.push({r, c, x, y, 0});

    while(!cola.empty()) {
        auto curr = cola.top();
        cola.pop();

        for(int k = 0; k < 4; k++) {
            ll i = curr.x + moves[k][0];
            ll j = curr.y + moves[k][1];
            if(k == 1) {
                if(curr.rights == 0) continue;
                if(check(i, j)) {
                    cola.push({i, j, curr.rights - 1, curr.lefts, orr});
                    orr ++;
                    vis[i][j] = true;
                }
                continue;
            }
            if(k == 3) {
                if(curr.lefts == 0) continue;
                if(check(i, j)) {
                    cola.push({i, j, curr.rights, curr.lefts - 1, orr});
                    orr++;
                    vis[i][j] = true;
                }
                continue;
            }
            if(check(i, j)) {
                cola.push({i, j, curr.rights, curr.lefts, 0});
                vis[i][j] = true;
            }
        }
    }


    ll ans = 0;
    for(auto &i : vis) {
        for(auto j : i) {
            ans += j;
        }
    }
    cout << ans << endl;

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

