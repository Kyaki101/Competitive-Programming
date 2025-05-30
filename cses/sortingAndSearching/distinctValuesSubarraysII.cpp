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
    map<ll, ll> mapa;
    ll count = a.size();
    ll l = 0;
    mapa[a[0]] ++;
    for(int r = 1; r < n; r++) {
        mapa[a[r]] ++;
        while(l + 1 < r && mapa.size() > k) {
            mapa[a[l]] --;
            if(mapa[a[l]] == 0) {
                mapa.erase(a[l]);
            }
            l ++;
        }
        if(mapa.size() <= k) {
            count += r - l;
        }

    }
    cout << count << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}

