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


    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(m);


    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }


    ll k = 0;
    ll i = 0;
    ll j = 0;
    vector<ll> c(m + n);

    while(i < n || j < m) {
        if(j == m || i < n && a[i] < b[j]) {
            c[k] = a[i];
            k ++;
            i ++;
        }
        else {
            c[k] = b[j];
            k ++;
            j ++;
        }
    }

    for(auto i : c) {
        cout << i << ' ';
    }
    cout << endl;
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}

