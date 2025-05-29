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
ll n;


ll allGcd(vector<ll> & a) {
    ll n = a.size();
    ll gc = a[0];
    for(int i = 0; i < n; i++) {
        gc = gcd(a[i], gc);
    }
    return gc;
}

void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(ALL(a));
    if(a[0] == a[1]) {
        cout << "YES" << endl;
        return;
    }
    vector<ll> mod;
    for(int i = 1; i < n; i++) {
        if(a[i] % a[0] == 0) {
            mod.push_back(a[i]);
        }
    }
    if(mod.size() == 0) {
        cout << "NO" << endl;
        return;
    }
    if(mod.size() == 1) {
        cout << "NO" << endl;
        return;
    }

    if(allGcd(mod) == a[0]) {
        cout << "YES" << endl;
        return;
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

