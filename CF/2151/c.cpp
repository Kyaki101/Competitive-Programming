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
    ll n;
    cin >> n;
    vll a(2 * n + 2);
    for(int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
    }
    ll l = 0;
    ll r = 2 * n + 1;
    vll ev(2 * n + 2), odd(2 * n + 2);
    for(int i = 1; i <= 2 * n; i++) {
        if(i & 1) {
            odd[i] = odd[i - 1] + a[i];
            ev[i] = ev[i - 1];
        }
        else {
            odd[i] = odd[i - 1];
            ev[i] = ev[i - 1] + a[i];
        }
    }

    ll ans = 0;
    ll borders = 0;
    for(int i = 0; i < n; i++) {
        ll e = ev[r - 1] - ev[l];
        ll o = odd[r - 1] - odd[l];
        borders += a[r] - a[l];
        if(i & 1) {
            cout << (o - e) + borders << ' ';
        }
        else {
            cout << (e - o) + borders << ' ';
        }
        l ++;
        r --;
    }
    cout << endl;
    
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

