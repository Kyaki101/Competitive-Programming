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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll zc = 0;
    ll oc = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') oc++;
        else zc++;
    }
    ll rem = n - (2 * k);
    zc -= rem / 2;
    oc -= rem / 2;
    if(zc < 0 || oc < 0) {
        cout << "NO" << endl;
        return;
    }
    n -= rem;
    if(zc / 2 + oc / 2 == k) {
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

