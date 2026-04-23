#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define F second
#define S first
#define PB push_back
#define ll long long
typedef vector<ll> vll;

const int MAX = 2e5+20, MOD = 1e9+7;

void solve(){        
    ll n;
    cin >> n;
    vll a(n);
    for(auto &i : a) cin >> i;
    if(n == 3) {
        cout << "YES" << endl;
        return;
    }

    vll b;
    for(int i = 0; i < n - 1; i++) {
        b.PB(gcd(a[i], a[i + 1]));
    }
    vector<bool> bruh(n - 1);
    for(int i = 1; i < n - 1; i++) {
        bruh[i] = b[i - 1] > b[i];

    }
    ll count = accumulate(ALL(bruh), 0LL);
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            ll saved = bruh[i + 1];
            if(saved == count) {
                cout << "YES" << endl;
                return;
            }
            continue;

        }
        if(i == n - 1) {
            ll saved = bruh[i - 1];
            if(saved == count) {
                cout << "YES" << endl;
                return;
            }
            continue;

        }
        ll saved = bruh[i] + bruh[i - 1];
        ll temp = gcd(a[i + 1], a[i - 1]);
        if(i < n - 2 && b[i + 1] < temp) {
            continue;
        }
        else {
            saved += bruh[i + 1];
        }
        if(i > 1 && temp < b[i - 2]) {
            continue;
        }
        if(saved == count) {
            cout << "YES" << endl;
            return;
        }
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

