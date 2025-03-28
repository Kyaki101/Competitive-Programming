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
    if(!(n & 1)) {
        cout << -1 << endl;
        return;
    }


    vector<ll> a(n + 1);
    a[n / 2 + 1] = n / 2 + 1;


    ll dist = 1;
    for(int i = n / 2 + 2; i <= n; i++) {
        if((i + dist) % n == 0) {
            a[i] = n;
        }
        else {
            a[i] = (i + dist) % n;
        }
        dist ++;
    }

    for(int i = 1; i < n / 2 + 1; i++) {
        if((i + dist) % n == 0) {
            a[i] = n;
        }
        else {
            a[i] = (i + dist) % n;
        }
        dist ++;
    }
    for(int i = 1; i <= n; i++) {
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

