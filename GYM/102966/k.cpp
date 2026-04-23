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

void solve() {        
    ll n, m;
    cin >> n >> m;
    vll a(n);
    vll b(m);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    ll p = 0;
    ll used = 0;
    ll avail = accumulate(ALL(b), 0LL);
    for(int i = 0; i < n; i++) {
        while(b[p] < a[i]) p++;
        if(b[p] >= a[i]) {
            b[p] -= a[i];
            used += a[i];
        }
    }
    cout << avail - used << endl;


    
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

