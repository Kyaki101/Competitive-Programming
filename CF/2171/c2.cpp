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
    vll a(n), b(n);
    ll x = 0;
    for(auto &i : a) cin >> i, x ^= i;
    for(auto &i : b) cin >> i, x ^= i;

    ll msb;
    if(x == 0) {
        cout << "Tie" << endl;
        return;
    }
    for(int i = 60; i > -1; i--) {
        if(TEST(x, i)) {
            msb = i;
            break;
        }
    }

    ll idx = 0;
    for(int i = 0; i < n; i++) {
        if(TEST(a[i], msb) ^ TEST(b[i], msb)) {
            idx = i;
        }
    }
    if(idx & 1) {
        cout << "MAI" << endl;
        return;
    }
    cout << "AJISAI" << endl;
    

    
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

