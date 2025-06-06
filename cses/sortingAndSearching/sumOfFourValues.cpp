#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    map<ll, pair<ll, ll>> mapa;
    for(int i = 0 ; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(mapa.find(k - (a[i] + a[j])) != mapa.end()) {
                cout << i + 1 << ' ' << j + 1 << ' ' << mapa[k - (a[i] + a[j])].first + 1 << ' ' << mapa[k - (a[i] + a[j])].second + 1 << endl;
                return;
            }
        }
        for(int j = i - 1; j > - 1; j--) {
            mapa[a[i] + a[j]] = {i, j};
        }
    }
    cout << "IMPOSSIBLE" << endl;
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

