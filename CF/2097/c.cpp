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
    map<ll, pair<ll, ll>> mapa;
    for(int i = 0; i < n; i++) {
        mapa[a[i]].first ++;
        mapa[a[i]].second = false;
    }
    for(auto [num, stat] : mapa) {
        if(stat.first >= 4 || stat.first >= 2 && stat.second) {
            cout << "YES" << endl;
            return;
        }
        if(stat.first >= 2 || stat.second) {
            if(mapa.find(num + 1) != mapa.end()) {
                mapa[num + 1].second = true;
            }
        }
    }
    cout << "NO" << endl;

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

