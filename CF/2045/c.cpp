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
    string a, b;
    cin >> a >> b;
    map<char, ll> mapa;
    ll n = a.size();
    ll m = b.size();
    ll mini = (1 << 30);
    for(int i = 0; i < m - 1; i++) {
        mapa[b[i]] = i;
    }
    ll x = -1, y = - 1;
    for(int i = 1; i < n; i++) {
        if(mapa.find(a[i]) != mapa.end()) {
            ll tmp = mapa[a[i]];
            if(i + 1 + (m - tmp) < mini) {
                x = i;
                y = tmp;
                mini = i + 1 + (m - tmp);
            }
        }
    }
    if(x == -1) {
        cout << -1 << endl;
        return;
    }
    string ans = "";
    for(int i = 0; i < x; i++) {
        ans.PB(a[i]);
    }
    for(int i = y; i < m; i++) {
        ans.PB(b[i]);
    }
    cout << ans << endl;
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

