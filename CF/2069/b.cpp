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


ll moves[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};


bool valid(ll i, ll j, ll n, ll m) {
    return i < n && j < m && i > -1 && j > -1;
}

ll dfs(ll n, ll i, ll j, vector<vector<ll> > & mat)  {
    ll ans = 1;
    for(int k = 0; k < 4; k++) {
        ll x = moves[k][0] + i;
        ll y = moves[k][1] + j;
        if(valid(x, y, mat.size(), mat[0].size()) && mat[x][y] == mat[i][j]) {
            return 2;

        }

    }
    return 1;

}

void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<vector<ll> > mat(n, vector<ll>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    map<ll, ll> mapa;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mapa.find(mat[i][j]) == mapa.end()) {
                mapa[mat[i][j]] = dfs(mat[i][j], i, j, mat);
            }
            else mapa[mat[i][j]] = max(mapa[mat[i][j]], dfs(mat[i][j], i, j, mat));
        }
    }
    ll maxi = 0;
    ll ans = 0;
    for(auto i : mapa) {
        maxi = max(i.second, maxi);
        ans += i.second;
    }
    cout << ans - maxi << endl;
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

