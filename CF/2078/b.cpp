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
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    if(x & 1) {
        for(int i = 0; i < n; i++) {
            if(i == n - 1) {
                a[i] = n - 1;
            }
            else a[i] = n;
        }
        for(int i = 0; i < n ;i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        if(i == n - 2) {
            a[i] = n;
        }
        else a[i] = n - 1;
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

