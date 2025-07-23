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
    vector<ll> b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    for(int i = 1; i < n; i++) {
        if(a[i] > a[i - 1]) {
            cout << "NO" << endl;
            return;
        }
        if(b[i] < b[i - 1]) {
            cout << "NO" << endl;
            return;
        }
    }
    for(int i = 0; i < n; i++) {
        if(a[0] % a[i] != 0) {
            cout << "NO" << endl;
            return;
        }
        if(b[n - 1] % b[i] != 0) {
            cout << "NO" << endl;
            return;
        }
    }
    if(n == 1) {
        if(a[0] == b[0]) cout << "YES" << endl;
        else cout << "NO" << endl;
        return;
    }
    if(gcd(a[0], b[1]) == b[0] && gcd(b[n - 1], a[n - 2]) == a[n - 1]) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
    return;


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

