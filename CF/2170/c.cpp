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
    vll a(n);
    vll b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;

    sort(ALL(a));
    sort(ALL(b));

    ll i = 0, j = n - 1;
    ll lowest = 0;
    ll ans = 0;
    vector<bool> as(n, false);
    vector<bool> bs(n, false);
    while(i < n && j > -1) {
        if((b[j] + 1) * a[i] + b[j] <= k) {
            ans ++;
            as[i] = true;
            bs[j] = true;
            i++;
            j--;
        }
        else {
            j --;
        }
    }

    i = n - 1; j = 0;
    while(j < n && i > -1) {
        while(bs[j] && j < n) j++;
        while(as[i] && i > -1) i--;
        if(j >= n || i < 0) continue;
        if((b[j] + 1) * a[i] + b[j] <= k) {
            ans ++;
            i--;
            j++;
        }
        else {
            i--;
        }
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

