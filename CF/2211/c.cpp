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
    ll n, k;
    cin >> n >> k;
    vll a(n);
    vll b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    vector<ll> check(n + 1, 0);
    vector<ll> expected(n + 1, 0);
    for(int i = 0; i < k; i++) {
        if(b[i] != -1) check[i] ++;
        a[i] ++;
    }
    for(int i = 0; i <= n; i++) {
        if(check[i] > a[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    ll back = 0;
    for(int i = k; i < n; i++) {
        

    }
    
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

