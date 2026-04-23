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
    vector<vll> a(n, vll(m));
    for(auto &i : a) for(auto &j : i) cin >> j;

    vector<vll> b(n, vll(m));
    for(auto &i : b) for(auto &j : i) cin >> j;
    
    vector<vll> rowsA(n, vll(m)), colsA(m, vll(n)), rowsB(n, vll(m)), colsB(m, vll(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            rowsA[i][j] = a[i][j];
            colsA[j][i] = a[i][j];
            rowsB[i][j] = b[i][j];
            colsB[j][i] = b[i][j];
        }
    }

    for(auto &i : rowsA) sort(ALL(i));
    for(auto &i : rowsB) sort(ALL(i));
    for(auto &i : colsA) sort(ALL(i));
    for(auto &i : colsB) sort(ALL(i));



    sort(ALL(rowsA));
    sort(ALL(rowsB));
    sort(ALL(colsA));
    sort(ALL(colsB));



    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(rowsA[i][j] != rowsB[i][j]) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            if(colsA[j][i] != colsB[j][i]) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;



    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
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

