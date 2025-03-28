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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll first = 0, final = 0;
    vector<ll> acum(n);
    map<ll, bool> mapa;
    for(int i = 0; i < n; i++) {
        if(mapa.find(a[i]) != mapa.end()) {
            mapa[a[i]] = 1;
        }
        else {
            mapa[a[i]] = 0;
        }
    }

    for(int i = 0; i < n; i++) {
        acum[i] = mapa[a[i]];
    }

    ll longest = 0;
    ll ini = 0, end = 0;
    ll l = 0, r = 0;
    ll i = 0;
    while(i < n) {
        if(acum[i] == 0) {
            l = i + 1;
            while(i < n && acum[i] == 0) {
                i++;
            }
            r = i;
            if((r - l) + 1 > longest) {

                longest = (r - l) + 1;
                ini = l; end = r;
            }
        }
        i++;
    }
    if(longest == 0) {
        cout << 0 << endl;
        return;
    }
    cout << ini << ' ' << end << endl;
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

