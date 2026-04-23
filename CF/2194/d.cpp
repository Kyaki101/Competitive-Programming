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

bool upVal(ll i) {
    return i > -1;
}

bool leftVal(ll j) {
    return j > -1;
}

void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> mat(n, vector<ll>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> mat[i][j];
    }

    vector<vector<pair<ll, ll>>> lab(n + 1, vector<pair<ll, ll>>(m + 1, {0, 0}));
    vector<vector<char>> path(n + 1, vector<char>(m + 1));

    vector<vector<ll>> acumRow(n, vll(m + 1));
    for(int i = 0; i < n; i++) {
        partial_sum(ALL(mat[i]), ++acumRow[i].begin());
    }
    vector<vector<ll>> acumCol(n + 1, vll(m));
    for(int j = 0; j < m; j++) {
        for(int i = 1; i <= n; i++) {
            acumCol[i][j] = acumCol[i - 1][j] + mat[i - 1][j];
        }
    }


    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(!leftVal(j - 1) && !upVal(i - 1)) continue;
            if(!leftVal(j - 1)) {
                lab[i][j] = { lab[i - 1][j].first + (acumRow[i - 1][m] - acumRow[i - 1][j]), lab[i - 1][j].second + acumRow[i - 1][j] };
                path[i][j] = 'D';
                continue;
            }
            if(!upVal(i - 1)) {
                lab[i][j] = { lab[i][j - 1].first, lab[i][j - 1].second + acumCol[n][j - 1] };
                path[i][j] = 'R';
                continue;
            }
            pair<ll, ll> up = { lab[i - 1][j].first + (acumRow[i - 1][m] - acumRow[i - 1][j]), lab[i - 1][j].second};
            pair<ll, ll> left = { lab[i][j - 1].first, lab[i][j - 1].second + (acumCol[n][j - 1] - acumCol[i][j - 1]) };
            if(up.first * up.second > left.first * left.second) {
                lab[i][j] = up;
                path[i][j] = 'D';
            }
            else {
                lab[i][j] = left;
                path[i][j] = 'R';
            }
        }
    }
    cout << lab[n][m].first * lab[n][m].second << endl;



    string p = "";
    ll i = n, j = m;
    while(i != 0 || j != 0) {
        p.PB(path[i][j]);
        if(path[i][j] == 'D') i = i - 1;
        else j = j - 1;

    }
    reverse(ALL(p));
    cout << p << endl;



    


    
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

