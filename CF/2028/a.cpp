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
    ll n, a, b;
    cin >> n >> a >> b;

    string s;
    cin >> s;
    ll x = 0, y = 0;
    ll j = 0;
    while(j < 1000) {

    
        for(int i = 0; i < n; i++) {
            if(x == a && b == y) {
                cout << "YES" << endl;
                return;
            }
            if(s[i] == 'N') {
                y ++;
            }
            if(s[i] == 'S') y --;
            if(s[i] == 'E') x++;
            if(s[i] == 'W') x--;

            if(x == a && b == y) {
                cout << "YES" << endl;
                return;
            }
        }
        j++;
    }
    cout << "NO" << endl;
    return;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

