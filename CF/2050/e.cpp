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


ll fill(string & a, string & b, string & c, vector<vector<ll>> & memo, vector<vector<bool>> & vis, ll i, ll j) {
    if(i == a.size() && j == b.size()) return 0;
    if(vis[i][j]) return memo[i][j];
    vis[i][j] = true;
    if(i == a.size()) {
        if(c[i + j] == b[j]) {
            return memo[i][j] = fill(a, b, c, memo, vis, i, j + 1);
        }
        return memo[i][j] = 1 + fill(a, b, c, memo, vis, i, j + 1);
    }

    if(j == b.size()) {
        if(c[i + j] == a[i]) {
            return memo[i][j] = fill(a, b, c, memo, vis, i + 1, j);
        }
        return memo[i][j] = 1 + fill(a, b, c, memo, vis, i + 1, j);
    }
    ll val = (1 << 30);
    if(b[j] == c[i + j]) {
        val = min(val, fill(a, b, c, memo, vis, i, j + 1));
    }
    else {
        val = min(val, fill(a, b, c, memo, vis, i, j + 1) + 1);
    }
    if(a[i] == c[i + j]) {
        val = min(val, fill(a, b, c, memo, vis, i + 1, j));
    }
    else val = min(val, fill(a, b, c, memo, vis, i + 1, j) + 1);
    return memo[i][j] = val;

}
ll t;

void solve(){        
    string a;
    string b;
    string c;
    cin >> a >> b >> c;
    vector<vector<ll>> memo(a.size() + 1, vector<ll>(b.size() + 1, 0));
    vector<vector<bool>> vis(a.size() + 1, vector<bool>(b.size() + 1, false));
    fill(a, b, c, memo, vis, 0, 0);
    cout << memo[0][0] << endl;;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

