#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
typedef long long int ll;
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

void solve(){        
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(ALL(a));
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll prev = a[i - 1];
        if(i == 0) prev = 0;
        while(a[i] > prev + 1) {
            ans += prev + 1;
            prev++;
        }
    }
    if(ans > k) {
        cout << "NO" << endl;
        return;
    }

    ll curr = a[n - 1] + 1;
    while(ans < k) {
        ans += curr;
        curr ++;
    }
    if(ans > k) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

