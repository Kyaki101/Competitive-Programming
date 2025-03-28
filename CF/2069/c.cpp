#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
typedef long long int ll;
const int MAX = 2e5+20, MOD = 998244353;
int t=1;



void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> acum(n, 0);
    ll streak = 0;
    ll ones = 0;
    ll threes = 0;
    for(int i = 0; i < n; i++) if(a[i] == 3) threes ++;

    ll ans = 0;

    for(int i = 0; i < n; i++) {
        if(a[i] == 2) streak ++;
        if(streak && a[i] != 2) {
            cout << ones << ' ' << threes << ' ' << streak << endl;
            ll first = ((1LL << streak) - 1) % MOD;
            ll second = ((first % MOD) * (threes % MOD)) % MOD;
            ll third = ((second % MOD) * (ones % MOD)) % MOD;
            ans = ((ans % MOD) + (third % MOD)) % MOD;
            streak = 0;
        }

        if(a[i] == 1) ones ++;

        if(a[i] == 3) threes --;
    }

    cout << ans << endl;




}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

