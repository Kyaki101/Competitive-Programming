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
    if(n >= 7) {
        for(int i = 1; i <= n; i++, i++) {
            if(i != 7) cout << i << ' ';
        }
        cout << 7 << ' ';
        for(int i = 2; i <= n; i++, i++) {
            cout << i << ' ';
        }
        cout << endl;
        return;
    }

    if(n == 6) {
        cout << 2 << ' ' << 6 << ' ' << 4 << ' ' << 5 << ' ' << 3 << ' ' << 1 << endl;
        return;

    }
    if(n == 5) {
        cout << 2 << ' ' << 4 << ' ' << 5 << ' ' << 1 << ' ' << 3 << endl;
        return;
    }

    cout << -1 << endl;
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

