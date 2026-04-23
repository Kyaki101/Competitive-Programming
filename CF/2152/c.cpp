#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define F second
#define S first
#define PB push_back
#define ll long long
typedef vector<ll> vll;

const int MAX = 2e5+20, MOD = 1e9+7;

void solve(){        
    ll n, q;
    cin >> n >> q;
    vll s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vll pref0(n + 1, 0);
    vll pref1(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        if(s[i - 1] == 1) {
            pref1[i] = pref1[i - 1] + 1;
            pref0[i] = pref0[i - 1];
        }
        else {
            pref0[i] = pref0[i - 1] + 1;
            pref1[i] = pref1[i - 1];
        }
    }
    vll contPref(n + 1, 0);
    for(int i = 2; i <= n; i++) {
        if(s[i - 1] == s[i - 2]) {
            contPref[i] = contPref[i - 1] + 1;
        }
        else {
            contPref[i] = contPref[i - 1];
        }
    }
    while(q--) {
        ll l, r;
        cin >> l >> r;
        if((r - l + 1) % 3 != 0) {
            cout << -1 << endl;
            continue;
        }
        if((pref1[r] - pref1[l - 1]) % 3 != 0) {
            cout << -1 << endl;
            continue;
        }
        if((pref0[r] - pref0[l - 1]) % 3 != 0) {
            cout << -1 << endl;
            continue;
        }
        ll pairs = contPref[r] - contPref[l - 1];
        if(contPref[l] > contPref[l - 1]) pairs --;
        if(pairs) {
            cout << (r - l + 1) / 3 << endl;
            continue;
        }
        cout << 1 + (r - l + 1) / 3 << endl;
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

