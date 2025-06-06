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

    if(n == 4) {
        for(int i = n / 2; i > 0; i--) {
            cout << i << ' ';
        }
        for(int i = n; i > n / 2; i--) {
            cout << i << ' ';
        }
        cout << endl;
        return;
    }

    if(n % 2 == 0) {
        cout << -1 << endl;
        return;
    }

        ll high = n;
        ll low = 1;
        for(int i = 0; i < n; i++) {
            if(i & 1) {
                cout << low << ' ';
                low ++;
            }
            else {
                cout << high << ' ';
                high --;
            }
        }
        cout << endl;
        return;
    


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
