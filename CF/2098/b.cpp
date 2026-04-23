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
    for(auto &i : a) cin >> i;
    sort(ALL(a));
    if(n == 1) {
        cout << 1 << endl;
        return;
    }



    if(n & 1) {
        if(k == 0) {
            cout << 1 << endl;
            return;
        }
        if(k & 1) {
            k --; 
        }
        else {
            k -= 2;
        }
        k = k / 2;
        ll l = n / 2 - 1;
        ll r = n / 2 + 1;

        cout << a[r + k] - a[l - k] + 1 << endl;
        return;
    }

    if(k == 1) {
        cout << a[n / 2] - a[n / 2 - 1] + 1 << endl;
        return;
    }

    k /= 2;
    cout << 1 + a[n / 2 + k] - a[n / 2 - 1 - k]<< endl;

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

