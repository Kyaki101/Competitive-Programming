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


ll fibo(ll n, ll a, ll b) {
    if(n == 1) return a;
    if(n == 2) return b;
    return fibo(n - 1, b, a + b);
}

void solve(){        
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(m, vector<ll>(3, 0));
    for(int i = 0; i < m; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    string ans = "";
    if(n > 26) {
        for(int i = 0; i < m; i++) {
            cout << 0;
        }
        cout << endl;
    }
    ll fi = fibo(n, 1, 2);
    for(int i = 0; i < m; i++) {
        char curr = '0';
        if(a[i][0] >= fi + fibo(n - 1, 1, 2)) {
            if(a[i][1] >= fi && a[i][2] >= fi) curr = '1';

        }
        if(a[i][1] >= fi + fibo(n - 1, 1, 2)) {
            if(a[i][0] >= fi && a[i][2] >= fi) curr = '1';

        }

        if(a[i][2] >= fi + fibo(n - 1, 1, 2)) {
            if(a[i][1] >= fi && a[i][0] >= fi) curr = '1';

        }
        ans += curr;
    }
    cout << ans << endl;


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

