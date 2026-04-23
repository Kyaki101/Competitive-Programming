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
    ll m;
    cin >> m;
    vector<ll> a(n);
    vector<ll> b(m);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    vector<ll> c;
    ll j = 0;
    for(int i = 0; i < a.size(); i++) {
        while(j < b.size() && b[j] < a[i]) {
            c.PB(b[j]);
            j++;
        }
        c.PB(a[i]);
    }
    while(j < b.size()) {
        c.PB(b[j]);
        j++;
    }
    for(auto i : c) cout << i << ' ';
    cout << endl;
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

