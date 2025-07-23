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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> mat(n, vector<ll>(m));
    for(auto &i : mat) for(auto &j : i) cin >> j;
    ll maxi = 0;
    vector<pair<ll, ll>> greatest;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] > maxi) {
                maxi = mat[i][j];
            }
        }
    }
    ll maxis = 0;
    vector<vector<ll>> vals(n, vector<ll>(m, 0));
    vector<ll> rows(n, 0);
    vector<ll> cols(m, 0);
    for(int j = 0; j < m; j++) {
        bool found = false;
        for(int i = 0; i < n; i++) {
            if(mat[i][j] == maxi) {
                cols[j] ++;
                maxis ++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == maxi) {
                rows[i]++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == maxi) {
                vals[i][j] = rows[i] + cols[j] - 1;
            }
            else vals[i][j] = rows[i] + cols[j];
            if(vals[i][j] == maxis) {
                cout << maxi - 1 << endl;
                return;
            }
        }
    }
    cout << maxi << endl;

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

