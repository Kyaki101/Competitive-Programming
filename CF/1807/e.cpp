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
    vector<ll> acum(n + 1, 0);
    partial_sum(ALL(a), acum.begin() + 1);
    ll l = 1, r = n + 1;
    
    while(l + 1 < r) {
        ll mid = (r + l) / 2;
        cout << "? ";
        cout << (r - mid) << ' ';
        for(int j = mid; j < r; j++) {
            cout << j << ' ';
        }
        cout << endl << flush;


        ll ans;
        cin >> ans;
        if(ans > acum[r - 1] - acum[mid - 1]) {
            l = mid;
        }
        else {
            r = mid;
        }

    }
    cout << "! " << l << endl << flush;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

