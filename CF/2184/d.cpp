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


ll msb(ll n) {
    ll index = 0;
    for(int i = 0; i < 60; i++) {
        if(TEST(n, i)) index = i;
    }
    return index + 1;
}

vector<vll> mat(32, vll(32));


void solve(){        
    ll n, k;
    cin >> n >> k;
    ll maxBit = msb(n);
    ll ans = maxBit > k;
    for(int i = 1; i < maxBit; i++) {
        for(int j = 0; j < i; j++) {
            if(i + j > k) {
                ans += mat[i - 1][j];
            }
        }
    }
    cout << ans << endl;

    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;

    for(int i = 0; i < 32; i++) {
        for(int j = 0; j < 32; j++) {
            if(j == 0) {
                mat[i][j] = 1;
                continue;
            }
            if(j > i) {
                mat[i][j] = 0;
                continue;
            }
            mat[i][j] = mat[i - 1][j - 1] + mat[i - 1][j];
        }
    }
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

