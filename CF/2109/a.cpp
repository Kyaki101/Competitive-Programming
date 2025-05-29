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

void solve(){        
    ll n;
    cin >> n;
    vector<ll> a(n);
    bool found = false;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 0) found = true;
    }
    if(!found) {
        cout << "YES" << endl;
        return;
    }
    if(a[0] == 0) {
        if(a[1] == 0) {
            cout << "YES" << endl;
            return;
        }
    }

    for(int i = 1; i < n - 1; i++) {
        if(a[i] == 0) {
            if(a[i - 1] != 1 || a[i + 1] != 1)  {
                cout << "YES" << endl;
                return;
            }
        }
    }
    if(a[n - 1] == 0 && a[n - 2] == 0) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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

