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
    vector<ll> a(n), b(m);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    vector<vector<ll>> mat(n + 1, vector<ll>(m + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i - 1] == b[j - 1]) {
                mat[i][j] = mat[i - 1][j - 1] + 1;
            }
            else {
                mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
            }
        }
    }
    ll i = n, j = m;
    vector<ll> ans;
    while(i > 0 && j > 0) {
        if(a[i - 1] == b[j - 1]) {
            ans.push_back(a[i - 1]);
            i--;
            j--;
        }
        else if(mat[i - 1][j] > mat[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    reverse(ALL(ans));
    cout << ans.size() << endl;
    for(auto &i : ans) {
        cout << i << ' ';
    }
    cout << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

