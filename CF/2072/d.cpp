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

    ll total = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[j] > a[i]) {
                total ++;
            }
        }
    }
    ll mini = (1 << 30);
    ll l = 0;
    ll r = 0;

    for(int i = 0; i < n; i++) {
        ll bruh = total;
        for(int j = i; j < n; j++) {
            if(a[j] > a[i]) {
                bruh ++;
            }
            if(a[j] < a[i]) {
                bruh --;
            }
            if(bruh < mini) {
                mini = bruh;
                l = i + 1;
                r = j + 1;
            }

        }
    }
    cout << l << ' ' << r << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

