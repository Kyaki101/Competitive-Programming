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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for(auto & i : a) cin >> i;
    for(auto & i : b) cin >> i;
    vector<ll> pref(n + 1, 0), suff(n + 1, 0);
    ll p = 0;
    for(int i = 1; i <= n && p < m; i++) {
        pref[i] = pref[i - 1];
        if(a[i - 1] >= b[p]) pref[i] ++, p++;
    }
    if(p == m) {
        cout << 0 << endl;
        return;
    }

    p = m - 1;
    for(int i = n - 1; i > -1 && p > -1; i--) {
        if(i != n - 1) suff[i] = suff[i + 1];
        if(a[i] >= b[p]) {
            p--;
            suff[i] ++;
        }
    }
    ll mini = (1LL << 40);
    bool found = false;

    for(int i = 0; i < n; i++) {
        if(pref[i] + suff[i] >= m - 1) {
            found = true;
            mini = min(mini, b[pref[i]]);
        }
    }
    if(!found) {
        cout << -1 << endl;
        return;
    }
    cout << mini << endl;

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

