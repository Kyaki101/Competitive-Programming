#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define F second
#define S first
#define PB push_back
#define ll long long
typedef vector<ll> vll;

const int MAX = 2e5+20, MOD = 1e9+7;


void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> mat(n, vll(m));
    for(auto &i: mat) for(auto &j : i) cin >> j;
    vector<bool> val(n);
    map<ll, ll> mapa;

    for(int i = 0; i < n; i++) {
        bool same = true;
        for(int j = 1; j < m; j++) {
            if(mat[i][j - 1] != mat[i][j]) same = false;
        }
        val[i] = same;
    }

    for(int i = 0; i < n; i++) {
        if(val[i]) mapa[mat[i][0]] ++;
    }

    pair<ll, ll> yay;

    ll po = 0;
    vll ans(n)
    for(int i = 0; i < n; i++) {
        if(val[i]) po ^= mat[i][0];
    }




    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
        #ifdef ICPC 
            cout << "--------------------------------------------------" << endl;
        #endif // 
    }
    #ifdef ICPC 
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}

