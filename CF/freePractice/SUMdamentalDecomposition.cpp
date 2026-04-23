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
    ll n, x;
    cin >> n >> x;
    if(n == 1 && x == 0) {
        cout << -1 << endl;
        return;
    }
    if(x == 0) {
        if(n & 1) {
            cout << n - 2 + 5 << endl;
            return;
        }
        cout << n << endl;
        return;
    }
    if(x == 1) {
        if(n & 1) {
            cout << n << endl;
            return;
        }
        cout << n - 2 + 5 << endl;
        return;
    }

    auto bitCount = [](ll num) {
        ll ans = 0;
        for(int i = 0; i < 40; i++) {
            if(TEST(num, i)) {
                ans++;
            }
        }
        return ans;
    };


    
    if((bitCount(x) & 1) == (n & 1)) {
        cout << x + max(0LL, n - bitCount(x)) << endl;
        return;
    }
    else {
        cout << x + max(0LL, n - bitCount(x) + 1) << endl;
        return;
    }


    cout << n - 2 + (SET(x, 0)) + 1 << endl;
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

