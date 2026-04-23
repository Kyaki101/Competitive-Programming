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
    vector<bool> changed(n);
    for(auto &i : a) cin >> i;
    map<ll, ll> mapa;
    mapa[1] = 6;
    mapa[6] = 1;
    mapa[2] = 5;
    mapa[5] = 2;
    mapa[3] = 4;
    mapa[4] = 3;
    ll counter = 0;
    for(int i = 1; i < n; i++) {
        if((a[i - 1] == a[i] || a[i - 1] == mapa[a[i]]) && !changed[i - 1]) {
            counter ++;
            changed[i] = true;
        }
    }
    cout << counter << endl;

    
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

