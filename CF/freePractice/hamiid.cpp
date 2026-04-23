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
    ll n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    p--;
    ll rDist = 0;
    ll lDist = 0;
    for(int i = p + 1; i < n; i++) {
        if(s[i] == '#') {
            rDist = (n - i) + 1;
            break;
        }
    }
    for(int i = p - 1; i > -1; i--) {
        if(s[i] == '#') {
            lDist = i + 2;
            break;
        }
    }

    if(lDist == 0 && rDist == 0 || p == n - 1 || p == 0) {
        cout << 1 << endl;
        return;
    }

    if(lDist < rDist) {
        cout << min(p + 1, rDist) << endl;
        return;
    }
    else {
        cout << min(lDist, n - p) << endl;
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

