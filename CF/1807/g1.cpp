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
    vector<ll> c(n);
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(ALL(c));
    if(c[0] != 1) {
        cout << "NO" << endl;
        return;
    }

    ll suma = 0;
    suma += 1;
    for(int i = 1; i < n; i++) {
        
        if(c[i] > suma) {
            cout << "NO" << endl;
            return;
        }
        suma += c[i];
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

