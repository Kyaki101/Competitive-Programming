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
    ll n;
    cin >> n;
    vector<vector<ll> > mat(n, vector<ll>(n));

    vector<ll> ans(n, (1 << 30) - 1);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j) ans[i] = ans[i] & mat[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j && (ans[i] | ans[j]) != mat[i][j]) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;

    for(auto i : ans) cout << i << ' ';
    cout << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

