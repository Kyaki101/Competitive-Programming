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
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    ll suma = 0;
    map<ll, ll, greater<ll>> mapa;
    for(auto &i : a) {
        cin >> i;
        suma += i;
        mapa[i] ++;
    }

    if(suma == s) {
        cout << -1 << endl;
        return;
    }
    if(s < suma) {
        for(auto i : a) cout << i << ' ';
        cout << endl;
        return;
    }

    if(s - suma >= 2) {
        cout << -1 << endl;
        return;
    }
    if(s - suma == 1) {
        for(int i = 0; i < mapa[0]; i++) {
            cout << 0 << ' ';
        }
        for(int i = 0; i < mapa[2]; i++) {
            cout << 2 << ' ';
        }
        for(int i = 0; i < mapa[1]; i++) {
            cout << 1 << ' ';
        }
        cout << endl;
        return;
    }
    




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

