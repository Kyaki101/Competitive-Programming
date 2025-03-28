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

void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<string> mat(n);
    for(int i = 0; i < n; i++) {
        cin >> mat[i];
    }


    vector<vector<ll> > rowAcum(n, vector<ll>(m, 0));
    vector<vector<ll> > colAcum(m, vector<ll>(n, 0));


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(j == 0) {
                rowAcum[i][j] = mat[i][j] == '1';
            }
            else rowAcum[i][j] = (mat[i][j] == '1') + rowAcum[i][j - 1];
        }
    }


    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                colAcum[j][i] = mat[i][j] == '1';
            }
            else colAcum[j][i] = (mat[i][j] == '1') + colAcum[j][i - 1];
        }
    }

    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == '1' && colAcum[j][i] != i + 1 && rowAcum[i][j] != j + 1) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    return;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

