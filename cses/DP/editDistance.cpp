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
    string a, b;
    cin >> a >> b;
    ll n = a.size();
    ll m = b.size();
    vector<vector<ll>> mat(n + 1, vector<ll>(m + 1, 0));
    for(int i = 0; i <= n; i++) mat[i][0] = i;
    for(int j = 0; j <= m; j++) mat[0][j] = j;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i - 1] == b[j - 1]) {
                mat[i][j] = mat[i - 1][j - 1];
            }
            else {
                mat[i][j] = min({
                    mat[i - 1][j],
                    mat[i][j - 1],
                    mat[i - 1][j - 1]
                }) + 1;
            }
            
        }
    }
    cout << mat[n][m] << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

