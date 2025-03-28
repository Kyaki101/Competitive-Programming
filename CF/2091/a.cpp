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


bool check(map<ll, ll> & mapa) {
    for(auto i : mapa) {
        if(i.second != 0) {
            return false;
        }
    }
    return true;
}

void solve(){        
    ll n;
    cin >> n;
    map<ll, ll> digits;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    digits[1] = 1;
    digits[0] = 3;
    digits[3] = 1;
    digits[2] = 2;
    digits[5] = 1;


    for(int i = 0; i < n; i++) {
        if(a[i] == 1 && digits[1] > 0) {
            digits[1] --;
        }
        if(a[i] == 0 && digits[0] > 0) {
            digits[0] --;
        }
        if(a[i] == 3 && digits[3] > 0) {
            digits[3] --;
        }
        if(a[i] == 2 && digits[2] > 0) {
            digits[2] --;
        }
        if(a[i] == 5 && digits[5] > 0) {
            digits[5] --;
        }

        if(check(digits)) {
            cout << i + 1 << endl;
            return;
        }

    }
    cout << 0 << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

