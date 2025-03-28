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
    ll negs = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] < 0) negs ++;
    }
    
    if(!(negs & 1)) {
        for(int i = 0; i < n; i++) {
            a[i] = abs(a[i]);
        }

        cout << accumulate(ALL(a), 0LL) << endl;

        return;
    }

    bool flag = false;
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) {
            if(i > 0) {
                if(a[i - 1] < 0) flag = true;
            }
            if(a[i] < n - 1) {
                if(a[i + 1] < 0) flag = true;
            }
        }
    }
    if(flag) {
        for(int i = 0; i < n; i++) {
            a[i] = abs(a[i]);
        }
        cout << accumulate(ALL(a), 0LL) << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        a[i] = abs(a[i]);

    }

    sort(ALL(a));

    ll suma = a[0];
    suma *= -1;
    suma += accumulate(a.begin() + 1, a.end(), 0LL);
    cout << suma << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

