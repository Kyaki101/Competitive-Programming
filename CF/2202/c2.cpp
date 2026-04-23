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
    vll a(n);
    for(auto &i : a) cin >> i;
    vll bruh(n);
    vll anchors(n);
    map<ll, ll> mapa;
    mapa[a[0]] = 0;

    ll id = 1;
    bruh[0] = id;
    ll mini = a[0];
    anchors[0] = -1;

    for(int i = 1; i < n; i++) {
        mapa[a[i]] = i;
        if(a[i] > mini + 1 || mapa.find(a[i] - 1) == mapa.end() || bruh[mapa[a[i] - 1]] != id) {
            anchors[i] = -1;
            id ++;
        }
        else {
            anchors[i] = mapa[a[i] - 1];
        }
        bruh[i] = id;
        mini = a[i];
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(anchors[i] == -1) {
            ans += (i + 1) * (n - i);
        }
        else {
            ans += (i - anchors[i]) * (n - i);
        }
    }
    cout << ans << endl;
    
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

