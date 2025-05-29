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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll> > mat(n, vector<ll>(m, 0));
    vector<ll> perm(k);
    for(int i = 0; i < k; i++) {
        perm[i] = i + 1;
    }

    if(m % k == 0) {
        vector<ll> perma(m);
        for(int i = 0; i < m; i++) {
            perma[i] = i % k + 1;
        }

        for(int i = 0; i < n; i++) {
            ll b = 0;
            if(i & 1) b = 1;
            for(int j = 0; j < m; j++) {
                mat[i][j] = perma[b];
                b++;
                b %= m;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << mat[i][j] << ' ';
            }
            cout << endl;
        }
        return;
    }
    ll b = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            mat[i][j] = perm[b];
            b ++;
            b %= k;
        }
    }

    for(auto i : mat) {
        for(auto j : i) cout << j << ' ';
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

