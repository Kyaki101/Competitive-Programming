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

bool first(vector<ll> & transform, ll n, ll k) {
    vector<ll> acum(n);
    acum[0] = transform[0];
    for(int i = 1; i < n; i++) {
        acum[i] = acum[i - 1] + transform[i];
    }
    vector<ll> msp(n);
    msp[n - 1] = acum[n - 1];
    for(int i = n - 2; i > 0; i--) {
        msp[i] = max(acum[i], msp[i + 1]);
    }

    
    for(int i = 0; i < n - 2; i++) {
        if(acum[i] >= 0 && msp[i + 1] >= acum[i]) return true;
    }
    return false;
}

bool second(vector<ll> & transform, ll n, ll k) {
    vector<ll> acum(n);
    acum[0] = transform[0];
    for(int i = 1; i < n; i++) {
        acum[i] = transform[i] + acum[i - 1];
    }
    ll x = -1;
    ll y = -1;
    for(int i = 0; i < n; i++) {
        if(acum[i] == 0) {
            x = i;
            break;
        }
    }
    for(int i = n - 1; i > 0; i--) {
        if(acum[n - 1] - acum[i - 1] >= 0) {
            y = i;
            break;
        }
    }
    if(x != -1 && y != -1 && x + 2 <= y) return true;
    return false;
}

void solve(){        
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    vector<ll> transform(n);
    for(int i = 0; i < n; i++) {
        if(a[i] <= k) transform[i] = 1;
        else transform[i] = -1;
    }
    vector<ll> tra(ALL(transform));
    reverse(ALL(tra));
    if(first(transform, n, k) || second(transform, n, k) || first(tra, n, k)) {
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

