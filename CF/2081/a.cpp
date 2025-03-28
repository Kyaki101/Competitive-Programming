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
    vector<ll> rows(n, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == '1') {
                rows[i] ++;
            }
        }
    }


    vector<ll> cols(m, 0);
    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            if(mat[i][j] == '1') {
                cols[j] ++;
            }
        }
    }



    ll tZ = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == '1') tZ ++;
        }
    }
    ll sC = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(rows[i] % 2 == 0 && rows[i] > 0 && cols[j] % 2 == 1) {
                sC += 2;
                rows[i] ++;
            }
            else if(rows[i] % 2 == 1 && cols[j] > 0 && cols[j] % 2 == 0) {
                sC += 2;
                cols[j] ++;
            }
            else if(rows[i] % 2 == 0 && rows[i] > 0 && cols[j] % 2 == 0 && cols[j] > 0) {
                sC ++;
                cols[j] ++;
                rows[i] ++;
            }
        }
    }
    cout << sC << endl;
    cout << min(sC, tZ) << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

