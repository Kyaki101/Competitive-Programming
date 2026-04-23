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
    ll n, m, h;
    cin >> n >> m >> h;
    vll a(n);
    for(auto &i : a) cin >> i;
    vll bruh = a;
    vll ids(n);
    ll id = 0;
    for(int i = 0; i < m; i++) {
        ll b, c;
        cin >> b >> c;
        if(ids[b - 1] != id) {
            bruh[b - 1] = a[b - 1];
        }
        bruh[b - 1] += c;
        if(bruh[b - 1] > h) {
            id++;
            bruh[b - 1] = a[b - 1];
        }
        ids[b - 1] = id;
    }

    for(int i = 0; i < n; i++) {
        if(ids[i] != id) {
            cout << a[i] << ' ';
        }
        else cout << bruh[i] << ' ';
    }
    cout << endl;

    
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

