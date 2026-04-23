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

bool check(ll n, ll m, vector<vll> &mat) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m - 1; j++) {
            ll c = mat[i][j] + mat[i][j + 1] + mat[i + 1][j] + mat[i + 1][j + 1];
            if(c != 2) return false;
        }
    }
    return true;
}


void countValid(ll n, ll m, vector<vll> & mat, ll i, ll j, ll &count) {
    if(j == m) {
        i ++;
        j = 0;
    }
    if(i == n) {
        count += check(n, m, mat);
        return;
    }
    mat[i][j] = 0;
    countValid(n, m, mat, i, j + 1, count);
    mat[i][j] = 1;
    countValid(n, m, mat, i, j + 1, count);

}

void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<vll> mat(n, vll(m, 0));
    ll count = 0;
    countValid(n, m, mat, 0, 0, count);
    cout << count << endl;
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

