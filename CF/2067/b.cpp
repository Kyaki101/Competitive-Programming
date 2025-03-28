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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(ALL(a));
    ll maxi = 0;
    if(n & 1) {
        cout << "NO" << endl;
        return;
    }
    if(a[0] != a[1]) {
        cout << "NO" << endl;
        return;
    }
    maxi = a[0];
    for(int i = 2; i < n; i+=2) {
        if(a[i] <= maxi && a[i + 1] <= maxi) {
            a[i] = maxi + 1;
            a[i + 1] = maxi + 1;
            maxi ++;
        }
        else if(a[i] <= maxi) {
            a[i] = maxi + 1;
            maxi ++;
            if(a[i] != a[i + 1]) {
                cout << "NO" << endl;
                return;
            }
        }
        else {
            maxi = a[i];
            if(a[i + 1] != a[i]) {
                cout << "NO" << endl;
                return;
            }
        }
        
        
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

