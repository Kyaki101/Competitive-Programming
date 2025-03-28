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
    vector<vector<ll> > mat(n, vector<ll>(m));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    
    if(n == 1 && m == 1) {
        cout << -1 << endl;
        return;
    }


    if(m == 1) {
        mat.insert(mat.begin(), mat[n - 1]);
        mat.pop_back();
        for(auto i : mat) {
            for(auto j : i) {
                cout << j << ' ';
            }
            cout << endl;
        }
        return;
    }



    for(int i = 0; i < n; i++) {
        mat[i].insert(mat[i].begin(), mat[i][m - 1]);
        mat[i].pop_back();
    }


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

