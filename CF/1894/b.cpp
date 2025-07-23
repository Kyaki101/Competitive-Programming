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
    for(auto i : a) {
        mapa[i] ++;
    }
    vector<ll> sel;
    for(auto &i : mapa) {
        if(i.second >= 2) {
            sel.push_back(i.first);
        }
    }
    if(sel.size() < 2) {
        cout << "-1" << endl;
        return;
    }
    ll x = sel[0];
    ll y = sel[1];
    bool one = false, two = false;
    for(int i = 0; i < n; i++) {
        if(a[i] == x && !one) {
            cout << 1 << ' ';
            one = true;
        }
        else if(a[i] == x && one) {
            cout << 2 << ' ';
            one = false;
        }
        else if(a[i] == y && !two) {
            cout << 1 << ' ';
            two = true;
        }
        else if(a[i] == y && two) {
            cout << 3 << ' ';
            two = false;
        }
        else {
            cout << 1 << ' ';
        }
    }
    cout << endl;


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

