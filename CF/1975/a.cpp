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
    ll mini = a[0];
    bool flag = false;
    for(int i = 1; i < n; i++) {
        if(a[i] < a[i - 1] && !flag) {
            if(a[i] > mini) {
                cout << "NO" << endl;
                return;
            }

            else {
                flag = true;
            }
        }
        else if(a[i] < a[i - 1] && flag) {
            cout << "NO" << endl;
            return;
        }
        if(a[i] > mini && flag) {
            cout << "NO" << endl;
            return;
        }

    }
    cout << "YES" << endl;
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

