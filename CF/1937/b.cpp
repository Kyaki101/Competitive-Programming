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
    string up, down;
    cin >> up >> down;
    ll count = 0;
    string ans = "";
    bool u = true;
    for(int i = 0; i < n - 1; i++) {
        if(u) ans += up[i];
        else ans += down[i];
        if(u && up[i + 1] == '1' && down[i] == '0') {
            u = false;
            ans += down[i];
        }
    }
    if(u) {
        ans += up[n - 1];
        ans += down[n - 1];
    }
    else {
        ans += down[n - 1];
    }
    cout << ans << endl;

    count = 0;
    vector<ll> acum(n, 0);
    for(int i = n; i > 0; i--) {
        if(down[i - 1] == ans[i]) {
            count ++;
        }
        acum[i - 1] = count;
    }
    ll r = 0;
    for(int i = 0; i < n; i++) {
        if(up[i] != ans[i]) {
            break;
        }
        if(acum[i] == (ans.size() - (i + 1))) r++;
    }
    cout << r << endl;

    
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

