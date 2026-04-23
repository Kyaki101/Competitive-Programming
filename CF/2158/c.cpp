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
    ll n, k;
    cin >> n >> k;
    vll a(n), b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    vll pref(n), suff(n);
    ll tmp = 0;
    for(int i = 0; i < n; i++) {
        pref[i] = tmp + a[i];
        tmp = max(tmp + a[i], 0LL);
    }
    tmp = 0;
    for(int i = n - 1; i > -1; i--) {
        suff[i] = tmp + a[i];
        tmp = max(tmp + a[i], 0LL);
    }
    if(!(k & 1)) {
        ll maxi = 0;
        ll t = 0;
        ll mini = -(1 << 30);
        bool check = false;
        for(int i = 0; i < n; i++) {
            mini = max(a[i], mini);
            if(a[i] == 0) check = true;
            t = max(t + a[i], 0LL);
            maxi = max(maxi, t);
        }
        if(maxi == 0 && check) {
            cout << 0 << endl;
            return;
        }
        if(maxi == 0) {
            cout << mini << endl;
            return;
        }
        cout << maxi << endl;
        return;
    }
    ll maxi = -(1 << 30);
    for(int i = 0; i < n; i++) {
        maxi = max(maxi, pref[i] + suff[i] - a[i] + b[i]);
    }
    cout << maxi << endl;


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

