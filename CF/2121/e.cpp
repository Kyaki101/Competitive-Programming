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
    ll a, b;
    cin >> a >> b;
    string x = to_string(a);
    string y = to_string(b);
    ll n = x.size();
    ll ans = 0;
    bool active = false;
    for(int i = 0; i < n; i++) {
        if((x[i] == y[i] || y[i] - x[i] == 1) && active) {
            break;
        }
        else if(x[i] == y[i]) {
            ans += 2;
        }
        else if(y[i] - x[i] == 1 || (x[i] == '9' && y[i] == '0')) {
            ans ++;
            active = true;
        }
        else break;

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

