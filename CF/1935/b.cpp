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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    map<ll, ll> mapa;
    for(int i = 0; i < n; i++) {
        mapa[a[i]] ++;
    }
    ll mex = 0;
    auto it = mapa.begin();
    while(it != mapa.end() && it->first == mex) {
        it++;
        mex ++;
    }
    if(mex == 0) {
        cout << 2 << endl;
        cout << 1 << ' ' << 1 << endl << 2 << ' ' << n << endl;
        return;
    }
    set<ll> left;
    for(int i = 0; i < n; i++) {
        if(a[i] < mex) {
            left.insert(a[i]);
            mapa[a[i]] --;
            if(mapa[a[i]] == 0) {
                cout << -1 << endl;
                return;
            }
            if(left.size() == mex) {
                cout << 2 << endl;
                cout << 1 << ' ' << i + 1 << endl << i + 2 << ' ' << n << endl;
                return;
            }
        }
    }
    cout << -1 << endl;

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

