#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
typedef long long int ll;
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

void solve(){        
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char, ll> mapa;
    for(auto i : s) mapa[i] ++;

    ll ans = 0;
    for(int i = 65, j = 97; i < 92; i++, j++) {
        ll bru = min(mapa[i], mapa[j]);
        ans += bru;
        mapa[i] -= bru;
        mapa[j] -= bru;
    }


    for(int i = 65, j = 97; i < 92; i++, j++) {
        ll bruh = min(max(mapa[i], mapa[j]) / 2, k);
        ans += bruh;
        k -= bruh;
    }
    cout << ans << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

