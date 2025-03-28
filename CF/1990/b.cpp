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
    
    vector<ll> ans(n + 1, 0);
    bool alter = true;
    for(int i = a + 1; i <= n; i++) {
        if(alter) {
            ans[i] = -1;
            alter = false;
        }
        else {
            ans[i] = 1;
            alter = true;
        }
    }
    alter = true;
    for(int i = b - 1; i > 0; i--) {
        if(alter) {
            ans[i] = -1;
            alter = false;
        }
        else {
            ans[i] = 1;
            alter = true;
        }
    }

    for(int i = b; i <= a; i++) {
        ans[i] = 1;
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
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

