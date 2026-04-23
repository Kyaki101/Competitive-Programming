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
    ll n, m, k;
    cin >> n >> m >> k;
    ll lDist = k - 1;
    ll rDist = n - k;
    if(lDist < rDist) {
        swap(lDist, rDist);
    }
    ll a = 0;
    ll b = 0;
    bool check = true;
    while(check) {
        if(b < rDist && a + (b + 1) + max(a, b + 1) - 1 <= m) b++;
        if(a < lDist && (a + 1) + b + max(a + 1, b) - 1 <= m) a++;
        else check = false;

    }
    cout << a + b + 1 << endl;
    
    
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

