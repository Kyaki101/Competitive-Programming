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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll a = 0, b = 0;
    ll x = 0, y = 0;
    map<ll, ll> mapa;
    ll mini = n;
    for(auto i : s) {
        if(i == 'a') x ++;
        else y ++;
    }
    ll diff = x - y;
    if(diff == 0) {
        cout << 0 << endl;
        return;
    }

    mapa[0] = -1;

    for(int i = 0; i < n; i++) {
        (s[i] == 'a') ? a++ : b++;


        if(mapa.find((a - b) - diff) != mapa.end()) {
            mini = min(mini, i - mapa[(a - b) - diff]);
        }
        mapa[a - b] = i;
    }

    if(mini == n) {
        cout << -1 << endl;
        return;
    }
    cout << mini << endl;
    
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

