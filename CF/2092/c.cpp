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
ll n;

void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll evens = 0, odds = 0;

    ll maximus = 0;
    ll suma = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        suma += a[i];
        if(a[i] & 1) odds++;
        else evens ++;
        maximus = max(maximus, a[i]);
    }
    if(odds == 0 || evens == 0) {
        cout << maximus << endl;
        return;
    }

    ll ans = suma - (odds - 1);
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

