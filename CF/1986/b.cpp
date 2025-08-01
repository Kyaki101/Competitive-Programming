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

bool valid(ll i, ll j, ll n, ll m) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

ll mvs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

ll getNeighb(vector<vector<ll>> & mat, ll i, ll j) {
    ll n = mat.size();
    ll m = mat[0].size();
    vector<ll> ans;
    for(int k = 0; k < 4; k++) {
        ll x = i + mvs[k][0];
        ll y = j + mvs[k][1];
        if(valid(x, y, n, m)) {
            ans.push_back(mat[x][y]);
        }
    }
    sort(ALL(ans));
    if(ans.size() == 0) {
        return (1LL << 60);
    }
    return ans[ans.size() - 1];

}

void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> mat(n, vector<ll>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ll bruh = getNeighb(mat, i, j);
            if(bruh < mat[i][j]) {
                mat[i][j] = bruh;
            }
            
        }
    }
    for (auto i : mat) {
        for (auto j : i) {
            cout << j << ' ';
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

