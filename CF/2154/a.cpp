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
    string s;
    cin >> s;
    ll ones = 0;
    ll ans = 0;
    for(int i = 0; i < k; i++) {
        if(s[i] == '1' && !ones) {
            ones ++;
            ans ++;
            continue;
        }
        if(s[i] == '1') ones++;
    }
    for(int i = k; i < n; i++) {
        if(s[i - k] == '1') ones--;
        if(s[i] == '1' && !ones) {
            ans ++;
            ones ++;
            continue;
        }
        if(s[i] == '1') ones ++;
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

