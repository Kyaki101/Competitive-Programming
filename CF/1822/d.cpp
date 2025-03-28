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
    if(n == 1) {
        cout << 1 << endl;
        return;
    }
    if(n & 1) {
        cout << -1 << endl;
        return;
    }

    cout << n << ' ';
    ll odd = n - 1;
    ll even = 2;
    for(int i = 0; i < n - 1; i++) {
        if(i & 1) {
            cout << even << ' ';
            even += 2;
        }
        else {
            cout << odd << ' ';
            odd -= 2;
        }
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

