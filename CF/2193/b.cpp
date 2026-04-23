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
    unordered_map<ll, ll> mapa;
    for(int i = 0; i < n; i++) {
        mapa[a[i]] = i;
    }
    iota(ALL(bruh), 1LL);
    reverse(ALL(bruh));
    bool found = false;
    for(int i = 0; i < n; i++) {
        if(a[i] != bruh[i] && !found) {
            found = true;
            for(int j = mapa[bruh[i]]; j >= i; j--) {
                cout << a[j] << ' ';
            }
            i = mapa[bruh[i]];
        }
        else {
            cout << a[i] << ' ';
        }
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
    }return 0;
}

