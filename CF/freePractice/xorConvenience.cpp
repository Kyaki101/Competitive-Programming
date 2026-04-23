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

bool isPot(ll n) {
    return (!(n & (n - 1)));
}

ll msb(ll n) {
    ll index = 0;
    for(int i = 0; i < 60; i++) {
        if(TEST(n, i)) index = i;
    }
    return index;
}

void solve(){        
    ll n;
    cin >> n;
    if(!(n & 1)) {
        cout << n << ' ';
        for(int i = 2; i < n; i += 2) {
            cout << i + 1 << ' ' << i << ' ';
        }
        cout << 1 << endl;
        return;
    }
    cout << n - 1 << ' ';
    for(int i = 2; i < n - 1; i += 2) {
        cout << i + 1 << ' ' << i << ' ';
    }
    cout << n << ' ' << 1 << endl;

    
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

