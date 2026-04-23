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

ll proc(ll n) {
    ll count = 0;
    while(n) {
        if(n & 1) n--;
        else n /= 2;
        count ++;
    }
    return count;
}

void solve(){        
    ll n;
    cin >> n;
    map<ll, vll> mapa;
    for(int i = 1; i <= n; i++) {
        mapa[proc(i)].PB(i);
    }
    ll acum = 0;
    for(auto &[x, y] : mapa) {
        cout << x << ": ";
        for(auto i : y) cout << i << ' ';
        acum += y.size();
        cout << ": " << y.size()  << endl;
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

